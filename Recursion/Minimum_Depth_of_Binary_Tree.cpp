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
   
    int minDepth(TreeNode* root) {
       if(root==NULL){
           return 0;
       }
         int l=0,r=0;
      if(root->left==NULL && root->right==NULL){
            return 1;
        }
       if((root->left!=NULL && root->right!=NULL) ||(root->left!=NULL && root->right==NULL)){
              l=l+minDepth(root->left)+1;
        }
        
        if((root->left!=NULL && root->right!=NULL) ||(root->left==NULL && root->right!=NULL)){
              r=r+minDepth(root->right)+1;
        }
      
       if(l==0){l=INT_MAX;}
         if(r==0){r=INT_MAX;}
        return min(l,r);
    }
};
