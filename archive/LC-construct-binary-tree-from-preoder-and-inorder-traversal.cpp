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
 LC - construct binary tree from preoder and inorder traversal (accepted)
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &inorderlkp, int ileft, int iright, int& rootIdx) {
        if( rootIdx >= preorder.size())
            return nullptr;

        if (ileft > iright)
            return nullptr;

        int val = preorder[rootIdx];
        int inorderRootIdx = inorderlkp[val];

        if (inorderRootIdx < ileft || inorderRootIdx > iright) {
            return nullptr;
        }

        rootIdx += 1;
        TreeNode* left = build(preorder, inorder, inorderlkp, ileft, inorderRootIdx - 1, rootIdx);
        TreeNode* right = build(preorder, inorder, inorderlkp, inorderRootIdx + 1, iright, rootIdx);

        TreeNode* curr = new TreeNode(val, left, right);
        return curr;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderlkp;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderlkp[inorder[i]] = i;
        }

        int rootIdx = 0;
        return build(preorder, inorder, inorderlkp, 0, preorder.size() - 1, rootIdx);
    }
};

int main() {
    //int t = 1;
    //cin >> t;

    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    vector<int> p{ 1,2,4,5,3,6,7 };
    vector<int> i{4,2,5,1,6,3,7 };

    Solution S;
    TreeNode *t = S.buildTree(p, i);
    
    


    return 0;
}
