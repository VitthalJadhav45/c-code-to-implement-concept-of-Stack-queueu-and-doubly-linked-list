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
     node* p=head;
     cout<<"Traversal in forward direction "<<endl;
    while(p->next!=head){
         cout<<p->data<<" ";
         last=p;
        p=p->next;
     }
      cout<<p->data<<" ";

     cout<<"\nTraversal in backward direction "<<endl;
     p=last;
     cout<<last->next->data<<" ";
     while(p->prev!=last){
         cout<<p->data<<" ";
         p=p->prev;
     }
}

// node* insertion_at_begin(node** head,int element){
//     node* last;
//     last=(*head)->prev;

//     node* p= new node();
//     p->data=element;

//     p->next=*head;
//     p->prev=last;
//     last->next= (*head)->prev=p;
//    *head=p;

//   return *head;
// }

node* insertion_at_end(node* head,int element){
    node* last;
    last=head->prev;

    node* ptr= new node();
    ptr->data=element;

    ptr->next=head;
    head->prev=last;
    last->next=ptr;
    ptr->prev=last;

    return head;
}

// node* insertion_at_between(node* head,int element,int x){
//       node* p=head;
//       node* q=head->next;

//       node* ptr=new node();
//       ptr->data=element;
//       int i=1;
//       while(i<x){
//           p=p->next;
//           q=q->next;
//           i++;
//       }

//       ptr->next=q;  //manditory to maintain series q->q->ptr->ptr->p->p->ptr
//       q->prev=ptr;
//       ptr->prev=p;
//       p->next=ptr;

//       return head;
// }

int main(){
    node* head= new node();
    node* second= new node();
    node* third= new node();
    node* four= new node();

    head->data=5;
    head->next=second;
    head->prev=four;  

    second->data=15;
    second->next=third;
    second->prev=head;

    third->data=25;
    third->next=four;
    third->prev=second;

    four->data=35;
    four->next=head;
    four->prev=third;
    
    cout<<"Before insertion "<<endl;
     traversal(head);
    cout<<"\nAfter insertion "<<endl;
    // head=insertion_at_begin(&head,45);
    head=insertion_at_end(head,45);
    // head=insertion_at_between(head,45,2);
    // insertEnd(&head,45);
     traversal(head);

    return 0;
}