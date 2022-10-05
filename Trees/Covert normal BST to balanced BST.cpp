#include<bits/stdc++.h>
using namespace std;
class node
{
    public:

    int data;
    node *left;
    node *right;
};
node* create(int x)
{
    node *new_node=new node();
    new_node->data=x;
    new_node->left=new_node->right=NULL;
    return new_node;

}
void fillVector(node *root,vector<node*>&v)

{
if(!root)
        return;
fillVector(root->left,v);
v.push_back(root);
fillVector(root->right,v);


}
node* buildBalancedBST(vector<node*>&v,int s,int e)
{
    if(s>e)
        return NULL;
    int mid=(s+e)/2;
    node *root=v[mid];

    root->left=buildBalancedBST(v,s,mid-1);
    root->right=buildBalancedBST(v,mid+1,e);
    return root;
}
node* balancedBST(node *root)
{
    vector<node*>v;
    int i=-1;
    fillVector(root,v);
    int n=v.size();
    root=buildBalancedBST(v,0,n-1);
    return root;
}
void preorder(node *root)
{
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);

    preorder(root->right);

}
int main()
{
    node *root=create(10);
    root->left=create(8);

    root->left->left=create(7);
    root->left->left->left=create(6);
    root->left->left->left->left=create(5);

    preorder(root);
    root=balancedBST(root);
    cout<<"\n";
    preorder(root);



}
