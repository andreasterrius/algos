#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

typedef long long ll;
#define debuglist(x) for(int _i = 0; _i < x.size(); ++_i) { cout << x[_i] << " "; } cout << "\n";
#define MODL 1000000007

/*
    Flip Binary Tree To Match Preorder Traversal
    ACCEPTED
*/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
#define ABORT 0
#define OK 1
#define FLIP 2
public:
    void flip(TreeNode* n) {
        TreeNode* k = n->left;
        n->left = n->right;
        n->right = k;
    }

    int traverse(TreeNode* n, vector<int>& ans, vector<int>& voyage, int& curr) {
        if (n == nullptr) return OK;
        if (n->val != voyage[curr]) {
            return FLIP;
        }
        curr += 1;

        int l = traverse(n->left, ans, voyage, curr);
        if (l == FLIP) {
            flip(n);
            l = traverse(n->left, ans, voyage, curr);
            if (l == FLIP) {
                return ABORT;
            }
            else {
                ans.push_back(n->val);
            }
        }
        if (l == ABORT) {
            return ABORT;
        }

        int r = traverse(n->right, ans, voyage, curr);
        if (r == FLIP) {
            flip(n);
            r = traverse(n->right, ans, voyage, curr);
            if (r == FLIP) {
                return ABORT;
            }
            else {
                ans.push_back(n->val);
            }
        }
        if (r == ABORT) {
            return ABORT;
        }

        return OK;
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        int c = 0;
        int back = traverse(root, ans, voyage, c);
        if (back == OK && c == voyage.size()) {
            return ans;
        }
        else {
            return { -1 };
        }
    }
};



int main() {

    /*   int t, p;
       cin >> t >> p;
       for (int i = 0; i < t; ++i) {
           solve(i+1);
       }*/

       /*  vector<int> d{ 1,1,3,3,4 };
         cout << solve(d, 1);*/

    Solution s;
    TreeNode* n = new TreeNode(1);
    n->left = new TreeNode(2);
    n->left->left = new TreeNode(3);
    n->left->right = new TreeNode(4);

    n->right = new TreeNode(5);
    n->right->left = new TreeNode(6);
    n->right->right = new TreeNode(7);

    //vector<int> v{ 1,3,2 };
    vector<int> v{ 1,2,3,4,5,6,7};

    auto k = s.flipMatchVoyage(n, v);
    debuglist(k);

    return 0;
}