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
    int f(vector<int> &ino,int l,int r,int s){
        for(int i=l;i<=r;i++){
            if(ino[i]==s) return i;
        }
        return -1;
    }
    TreeNode *build(vector<int> &pre,vector<int> &ino,int &idx,int l,int r){
        if(idx==pre.size() || l>r) return NULL;
        int elem=pre[idx];
        int eidx=f(ino,l,r,elem);
        TreeNode *p=new TreeNode(elem);
        idx+=1;
        p->left=build(pre,ino,idx,l,eidx-1);
        p->right=build(pre,ino,idx,eidx+1,r);
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root=NULL;
        int idx=0;
        root=build(preorder,inorder,idx,0,preorder.size()-1);
        return root;
    }
};
