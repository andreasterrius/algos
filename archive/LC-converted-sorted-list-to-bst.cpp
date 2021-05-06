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

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define debugarr(arr, x, y) for(int _i = 0; _i < x; ++_i) { \
                for(int _j = 0; _j < y; ++_j) \
                    cout << arr[_i][_j] << " "; \
                cout << "\n"; }
#define MODL 1000000007

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/*
    LC - Convert Sorted List to Binary Search Tree, Accepted
*/

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
 
   //Definition for a binary tree node.
   struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };
  
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        //if nulls
        if (head == nullptr) return nullptr;

        //1
        if (head->next == nullptr) {
            return new TreeNode(head->val);
        }

        //2 
        if (head->next->next == nullptr) {
            TreeNode* top = new TreeNode(head->next->val);
            TreeNode* left = new TreeNode(head->val);
            top->left = left;
            return top;
        }

        //3
        if (head->next->next->next == nullptr) {
            TreeNode* top = new TreeNode(head->next->val);
            TreeNode* left = new TreeNode(head->val);
            TreeNode* right = new TreeNode(head->next->next->val);
            top->left = left;
            top->right = right;
            return top;
        }

        // more than 3, then find middle and split
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast == nullptr) {
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* ne = slow;
        slow = slow->next;
        ne->next = nullptr;

        TreeNode* top = new TreeNode(slow->val);
        TreeNode* left = sortedListToBST(head);
        TreeNode* right = sortedListToBST(slow->next);
        top->left = left;
        top->right = right;

        return top;
    }
};

void solve(int cas);

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
       solve(i + 1);
    }
    
    
    return 0;
}
