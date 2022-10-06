#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
class Node {
public:
    int data;
    Node* next;
};
 
// A utility function to return  intersection node
Node* intersectPoint(Node* head1, Node* head2)
{
    // Maintaining two pointers ptr1 and ptr2
    // at the head of A and B,
    Node* ptr1 = head1;
    Node* ptr2 = head2;
 
    // If any one of head is NULL i.e
    // no Intersection Point
    if (ptr1 == NULL || ptr2 == NULL)
        return NULL;
 
    // Traverse through the lists until they
    // reach Intersection node
    while (ptr1 != ptr2) {
 
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
 
        // If at any node ptr1 meets ptr2, then it is
        // intersection node.Return intersection node.
 
        if (ptr1 == ptr2)
            return ptr1;
        /* Once both of them go through reassigning,
        they will be equidistant from the collision point.*/
 
        // When ptr1 reaches the end of a list, then
        // reassign it to the head2.
        if (ptr1 == NULL)
            ptr1 = head2;
        // When ptr2 reaches the end of a list, then
        // redirect it to the head1.
        if (ptr2 == NULL)
            ptr2 = head1;
    }
    return ptr1;
}
 
// Function to print intersection nodes
// in  a given linked list
void print(Node* node)
{
    if (node == NULL)
        cout << "NULL";
    while (node->next != NULL) {
        cout << node->data << "->";
        node = node->next;
    }
    cout << node->data;
}
// Driver code
int main()
{
    /*
    Create two linked lists
 
    1st Linked list is 3->6->9->15->30
    2nd Linked list is 10->15->30
 
    15 30 are elements in the intersection list
    */
 
    Node* newNode;
    Node* head1 = new Node();
    head1->data = 10;
    Node* head2 = new Node();
    head2->data = 3;
    newNode = new Node();
    newNode->data = 6;
    head2->next = newNode;
    newNode = new Node();
    newNode->data = 9;
    head2->next->next = newNode;
    newNode = new Node();
    newNode->data = 15;
    head1->next = newNode;
    head2->next->next->next = newNode;
    newNode = new Node();
    newNode->data = 30;
    head1->next->next = newNode;
    head1->next->next->next = NULL;
    Node* intersect_node = NULL;
 
    // Find the intersection node of two linked lists
    intersect_node = intersectPoint(head1, head2);
    cout << "INTERSEPOINT LIST :";
    print(intersect_node);
    return 0;
}