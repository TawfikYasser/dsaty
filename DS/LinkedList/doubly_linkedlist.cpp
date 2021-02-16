//Tawfik Yasser
#include <iostream>

using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(){}
};
class DLL{

private:
    Node *head;
    Node *tail;
    int _length;
public:
    DLL(){head = NULL; tail = NULL;}
    void dummyDLL(){
        Node *temp = new Node();
        Node *tail = new Node();
        int con = 1;
        while(con == 1){
            Node *newNode = new Node();
            cout<<"Enter node data: "<<endl;
            int d;
            cin>>d;
            newNode->data = d;
            newNode->next = NULL;
            newNode->prev = NULL;
            if(head == NULL){
                head = tail = newNode;
            }else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            cout<<"Do your want to continue (1/0) ? "<<endl;
            cin>>con;
        }
        temp = head;
        while(temp != NULL){
            cout<<"[ "<<temp->data<<" ] ";
            temp = temp->next;
        }
    }

    void insertAtBeginning(int value){
        if(head == NULL){ //Empty
            head = new Node();
            tail = new Node();
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
        }else{
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = NULL;
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int value){
        if(head == NULL){//Empty
            head = new Node();
            tail = new Node();
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
        }else{
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = NULL;
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPosition(int position, int value){
        if(head == NULL){//Empty
            head = new Node();
            tail = new Node();
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
        }else if(position == 1){
            insertAtBeginning(value);
        }else{
            Node *newNode= new Node();
            Node *temp = new Node();
            temp = head;
            int i = 1 ;
            while(i < position-1){
                temp = temp->next;
                i++;
            }
            newNode->data = value;
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->next->prev = newNode;
        }
    }

    void insertAfterPosition(int position, int value){
        if(head == NULL){//Empty
            head = new Node();
            tail = new Node();
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
        }else if(position == 1){
            insertAtBeginning(value);
        }else{
            Node *newNode= new Node();
            Node *temp = new Node();
            temp = head;
            int i = 1 ;
            while(i < position){
                temp = temp->next;
                i++;
            }
            newNode->data = value;
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->next->prev = newNode;
        }
    }

    void deleteFromBeginning(){

        if(head == NULL){
            cout<<"Empty List"<<endl;
        }else{
            Node *temp = new Node();
            temp = head;
            head = temp->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void deleteFromEnd(){
        if(head == NULL){
            cout<<"Empty List"<<endl;
        }else{
            Node *temp = new Node();
            temp = tail;
            tail->prev->next = NULL;
            tail = tail->prev;
            delete temp;
        }
    }

    void deleteFromPosition(int position){
        if(head == NULL){
            cout<<"Empty List"<<endl;
        }else if(position == 1){
            deleteFromBeginning();
        }else if(position == _size()){
            deleteFromEnd();
        }else{
            Node *temp = new Node();
            int i = 1;
            temp = head;
            while( i < position ){
                temp = temp->next;
                i++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    void reverse(){
        if(head == NULL){
            cout<<"Empty list"<<endl;
        }else{
            Node *currentNode = new Node();
            Node *nextNode = new Node();
            currentNode = head;
            while(currentNode != NULL){
                nextNode = currentNode->next;
                currentNode->next = currentNode->prev;
                currentNode->prev = nextNode;
                currentNode = nextNode;
            }
            currentNode = head;
            head = tail;
            tail = currentNode;
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
            Node *temp = NULL;
            temp = head;
            while(temp!= NULL)
            {
                cout<<"[ "<<temp->data<<" ] ";
                temp = temp->next;
            }
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
    DLL dll ;
    dll.insertAtBeginning(5);
    dll.insertAtBeginning(3);
    dll.insertAtBeginning(9);
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(1);
    dll.insertAtEnd(25);
    dll.insertAtPosition(3,7);
    dll.insertAfterPosition(7,8);
    cout<<"Linked List Items: ";
    dll.printLL();
    cout<<endl;
    cout<<"Linked List Size = "<<dll._size()<<endl;
    dll.deleteFromBeginning();
    dll.deleteFromEnd();
    cout<<"Linked List Items: ";
    dll.printLL();
    cout<<endl;
    cout<<"Linked List Size = "<<dll._size()<<endl;
    dll.deleteFromPosition(4);
    cout<<"Linked List Items: ";
    dll.printLL();
    cout<<endl;
    cout<<"Linked List Size = "<<dll._size()<<endl;
    dll.reverse();
    cout<<"Linked List Items: ";
    dll.printLL();
    cout<<endl;
    cout<<"Linked List Size = "<<dll._size()<<endl;
    return 0;
}
