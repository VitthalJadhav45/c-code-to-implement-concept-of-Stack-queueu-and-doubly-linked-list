#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void traversal(node **f)
{
    cout << "Printing the element " << endl;
    while (*f != NULL)
    {
        cout << (*f)->data << " ";
        *f = (*f)->next;
    }
}

void enQueue(node **f, node **r, int val)
{
    node *n = new node();
    if (*r == NULL)
    {
        *f=*r=n;
        cout << "This queue is Full" << endl;
    }
    else
    {
        n->data = val;
        n->next = NULL;
        cout << "Enqueued Element " << val << endl;
        if (*f == NULL)
        {
            *f = *r = n;
        }
        else
        {
            (*r)->next = n;
            *r = n;
        }
    }
}

int deQueue(node **f)
{
    int val = -1;
    node *ptr = *f;
    if (*f == NULL)
    {
        cout << "Queue is Empty " << endl;
    }
    else
    {
        val = ptr->data;
        *f = (*f)->next;
        free(ptr);
    }
    return val;
}

int main()
{
    node *f = NULL;
    node *r = NULL;

    traversal(&f);

    enQueue(&f, &r, 45);
    enQueue(&f, &r, 76);
    enQueue(&f, &r, 98);
    enQueue(&f, &r, 15);

    // traversal(&f); if use it and dequeuing element its shows empty because of f reaches to the end

    cout << "Dequeuing Element " << deQueue(&f) << endl;
    cout << "Dequeuing Element " << deQueue(&f) << endl;
    cout << "Dequeuing Element " << deQueue(&f) << endl;

    enQueue(&f, &r, 45);
    enQueue(&f, &r, 76);

    traversal(&f);

    return 0;
}