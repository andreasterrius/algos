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
LC - Flatten Binary Tree to Linked List (Accepted)

        1
    2       3

        1
      2   4
     3 x 6 7
    x x x x x x
      
    
 */


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

    TreeNode* traverse(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* lt = traverse(root->left);
        TreeNode* r = root->right;
        
        root->right = lt;
        root->left = nullptr;
        TreeNode* curr = root;
        while (curr->right != nullptr) {
            curr = curr->right;
        }
        curr->right = r;
        traverse(r);

        return root;
    }

    void flatten(TreeNode* root) {
        traverse(root);
    }
};


int main() {
    //int t = 1;
    //cin >> t;

    //for (int i = 0; i < t; ++i) {
    //   solve(i + 1);
    //}

    TreeNode* t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->left->left = new TreeNode(3);
    //t->left->right = new TreeNode(4);
    t->right = new TreeNode(5);
    t->right->left = new TreeNode(6);
    t->right->right = new TreeNode(7);

    Solution S;
    S.traverse(t);

    while (t != nullptr) {
        cout << t->val << " ";
        t = t->right;
    }

    return 0;
}
