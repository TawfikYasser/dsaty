//Tawfik Yasser
#include <iostream>

using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(){}
};
class CLL{

private:
    Node *head;
    int _length;
public:
    CLL(){head = NULL;}
    void dummyCLL(){
        Node *temp = new Node();
        int con = 1;
        while(con == 1){
            Node *newNode = new Node();
            cout<<"Enter node data: "<<endl;
            int d;
            cin>>d;
            newNode->data = d;
            newNode->next = NULL;
            if(head == NULL){
                head = temp = newNode;
            }else{
                temp->next = newNode;
                temp = newNode;
            }
            temp->next = head;
            cout<<"Do your want to continue (1/0) ? "<<endl;
            cin>>con;
        }
        temp = head;
        while(temp->next != head){
            cout<<"[ "<<temp->data<<" ] ";
            temp = temp->next;
        }
        cout<<"[ "<<temp->data<<" ] ";
    }

    void printLL()
    {
        if(head == NULL)
        {
            cout<<"Empty list"<<endl;
        }
        else
        {
            Node *temp = NULL;
            temp = head;
            while(temp->next != head)
            {
                cout<<"[ "<<temp->data<<" ] ";
                temp = temp->next;
            }
            cout<<"[ "<<temp->data<<" ] ";
        }
    }

    void calcSize()
    {
        if(head == NULL)
        {
            _length = 0;
        }
        else
        {
            int _count;
            Node *temp = NULL;
            temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
                _count++;
            }
            _count++;
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
    CLL cll;
    cll.dummyCLL();
    cout<<endl;
    cout<<"Linked List Size = "<<cll._size()<<endl;
    return 0;
}
