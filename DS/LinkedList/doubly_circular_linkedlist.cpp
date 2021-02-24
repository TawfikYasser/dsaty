//Tawfik Yasser
#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node() {}
};
class DCLL
{
private:
    Node *head;
    Node *tail;
    int _length;
public:
    DCLL()
    {
        head = tail = NULL;
    }
    void createDCLL()
    {
        int con = 1;
        while(con == 1)
        {
            Node *newNode = new Node();
            cout<<"Enter node data: "<<endl;
            int d;
            cin>>d;
            newNode->data = d;
            if(head == NULL)
            {
                head = tail = newNode;
                head->next = head;
                head->prev = head;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                newNode->next = head;
                head->prev = newNode;
                tail = newNode;
            }
            cout<<"Do your want to continue (1/0) ? "<<endl;
            cin>>con;
        }
        Node *temp = new Node();
        temp = head;
        do
        {
            cout<<"[ "<<temp->data<<" ] ";
            temp = temp->next;
        }
        while(temp->next != tail->next);
        cout<<"[ "<<temp->data<<" ] ";
    }

    void insertAtBeginning(int value){
        Node *newNode = new Node();
        if(head == NULL){
            head = tail = newNode;
            newNode->data = value;
            newNode->next = newNode->prev = newNode;
        }else{
            newNode->data = value;
            newNode->next = head;
            head->prev = newNode;
            newNode->prev = tail;
            tail->next = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value){
        Node *newNode = new Node();
        if(head == NULL){
            head = tail = newNode;
            newNode->data = value;
            newNode->next = newNode->prev = newNode;
        }else{
            newNode->data = value;
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void insertAtPosition(int position, int value){
        Node *newNode = new Node();
        if(head == NULL){
            head = tail = newNode;
            newNode->data = value;
            newNode->next = newNode->prev = newNode;
        }else{
            if(position == 1){
                insertAtBeginning(value);
            }else{
                int i = 1;
                Node *temp = new Node();
                temp = head;
                while(i < position-1){
                    temp = temp->next;
                    i++;
                }
                newNode->data = value;
                newNode->next = temp->next;
                temp->next->prev = newNode;
                newNode->prev = temp;
                temp->next = newNode;
            }
        }
    }

    void deleteFromBeginning(){
        Node *temp = new Node();
        temp = head;
        if(head == NULL){
            cout<<"Empty List"<<endl;
        }else if(head == tail){
            head = tail = NULL;
            delete temp;
        }else{
            temp->next->prev = tail;
            tail->next = temp->next;
            head = temp->next;
            delete temp;
        }
    }

    void deleteFromEnd(){
        Node *temp = new Node();
        temp = tail;
        if(head == NULL){
            cout<<"Empty List"<<endl;
        }else if(head == tail){
            head = tail = NULL;
            delete temp;
        }else{
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }

    void deleteFromPosition(int position){
        Node *temp = new Node();
        temp = head;
        if(head == NULL){
            cout<<"Empty List"<<endl;
        }else{
            if(position == 1){
                deleteFromBeginning();
            }else if(position == _size()){
                deleteFromEnd();
            }else if(position < 1 || position > _length){
                cout<<"Invalid Position"<<endl;
            }else{
                int i = 1;
                while(i<position){
                    temp = temp->next;
                    i++;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        }
    }

    void printLL()
    {
        if(head == NULL)
        {
            cout<<"Empty list"<<endl;
        }
        else
        {
            Node *temp = new Node();
            temp = head;
            do
            {
                cout<<"[ "<<temp->data<<" ] ";
                temp = temp->next;
            }
            while(temp->next != tail->next);
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

            Node *temp = new Node();
            temp = head;
            do
            {
                temp = temp->next;
                _count++;
            }
            while(temp->next != tail->next);
            _count+=1;
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
    DCLL dcll;
    //dcll.createDCLL();
    dcll.insertAtBeginning(1);
    dcll.insertAtBeginning(2);
    dcll.insertAtBeginning(9);
    dcll.insertAtEnd(10);
    dcll.insertAtEnd(5);
    dcll.insertAtEnd(3);
    dcll.insertAtPosition(3,20);
    dcll.deleteFromBeginning();
    dcll.deleteFromEnd();
    dcll.deleteFromPosition(3);
    cout<<"Linked list items: ";
    dcll.printLL();
    cout<<endl;
    cout<<"List size = "<<dcll._size();
    return 0;
}
