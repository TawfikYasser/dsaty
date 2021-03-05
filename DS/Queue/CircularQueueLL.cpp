// Tawfik Yasser
//Circular Queue Linked List
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
    QueueLL()
    {
        front = rear = NULL;
    }
    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if(rear == NULL)
        {
            front = rear = newNode;
            rear->next = front;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }
    void dequeue()
    {
        Node *temp = front;
        if(front == NULL && rear == NULL){
            cout<<"Empty Queue"<<endl;
        }else if(front == rear){
            front = rear = NULL;
            delete temp;
        }else{
            front = temp->next;
            rear->next = front;
            delete temp;
        }
    }
    void peek()
    {
        if(front == NULL && rear == NULL){
            cout<<"Empty Queue"<<endl;
        }else{
            cout<<front->data<<endl;
        }
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
            while(temp->next != front)
            {
                cout<<"[ "<<temp->data<<" ] ";
                temp = temp->next;
            }
            cout<<"[ "<<temp->data<<" ] ";
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
            while(temp->next != front)
            {
                temp = temp->next;
                _count++;
            }
            _length = _count +1;
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
    cout<<endl;
    qll.peek();
    qll.dequeue();
    qll.print();
    cout<<endl;
    qll.peek();
    return 0;
}
