/*
 *Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //there is a posibility that both of them are not on same level
        //and the one in upper level is ancestor of itself and the other node which is one amongst its children

        if(root==p or root==q)return root;//if anyone found first then its the one at higher level marked as LCA

        if(!root)return NULL;//while recursion if reached leaf nodes and didn't find anyone out of two nodes in the path then return null

        //left tree search-brings the LCA if found else null
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        //right tree search-brings the LCA if found else null
        TreeNode*right=lowestCommonAncestor(root->right,p,q);

        //case where one amongst left or right is null and other is not null ---or both are null
        if(!left)return right;//if left is null then --right may bring the LCA or null
        if(!right)return left;//if right is null then --left may bring the LCA or null

        //if both are not null then it means both are found in left and right subtree..so root is the LCA
        return root;
    }
};