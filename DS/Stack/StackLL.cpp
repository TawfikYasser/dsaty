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
class StackLL
{
private:
    Node *top;
    int _length;
public:
    StackLL()
    {
        top = NULL;
    }
    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if(top == NULL)
        {
            cout<<"Empty Stack"<<endl;
        }
        else
        {
            Node *temp = new Node();
            temp = top;
            top = top->next;
            delete temp;
        }
    }
    void peek()
    {
        if(top == NULL)
        {
            cout<<"Empty Stack"<<endl;
        }
        else
        {
            cout<<top->data<<endl;
        }
    }
    void print()
    {
        if(top == NULL)
        {
            cout<<"Empty Stack"<<endl;
        }
        else
        {
            Node *temp = new Node();
            temp = top;
            while(temp != NULL)
            {
                cout<<"[ "<<temp->data<<" ] ";
                temp = temp->next;
            }
        }
    }

    void calcSize()
    {
        if(top == NULL)
        {
            _length = 0;
        }
        else
        {
            int _count;
            Node *temp = NULL;
            temp = top;
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
    StackLL sll;
    sll.push(2);
    sll.push(3);
    sll.push(10);
    sll.print();
    cout<<endl;
    sll.peek();
    cout<<endl;
    cout<<"Stack Size = "<<sll._size();
    sll.pop();
    cout<<endl;
    sll.print();
    cout<<endl;
    sll.peek();
    cout<<endl;
    cout<<"Stack Size = "<<sll._size();
    return 0;
}
