class Solution {
public:
    bool f(TreeNode *r1, TreeNode *r2) {
        if (r1 == NULL || r2 == NULL)
            return r1 == r2;

        return r1->val == r2->val &&
               f(r1->left, r2->left) &&
               f(r1->right, r2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL)
            return false;

        if (f(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};