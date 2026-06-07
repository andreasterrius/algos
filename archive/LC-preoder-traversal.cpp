#include<vector>
#include<iostream>

using namespace std;

//  Definition for a binary tree node.
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
    vector<int> result;
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return result;
    }

    void dfs(TreeNode* node) {
        if(node == nullptr) 
          return;
        result.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
};

int main(){

  Solution S;

  // Create the input (equivalent to your scanf usually but just do it from code)
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  vector<int> yourAnswer = S.preorderTraversal(root);
  for(int i = 0; i < yourAnswer.size(); ++i){
    cout << yourAnswer[i] << " ";
  }

  return 0;
}
