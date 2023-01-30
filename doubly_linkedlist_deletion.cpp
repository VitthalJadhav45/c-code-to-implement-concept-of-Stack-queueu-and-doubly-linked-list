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

// node* deletion(node* head,node* p){

//     if(head==NULL || p==NULL)
//       return NULL;
    
//     if(p==head){
//         head=p->next;
//     }
//     if(p->next!=NULL){
//         p->next->prev=p->prev;
//     }
//     if(p->prev!=NULL){
//         p->prev->next=p->next;
//     }

//     free(p);

//     return head;
// }
node* deletion_at_given(node* head,int x){
    node* p=head;
    int i=1;
    while (i<x)
    {
        p=p->next;
        i++;
    }
    

    if(head==NULL || p==NULL)
      return NULL;
    
    if(p==head){
        head=p->next;
    }
    if(p->next!=NULL){
        p->next->prev=p->prev;
    }
    if(p->prev!=NULL){
        p->prev->next=p->next;
    }

    free(p);

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
    
    cout<<"Before deletionn "<<endl;
    traversal(head);
    cout<<"\nAfter deletionn "<<endl;
    // head=deletion(head,head);
    head=deletion_at_given(head,4);
    traversal(head);

    return 0;
}