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
    vector<vector<int>> levelOrder(TreeNode* root) {
       queue<TreeNode *>q;
       vector<vector<int>> ans;
       if(!root) return ans;
       vector<int>temp;
       q.push(root);
       while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            auto it=q.front();
            if(it->left) q.push(it->left);
            if(it->right) q.push(it->right);
            q.pop();
            temp.push_back(it->val);
        }
        ans.push_back(temp);
        temp.clear();
       } 
       return ans;
    }
};
