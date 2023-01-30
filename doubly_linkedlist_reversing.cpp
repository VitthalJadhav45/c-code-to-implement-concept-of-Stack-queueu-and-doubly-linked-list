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

node* reversing(node* head){
    node* left=head;
    node* right=head;
    while(right->next!=NULL){
        right=right->next;
    }

    if(left!=right){
        swap(left->data,right->data);

        left=left->next;
        right=right->prev;

    }

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
    
    cout<<"Before reversing "<<endl;
    traversal(head);
    cout<<"\nAfter reversing "<<endl;
    // head=deletion(head,head);
    head=reversing(head);
    traversal(head);

    
    return 0;
}