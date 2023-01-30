#include <iostream>
using namespace std;
// int length=1; 

class stackNode
{
public:
    int data;
    stackNode *next;
    
};

void traversal(stackNode *top)
{
    while (top != NULL)
    {
        cout << top->data << " ";
        top = top->next;
        // length++;
    }
    cout << endl;
}
int isEmpty(stackNode *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stackNode **top, int value)
{

    stackNode *p = new stackNode();
    p->data = value;
    p->next = *top;
    *top = p;
}

int pop(stackNode **top)
{
    if (isEmpty(*top))
    {
        cout << "\nstack is Empty " << endl;
        return 0;
    }
    else
    {
        stackNode *p = (*top);
        *top = (*top)->next;
        int x = p->data;
        free(p);
        return x;
    }
}

// not work
//  int peek(stackNode** top,int at){
//      int pos=5-at+1;
//      stackNode* p=*top;
//          int i=0;
//          while(i< pos-1){
//              p=p->next;
//          }
//          int x=p->data;
//          return x;

// }

int main()
{
    stackNode *top = NULL;
    push(&top, 45);
    push(&top, 25);
    push(&top, 56);
    push(&top, 12);
    push(&top, 76);

    traversal(top);

    //    cout<<"popped number is "<<pop(&top)<<endl;
    //    cout<<"popped number is "<<pop(&top)<<endl;
    int d;
    cout << "Enter position " << endl;
    cin >> d;
    //    cout<<" value at position "<<d<<" is "<<peek(&top,d)<<endl;
    //    traversal(top);

    return 0;
}