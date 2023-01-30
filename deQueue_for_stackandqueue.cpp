#include <iostream>
using namespace std;

class Deque
{
public:
    int data;
    Deque *next;
    Deque *prev;
    Deque *head;
    Deque *tail;

    Deque()
    {
        head = tail = NULL;
    }

    int isEmpty()
    {
        if (head == NULL)
            return 1;
        return 0;
    }

    int size()
    {

        if (!isEmpty())
        {
            Deque *temp = head;
            int len = 0;
            while (temp != NULL)
            {
                len++;
                temp = temp->next;
            }
            return len;
        }
        return 0;
    }

    void insert_first(int element)
    {

        Deque *temp = new Deque;
        temp->data= element;

        if (head == NULL)
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            head->prev = temp;
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
    }

    void insert_last(int element)
    {

        Deque *temp = new Deque;
        temp->data = element;

        if (head == NULL)
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            tail->next = temp;
            temp->next = NULL;
            temp->prev = tail;
            tail = temp;
        }
    }

    void remove_first()
    {
        Deque* temp= head;
        head=head->next;
        head->prev=NULL;
         free(temp);


    }

    void remove_last()
    {
        Deque* tmp= tail;
         tail=tail->prev;
         tail->next=NULL;
          free(tmp);
        
    }

    void display()
    {

        if (!isEmpty())
        {
            Deque *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
        cout << "List is Empty" << endl;
    }
};

class Stack : public Deque
{
public:
    void push(int element)
    {
        insert_last(element);
    }
    void pop()
    {
        remove_last();
    }
};

class Queue : public Deque
{
public:
    void enqueue(int element)
    {
        insert_last(element);
    }

    void dequeue()
    {
        remove_first();
    }
};

int main()
{

    Stack stk;

    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();

    stk.pop();
    cout << "Stack: ";
    stk.display();

    Queue que;

    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();

    que.dequeue();
    cout << "Queue: ";
    que.display();

    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << que.size() << endl;
    return 0;
}
