/*EXPLANATION

Floyd’s Cycle-Finding Algorithm // fast slow approach // 2 pointers // "tortoise and the hare algorithm"

Approach: This is the fastest method and has been described below:

Traverse linked list using two pointers.

Move one pointer(slow_p) by one and another pointer(fast_p) by two.

If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.*/
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*next;
};
void push(node** head_ref, int new_data)
{
    /* allocate node */
    node* new_node = new node();
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 bool hasCycle(node *head) {
	
		// if head is NULL then return false;
        if(head == NULL)
            return false;
        
		// making two pointers fast and slow and assignning them to head
        node *fast = head;
        node *slow = head;
        
		// till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
			
			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }
        
		// if traversal reaches to NULL this means no cycle.
        return false;
    }
    /* Driver code*/
int main()
{
    /* Start with the empty list */
    node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
    if (hasCycle(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
}
//output will be loop found