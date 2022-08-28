#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
                for(int _j = 0; _j < y; ++_j) \
                    cout << arr[_i][_j] << " "; \
                cout << "\n"; }
#define MODL 1000000007

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// o(n log k) time
// o(1) space + some for recursion


class Solution {
public:

    ListNode *mergeList(ListNode *a, ListNode *b) {
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        while (curr != nullptr) {
            if (a == nullptr) {
                curr->next = b;
                break;
            } else if (b == nullptr) {
                curr->next = a;
                break;
            } else if (a->val < b->val) {
                curr->next = a;
                a = a->next;
            } else {
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }

        return head->next;
    }

    ListNode *mergeSort(vector<ListNode *> &lists, int start, int end) {
        if (end <= start) {
            return lists[start];
        } else if (start == end - 1) {
            return mergeList(lists[start], lists[end]);
        }
        int mid = start + (end - start) / 2;
        ListNode *a = mergeSort(lists, start, mid);
        ListNode *b = mergeSort(lists, mid + 1, end);
        return mergeList(a, b);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;
        return mergeSort(lists, 0, lists.size() - 1);
    }
};

int main() {
    return 0;
}
