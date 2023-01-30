#include<iostream>
using namespace std;


 class Node{
      public:
      int data;
      Node* pre;
      Node* next;
 };

 void transversal(Node* head){
     Node* ptr=head;
       
     cout<<"From left to right "<<endl;
     while(ptr->next!=head){
         cout<<ptr->data<<" ";
         ptr=ptr->next;
     }
    
     cout<<ptr->data<<endl;

     cout<<"From right to left "<<endl;
     while(ptr->pre!=head){
         cout<<ptr->pre<<" ";
         ptr=ptr->pre;
     }
     
 }
int main(){
    Node* head=new Node();
    Node* second=new Node();
    Node* third=new Node();
    Node* four=new Node();

    head->data=10;
    head->pre=NULL;
    head->next=second;

    second->data=11;
    second->pre=head;
    second->next=third;

    third->data=12;
    four->pre=second;
    third->next=four;

    four->data=14;
    third->pre=third;
    four->next=head;

    transversal(head);

    return 0;
}