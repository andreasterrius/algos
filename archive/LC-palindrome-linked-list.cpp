#include <iostream>
#include <vector>
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

typedef long long ll;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
        for(int _j = 0; _j < y; ++_j) \
            cout << arr[_i][_j] << " "; \
        cout << "\n"; }
#define MODL 1000000007

/*
* ACCEPTED, find mid point, reverse then match
* LC - Is single linked list palindrome ?
*             
*/



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int s = 0;
        for (auto k = head; k != nullptr; k = k->next) {
            s += 1;
        }

        if (s == 0)
            return false;
        if (s == 1)
            return true;
        if (s == 2)
            return head->val == head->next->val;

        // reverse half the list
        ListNode* s1 = head;
        ListNode* s2 = head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < s / 2; ++i) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

            s1 = prev;
            s2 = curr;
        }

        if (s % 2 == 1) {
            s2 = s2->next;
        }

        while (s1 != nullptr && s2 != nullptr) {
            if (s1->val != s2->val) return false;
            s1 = s1->next;
            s2 = s2->next;
        }

        return true;
    }
};

int main() {

  /*  int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i+1);
    }*/ 

    Solution s;
    auto t = s.movesToStamp("bfe", "bbfefeefbbfebbfeeefe");
    debuglist(t);

    return 0;
}