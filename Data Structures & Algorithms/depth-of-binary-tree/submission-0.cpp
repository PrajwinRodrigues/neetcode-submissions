/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxd(TreeNode *root){
        if(root==NULL) return 0;
        int ld=maxd(root->left);
        int rd=maxd(root->right);
        return 1+max(ld,rd);
    }
    int maxDepth(TreeNode* root) {
     return maxd(root);   
    }
};
