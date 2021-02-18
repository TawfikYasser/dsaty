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
    Node *tail;
    int _length;
public:
    CLL(){head = NULL; tail=NULL;}
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

    void createWithHeadAndTail(){
        int con = 1;
        while(con==1){
            Node *newNode = new Node();
            cout<<"Enter node data: "<<endl;
            int d;
            cin>>d;
            newNode->data = d;
            newNode->next = NULL;
            if(head == NULL){
                head = tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            tail->next = head;
            cout<<"Do your want to continue (1/0) ? "<<endl;
            cin>>con;
        }
        Node *temp = new Node();
        temp = head;
        while(temp->next != head){
            cout<<"[ "<<temp->data<<" ] ";
            temp = temp->next;
        }
        cout<<"[ "<<temp->data<<" ] ";
    }

    void createWithTail(){
        int con = 1;
        while(con==1){
            Node *newNode = new Node();
            cout<<"Enter node data: "<<endl;
            int d;
            cin>>d;
            newNode->data = d;
            newNode->next = NULL;
            if(tail == NULL){
                tail = newNode;
                tail->next = newNode;
            }else{
                newNode->next = tail->next;
                tail->next = newNode;
                tail = newNode;
            }
            cout<<"Do your want to continue (1/0) ? "<<endl;
            cin>>con;
        }
        Node *temp = new Node();
        temp = tail->next;
        while(temp->next != tail->next){
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

    ///To create a circular linked list you can use any of three methods
    /*
    //1. create cll with tail only
    cll.createWithTail();
    cout<<endl;
    cout<<"Linked List Size = "<<cll._size()<<endl;
    //2. create cll with head only
    cll.dummyCLL();
    cout<<endl;
    cout<<"Linked List Size = "<<cll._size()<<endl;
    //2. create cll with head and tail pointers
    cll.createWithHeadAndTail();
    cout<<endl;
    cout<<"Linked List Size = "<<cll._size()<<endl;
    */
    return 0;
}
