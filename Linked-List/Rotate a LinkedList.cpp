#include<iostream>
using namespace std; 

class node
{
public: 
int data;
node* next;
node(int val)
{
data=val;
next=NULL;
}
};

void insert(node* &head,int val)
{
node* n=new node(val);
if(head==NULL)
{
head=n;
return;
}
node* temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=n;
}
void display (node* head)
{
node* temp=head;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}

node* rotate(node* &head,int k)
{
if(head==NULL || k==0 || head->next==NULL)
{
return head;
}
node* temp=head;
node* back=head;
int size=1;
while(temp->next!=NULL )
{
size++;
temp=temp->next;
}
temp->next=head; 
k=k%size;
k=size-k-1;
while(k--)
{
back=back->next;
}
head=back->next;
back->next=NULL;
return head;
}


int main()
{
node* head1=NULL;
insert(head1,1);
insert(head1,3);
insert(head1,4);
insert (head1,5);
insert (head1,6);

display(head1);
cout<<endl;
display(rotate(head1,2));
cout<<endl; 

}
