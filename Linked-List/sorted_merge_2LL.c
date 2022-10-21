#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *create(struct node *head,int i){
    struct node *ptr;
    ptr=(struct node *) malloc(sizeof(struct node));
    struct node *p;
    printf("Enter value[%d] of list:",i);
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        p=head;
        return(head);
    }
    else{
        p->next=ptr;
        p=ptr;
        return(head);
    }
}
struct node *merge(struct node * head1,struct node * head2){
    struct node* p1=head1;
    struct node *p2=head2;
    struct node *dummy;
    struct node *p3=dummy;
    while(p1!=NULL&&p2!=NULL){
        if(p1->data>p2->data){
            p3->next=p2;
            p2=p2->next;
        }
        else{
            p3->next=p1;
            p1=p1->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummy->next;
}
struct node *merge_rec(struct node * head1,struct node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    struct node *result;
    if(head1->data<head2->data){
        result=head1;
        result->next=merge_rec(head1->next,head2);
    }
    else{
        result=head2;
        result->next=merge_rec(head1,head2->next);
    }
    return result;
}
void print(struct node *ptr){
    int i=1;
    while(ptr!=NULL){
        printf("Value at Node[%d]:%d\n",i,ptr->data);
        i++;
        ptr=ptr->next;
    }
}
int main(){
    int i,n,data,pos;
    struct node *head1=NULL;
    struct node *head2=NULL;
    printf("Enter size of linked list1:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head1=create(head1,i+1);
    }
    print(head1);

    printf("Enter size of linked list2:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head2=create(head2,i+1);
    }
    print(head2);
    printf("After merge two linked list:\n");
    struct node *head=merge(head1,head2);
    print(head);

    /*printf("After merge two linked list by recursion:\n");
    struct node *head_rec=merge_rec(head1,head2);
    print(head_rec);*/
    return 0;
}