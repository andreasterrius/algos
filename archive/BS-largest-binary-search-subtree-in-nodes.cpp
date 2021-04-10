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
BS - Largest Binary Search Subtree in Nodes
ACCEPTED

*/
class Tree {
    public:
        int val;
        Tree *left;
        Tree *right;

    Tree(int v) {
        this->val = v;
    }
};
 
class BST {
public:
    Tree* ans = nullptr;
    int maxNode = INT_MIN;
    pair<int, int>isBST(Tree* r, int depth, bool toLeft) {
        if (r == nullptr && toLeft) return { 0, INT_MIN };
        else if (r == nullptr && !toLeft) return { 0, INT_MAX };

        auto [lok, left] = isBST(r->left, depth + 1, true);
        auto [rok, right] = isBST(r->right, depth + 1, false);

        cout << "r: " << r->val << " lok+rok+1: " << lok + rok + 1 << " l|r:" << left << "|" << right << endl;
        if (lok == -1 || rok == -1) return { -1, r->val };

        if (r->val < right && r->val > left) {
            if (lok + rok > maxNode) {
                maxNode = lok + rok;
                ans = r;
            }
            if (toLeft) {
                if (right == INT_MAX) right = r->val;
                return { lok + rok + 1, right };
            }
            else {
                if (left == INT_MIN) left = r->val;
                return { lok + rok + 1, left };
            }
        }

        else return { -1, r->val };
    }
};

Tree* solve(Tree* root) {
    if (root == nullptr) return nullptr;
    BST b;
    b.isBST(root, 0, true);
    return b.ans;
}

int main() {

    //int t;
    //cin >> t;
    //for (int i = 0; i < t; ++i) {
    //    solve(i + 1);
    //}

    //Tree* root = new Tree(1);
    //root->left = new Tree(3);
    //root->left->right = new Tree(5);
    //root->left->left = new Tree(2);
    //root->right = new Tree(5);
    //root->right->left = new Tree(3);
    //root->right->right = new Tree(7);
    //root->right->right->left = new Tree(6);
    //root->right->left->left = new Tree(2);
    //root->right->left->right = new Tree(4);

    Tree* root = new Tree(5);
    root->left = new Tree(3);
    root->left->left = new Tree(2);
    root->left->right = new Tree(4);

    root->right = new Tree(7);
    root->right->left = new Tree(6);
    root->right->right = new Tree(10);
    root->right->right->left = new Tree(9);
    root->right->right->right = new Tree(11);

    //Tree* root = new Tree(1);
    //root->left = new Tree(3);
    //root->left->left = new Tree(2);
    //root->left->right = new Tree(5);

    cout << solve(root)->val;

    return 0;
}