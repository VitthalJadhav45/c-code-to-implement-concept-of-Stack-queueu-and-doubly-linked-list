#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
};

 void traversal(node* head){
     node* last;
     cout<<"Traversal in forward direction "<<endl;
     while(head!=NULL){
         cout<<head->data<<" ";
         last=head;
         head=head->next;
     }

     cout<<"\nTraversal in backward direction "<<endl;
     while(last!=NULL){
         cout<<last->data<<" ";
         last=last->prev;
     }
}

node* insertion_at_begin(node** head,int element){
        node* p= new node();
        p->data=element;
        p->next=*head;
        p->prev=NULL;
        (*head)->prev=p;

        *head=p;

        return *head;
}
node* insertion_at_end(node* head,int element){
    node* p=head;
    node* ptr= new node();
    ptr->data=element;

    while(p->next!=NULL){
         p=p->next;
    }
    p->next=ptr;
    ptr->prev=p;
    ptr->next=NULL;

    return head;
}

node* insertion_at_given(node* head,int element,int at_data){
    node* p=head;
    node* q=head->next;
    node* ptr=new node();
    ptr->data=element;
    while (q->data!=at_data)
    {
        p=p->next;
        q=q->next;
    }
    ptr->next=q;
    q->prev=ptr;
    ptr->prev=p;
    p->next=ptr;

    return head;
}

int main(){
    node* head= new node();
    node* second= new node();
    node* third= new node();
    node* four= new node();

    head->data=5;
    head->next=second;
    head->prev=NULL;  

    second->data=15;
    second->next=third;
    second->prev=head;

    third->data=25;
    third->next=four;
    third->prev=second;

    four->data=35;
    four->next=NULL;
    four->prev=third;
    
    cout<<"Before insertion "<<endl;
    traversal(head);
    cout<<"\nAfter insertion "<<endl;
    // head=insertion_at_begin(&head,45);
    // head=insertion_at_end(head,45);
    head=insertion_at_given(head,45,15);
    traversal(head);

    return 0;
}