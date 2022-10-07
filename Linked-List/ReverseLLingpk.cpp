/*
Problem statement : Reverse Linkedlist in group of K and ignore last set if not equal to K.
Followup: Dont use count loop and do...do it in single traversal of

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode * reverse(ListNode *st,ListNode *end)
    {
        ListNode *prev=NULL,*t=st;
        while(t!=NULL&&t!=end)
        {
            ListNode * k=t->next;
            t->next=prev;
            prev=t;
            t=k;
        }
        return prev;
    }
    //return head of the new ll
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *fast=new ListNode();
        fast->next=head;
        ListNode *slow=fast,*ans=fast;
        fast=fast->next;
        int i=0;
        //cout<<slow->next->val<<" ";
        for(;i<k;i++){
            if(!fast)break;
            fast=fast->next;
            
        }
        cout<<i;
        if(i<k)return head;
        if(k==1)return head;
        
        while(fast!=NULL||i==k)
        {
            if(i==k)
            {
                ListNode * temp=slow->next;
                slow->next=reverse(slow->next,fast);
                cout<<slow->next->val;
                if(fast)
                    temp->next=fast;
                slow=temp;
                i=0;
            }
            i++;
            if(fast)fast=fast->next;
        }
        return ans->next;
        
    }
};