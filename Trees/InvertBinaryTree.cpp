class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        
        TreeNode* lt= root->left;
        TreeNode* rt= root->right;
        
        invertTree(root->left);
        invertTree(root->right);
        
        root->left= rt;
        root->right= lt;
        
        return root;
    }
};
