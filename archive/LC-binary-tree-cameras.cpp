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
LC - binary tree cameras

        C
      A 
    C   
  C  A
A  
*/

//   1
// 2 
//   3
// 5
//   6
// 7

//   3
// 5
//   6
// 7

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
    int res = 0;
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1 ? 1 : 0) + res;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) return 2;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
};

int main() {
    //int t = 1;
    //cin >> t;

    //for (int i = 0; i < t; ++i) {
    //   solve(i + 1);
    //}

    //TreeNode* r = new TreeNode(1);
    //r->left = new TreeNode(2);
    //r->left->right = new TreeNode(3);
    //r->left->right->left = new TreeNode(4);
    //r->left->right->left->right = new TreeNode(5);
    //r->left->right->left->right->left = new TreeNode(6);

    //TreeNode* r = new TreeNode(1);
    //r->left = new TreeNode(2);
    //r->left->right = new TreeNode(4);
    //r->left->right->right = new TreeNode(6);
    //r->right = new TreeNode(3);
    //r->right->left = new TreeNode(5);

    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->left->left = new TreeNode(3);
    r->left->left->left = new TreeNode(4);
    r->left->left->left->left = new TreeNode(5);
    r->left->left->left->left->left = new TreeNode(6);

    /*
            1
           2
          3
         4
        5
       6
    */
    
    //TreeNode* r = new TreeNode(1);
    //r->left = new TreeNode(2);
    //r->left->right = new TreeNode(3);
    //r->left->left = new TreeNode(4);

    //TreeNode* r = new TreeNode(1);
    //r->left = new TreeNode(2);
    //r->right = new TreeNode(3);
    //r->left->left = new TreeNode(4);
    //r->left->right = new TreeNode(5);

    //r->left->left->left = new TreeNode(6);
    //r->left->right->right = new TreeNode(7);

    //r->left->left->left->right = new TreeNode(8);
    //r->left->left->left->right->right = new TreeNode(9);

    //   1
    // 2 
    //   3
    // 5
    //   6
    // 7

    //       0
    //     0
    //   0
    // 0

    //cin >> t;
    Solution S;
    cout << S.minCameraCover(r);
    

    return 0;
}
