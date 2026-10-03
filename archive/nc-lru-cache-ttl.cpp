#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull, ull> pull;
#define debuglist(x)                                                           \
  for (int _i = 0; _i < x.size(); ++_i) {                                      \
    cout << x[_i] << " ";                                                      \
  }                                                                            \
  cout << "\n";
#define debugarr(arr, x, y)                                                    \
  for (int _i = 0; _i < x; ++_i) {                                             \
    for (int _j = 0; _j < y; ++_j)                                             \
      cout << arr[_i][_j] << " ";                                              \
    cout << "\n";                                                              \
  }
#define MODL 1000000007

// NC 150, LRUCache, Accepted.
// I add some code to handle TTL here just for fun
// How to make it concurrent? mutex on get and put.
// Maybe can copy spring ConcurrentLruCache, but maybe later
class LRUCache {
  struct Node {
    int key, value, ttl;
    Node *prev, *next;
  };

  Node *head;
  Node *tail;

  unordered_map<int, Node *> lru;
  priority_queue<pair<int, int>> pq;
  int capacity;

public:
  LRUCache(int capacity) : head(nullptr), tail(nullptr), capacity(capacity) {
    head = new Node();
    tail = new Node();
    head->prev = nullptr;
    head->next = tail;
    tail->next = nullptr;
    tail->prev = head;
  }

  void unplug(Node *curr) {
    Node *before = curr->prev;
    Node *after = curr->next;

    curr->prev = nullptr;
    curr->next = nullptr;
    before->next = after;
    after->prev = before;
  }

  void put_front(Node *curr) {
    // [head] [curr] [after]
    Node *after = head->next;
    after->prev = curr;
    head->next = curr;
    curr->prev = head;
    curr->next = after;
  }

  void evict_and_delete(Node *curr) {
    lru.erase(curr->key);
    unplug(curr);
    delete curr;
  }

  void evict_ttl() {
    // we get current time epoch
    auto now = std::time(nullptr);
    while (!pq.empty()) {
      auto curr_key = pq.top();
      Node *n = lru[curr_key.second];

      if (n->ttl != -curr_key.first) {
        pq.pop(); // outdated ttl, just pop and continue
        continue;
      }

      if (n->ttl < now) {
        evict_and_delete(n);
        pq.pop();
      } else {
        break;
      }
    }
  }

  int get(int key) {

    evict_ttl();
    if (lru.find(key) == lru.end()) {
      return -1;
    }

    // if found
    Node *n = lru[key];
    unplug(n);
    put_front(n);
    return n->value;
  }

  void put(int key, int value, int ttl /*unix epoch*/) {

    evict_ttl();

    if (lru.find(key) == lru.end()) {
      Node *n = new Node();
      n->key = key;
      n->value = value;
      n->ttl = ttl;
      put_front(n);
      lru[key] = n;

      pq.push(make_pair(-ttl, key));
    } else {
      // node exist
      Node *curr = lru[key];
      curr->value = value;
      curr->ttl = ttl;
      unplug(curr);
      put_front(curr);

      pq.push(make_pair(-ttl, key));
    }

    if (lru.size() > capacity) {
      Node *curr = tail->prev;
      evict_and_delete(curr);
    }
  }
};

void tc();

int main() {
  int n;
  cin >> n;
  while (n--) {
    tc();
  }
  return 0;
}
