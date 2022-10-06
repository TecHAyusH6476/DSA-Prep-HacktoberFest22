// 1. Using Hashing

// The idea is to traverse the first list and store each node’s address in a hash table. Then traverse the second list and get the address of the first node present in the hash table. This node would be the intersection point. Following is the C++, Java, and Python implementation based on the idea:


#include <iostream>
#include <unordered_set>
using namespace std;
 
// A Linked List Node

struct Node
{
    int data;
    Node* next;
};
 
// Utility function to create a new node with the given data and
// pushes it onto the list's front
void push(Node*& headRef, int data)
{
    // create a new linked list node from the heap
    Node* newNode = new Node;
 
    newNode->data = data;
    newNode->next = headRef;
    headRef = newNode;
}
 
// Function to find the intersection point of two linked lists using hashing
Node* findIntersection(Node* first, Node* second)
{
    // maintain a set to store list nodes
    unordered_set<Node*> nodes;
 
    // traverse the first list and insert the address of each node into the set
    while (first)
    {
        nodes.insert(first);
        first = first->next;
    }
 
    // now traverse the second list and find the first node that is
    // already present in the set
    while (second)
    {
        // return the current node if it is found in the set
        if (nodes.find(second) != nodes.end()) {
            return second;
        }
        second = second->next;
    }
 
    // we reach here if lists do not intersect
    return nullptr;
}
 
int main()
{
    // construct the first linked list (1 —> 2 —> 3 —> 4 —> 5 —> null)
    Node* first = nullptr;
    for (int i = 5; i > 0; i--) {
        push(first, i);
    }
 
    // construct the second linked list (1 —> 2 —> 3 —> null)
    Node* second = nullptr;
    for (int i = 3; i > 0; i--) {
        push(second, i);
    }
 
    // link tail of the second list to the fourth node of the first list
    second->next->next->next = first->next->next->next;
 
    Node* addr = findIntersection(first, second);
    if (addr) {
        cout << "The intersection point is " << addr->data << endl;
    }
    else {
        cout << "The lists do not intersect." << endl;
    }
 
    return 0;
}
