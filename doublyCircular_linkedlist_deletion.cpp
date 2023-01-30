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

node* deletion_at_begin(node* head){
    node* last=head->prev;
    node* p=head;
    if(p==head){
        p=p->next;
    }
   
    free(head);
    head=p;
    p->prev=last;
    last->next=head;

    return head;
}

node* deletion_at_end(node* head){
    node* prev1=head;
    node* cur=head->next;

    while(cur->next!=head){
        prev1=prev1->next;
        cur=cur->next;
    }

    free(cur);
    prev1->next=head;
    head->prev=prev1;

    return head;
}

//NOt work 
node* deletion_at_between(node* head,int element){
        node* prev1;
        node*  cur=head;
       
        while (cur->data!=element)
        {
           prev1=cur;
           cur=cur->next;
        }
        free(cur);
        node* temp=cur->next;
        prev1->next=temp;
        // cur->next->prev=prev1;
        
    return head;
}
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
    
    cout<<"Before deletion "<<endl;
     traversal(head);
    cout<<"\nAfter deletion "<<endl;
    // head=deletion_at_begin(head);
    // head=deletion_at_end(head);
    head=deletion_at_between(head,25);
    traversal(head);

    
    return 0;
}