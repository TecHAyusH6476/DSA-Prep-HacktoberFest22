// 2. Using Floyd’s Cycle Detection Algorithm

// Another approach is to make the first linked list circular by linking its tail to the head. Then the problem reduces to finding a loop in the second linked list.
// The idea is to get a pointer to the loop node using Floyd’s cycle detection algorithm and count the total number of nodes in the loop using that loop node, say k. Then take two pointers – one pointing to the head node and another pointing to the k'th node from the head. If we simultaneously move these pointers at the same speed, they will eventually meet at the loop’s starting node.



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
 
// Find the starting node of the loop in a linked list pointed by `head`.
// The `loopNode` points to one of the nodes involved in the cycle
Node* removeCycle(Node* loopNode, Node* head)
{
    // find the count of nodes involved in the loop and store the count in `k`
    int k = 1;
    for (Node* ptr = loopNode; ptr->next != loopNode; ptr = ptr->next) {
        k++;
    }
 
    // get pointer to k'th node from the head
    Node* curr = head;
    for (int i = 0; i < k; i++) {
        curr = curr->next;
    }
 
    // simultaneously move the `head` and `curr` pointers
    // at the same speed until they meet
    while (curr != head)
    {
        curr = curr->next;
        head = head->next;
    }
 
    // `curr` now points to the starting node of the loop
    return curr;
}
 
// Function to identify a cycle in a linked list using
// Floyd’s cycle detection algorithm
Node* identifyCycle(Node* head)
{
    // take two pointers – `slow` and `fast`
    Node *slow = head, *fast = head;
 
    while (fast && fast->next)
    {
        // move slow by one pointer
        slow = slow->next;
 
        // move fast by two pointers
        fast = fast->next->next;
 
        // if they meet any node, the linked list contains a cycle
        if (slow == fast) {
            return slow;
        }
    }
 
    // return null if the linked list does not contain a cycle
    return nullptr;
}
 
// Function to find the intersection point of two linked lists
Node* findIntersection(Node* first, Node* second)
{
    Node* prev = nullptr;       // previous pointer
    Node* curr = first;         // main pointer
 
    // traverse the first list
    while (curr)
    {
        // update the previous pointer to the current node and
        // move the main pointer to the next node
        prev = curr;
        curr = curr->next;
    }
 
    // create a cycle in the first list
    if (prev) {
        prev->next = first;
    }
 
    // now get a pointer to the loop node using the second list
    Node* slow = identifyCycle(second);
 
    // find the intersection node
    Node* addr = nullptr;
    if (slow) {
        addr = removeCycle(slow, second);
    }
 
    // remove cycle in the first list before exiting
    if (prev) {
        prev->next = nullptr;
    }
 
    // return the intersection node
    return addr;
}
 
int main()
{
    // construct the first linked list (1 —> 2 —> 3 —> 4 —> 5 —> null)
    Node* first = nullptr;
    for (int i = 7; i > 0; i--) {
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