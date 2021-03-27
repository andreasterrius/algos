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
#define debuglist(x) for(int i = 0; i < x.size(); ++i) { cout << x[i] << " "; } cout << endl;
#define MODL 1000000007

/*
* ACCEPTED
Construct Binary Tree from String

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
    TreeNode* str2tree(string s) {
        if (s == "") return nullptr;

        string num = "";
        int numNode = 0;
        bool numNodeDone = false;

        int level = 0;
        string child = "";
        vector<string> chs;
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 && s[0] == '(' && s.back() == ')') continue;
            if (i == s.size()-1 && s[0] == '(' && s.back() == ')') continue;
            if (!numNodeDone) {
                num += s[i];
            }
            else {
                child += s[i];
            }

            if (s[i] == '(') {
                if (!numNodeDone) {
                    num.pop_back();
                    child += '(';
                    numNode = stoi(num, nullptr, 10);
                }
                numNodeDone = true;
                level++;
            }
            else if (s[i] == ')') {
                level--;
                if (level == 0) {
                    chs.push_back(child);
                    child = "";
                }
            }
        }

        TreeNode* curr = new TreeNode(numNode);
        if (chs.size() >= 1)
            curr->left = str2tree(chs[0]);
        if (chs.size() >= 2)
            curr->right = str2tree(chs[1]);
        else {
            curr->val = stoi(num, nullptr, 10);
        }

        return curr;
    }
};


int main() {

    
    //int cas;
    //cin >> cas;
    //int l = cas;
    //int a = 1;
    //while (cas--) {
    //    solve(l, a);
    //    a += 1;
    //}

    //solve(0);

    Solution s;
    TreeNode *k = s.str2tree("-4(2(3)(1))(6(5)(7))");
  
    return 0;
}