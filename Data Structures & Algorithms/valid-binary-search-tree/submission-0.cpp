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
    void inorder(TreeNode *root,vector<int> &ino){
        if(root!=NULL){
            inorder(root->left,ino);
            ino.push_back(root->val);
            inorder(root->right,ino);
        }
    }
    bool isValidBST(TreeNode* root) {
     vector<int>ino;  
     inorder(root,ino);
     for(int i=0;i<ino.size()-1;i++){
        if(ino[i+1] <= ino[i]){
            return false;
        }
     } 
     return true;
    }
};
