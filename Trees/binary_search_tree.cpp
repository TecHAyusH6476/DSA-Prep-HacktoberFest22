#include&lt;iostream&gt; 
using namespace std;
struct bstnode 
{ 
int data; 
struct bstnode *left, *right; 
}; 
struct bstnode *newNode(int key) 
{ 
struct bstnode *temp =  new struct bstnode(); 
temp-&gt;data = key; 
temp-&gt;left = temp-&gt;right = NULL; 
return temp; 
} 
void inorder(struct bstnode *root) 
{ 
if (root != NULL) 
    { 
inorder(root-&gt;left); 
cout&lt;&lt;root-&gt;data&lt;&lt;" "; 
inorder(root-&gt;right); 
    } 
} 
struct bstnode* insert(struct bstnode* node, int key) 
{ 
if (node == NULL) return newNode(key); 
if (key &lt; node-&gt;data) 
node-&gt;left  = insert(node-&gt;left, key); 
else
node-&gt;right = insert(node-&gt;right, key); 
return node; 
} 
struct bstnode * minValueNode(struct bstnode* node) 
{ 
struct bstnode* current = node;
while (current &amp;&amp; current-&gt;left != NULL) 
current = current-&gt;left; 
   
return current; 
} 
struct bstnode* deleteNode(struct bstnode* root, int key) 
{ 
if (root == NULL) return root; 
if (key &lt; root-&gt;data) 
root-&gt;left = deleteNode(root-&gt;left, key); 
else if (key &gt; root-&gt;data) 
root-&gt;right = deleteNode(root-&gt;right, key); 
else
    { 
if (root-&gt;left == NULL) 
        { 
struct bstnode *temp = root-&gt;right; 
free(root); 
return temp; 
        } 
else if (root-&gt;right == NULL) 
        { 
struct bstnode *temp = root-&gt;left; 
free(root); 
return temp; 
        } 
struct bstnode* temp = minValueNode(root-&gt;right); 
root-&gt;data = temp-&gt;data; 
root-&gt;right = deleteNode(root-&gt;right, temp-&gt;data); 
    } 
    return root; 
}   
int main() 
{ 
struct bstnode *root = NULL; 
root = insert(root, 40); 
root = insert(root, 30); 
root = insert(root, 60); 
root = insert(root, 65); 
root = insert(root, 70); 
 
cout&lt;&lt;"Binary Search Tree created (Inorder traversal):"&lt;&lt;endl; 
inorder(root); 
   
cout&lt;&lt;"\nDelete node 40\n"; 
root = deleteNode(root, 40); 
cout&lt;&lt;"Inorder traversal for the modified Binary Search Tree:"&lt;&lt;endl; 
inorder(root); 
   
return 0; 
}
