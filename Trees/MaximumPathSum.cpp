//A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.
#include "bits/stdc++.h"
using namespace std ;

struct Node
{
    int data;
    Node* right ;
    Node* left ;
    Node(int val){
        data = val ;
        right = NULL;
        left = NULL ;
    }
};
int maxPathSumUtil(Node* root, int &ans){
        if(root == NULL){
           
            return 0 ;
        }
        int left = maxPathSumUtil(root->left,ans);
        int right = maxPathSumUtil(root->right,ans);
        int nodemax = max(max(root->data ,root->data + left + right),
                          max(root->data + left,root->data+right));
        ans = max(ans,nodemax);
        int singlepathsum = max(root->data,max(root->data + left ,root->data + right));
            return singlepathsum;
    }
int maxPathSum(Node* root) {
        
        int ans = INT_MIN;
        maxPathSumUtil(root,ans);
        return ans ;
    }


int main(){
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    cout<<maxPathSum(root);
    return 0 ;
   
}