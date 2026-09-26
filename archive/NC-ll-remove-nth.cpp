/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Very trivial, except maybe prev == nullptr, return head->next

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *now = head;
    ListNode *scout = now;
    for (int i = 0; i < n; ++i) {
      scout = scout->next;
    }

    ListNode *prev = nullptr;
    while (scout != nullptr) {
      scout = scout->next;
      prev = now;
      now = now->next;
    }

    if (prev == nullptr)
      return head->next;
    else {
      prev->next = now->next;
    }

    return head;
  }
};

// [1,2]
