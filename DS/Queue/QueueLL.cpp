// Tawfik Yasser
#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node() {}
};
class QueueLL
{
private:
    Node *front;
    Node *rear;
    int _length;
public:

    //Constructor to initialize a LinkedList
    QueueLL()
    {
        front = rear = NULL;
    }
    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if(front == NULL && rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue()
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    void peek()
    {
        cout<<front->data<<endl;
    }
    void print()
    {
        if(front == NULL && rear == NULL)
        {
            cout<<"Empty Queue"<<endl;
        }
        else
        {
            Node *temp = front;
            while(temp != NULL)
            {
                cout<<"[ "<<temp->data<<" ] ";
                temp = temp->next;
            }
        }
    }
    void calcSize()
    {

        if(front == NULL && rear == NULL)
        {
            _length = 0;
        }
        else
        {
            int _count;
            Node *temp = front;
            while(temp!= NULL)
            {
                temp = temp->next;
                _count++;
            }
            _length = _count;
        }
    }
    int _size()
    {
        calcSize();
        return _length;
    }
};
int main()
{
    QueueLL qll;
    qll.enqueue(5);
    qll.enqueue(3);
    qll.enqueue(-2);
    qll.print();
    qll.peek();
    return 0;
}
