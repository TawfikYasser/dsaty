#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node() {}
};
class TLL
{
private:
    Node *head;
    int _length;
public:

    //Constructor to initialize a LinkedList
    TLL()
    {
        head = NULL;
    }

    void insertAtBeginning(int value)
    {
        if(head == NULL)  // Empty LL
        {
            head = new Node();
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            head = newNode;
        }
        else   //Non-Empty LL
        {
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int value){
        if(head == NULL){ // Empty LL
            head = new Node();
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            head = newNode;
        }else{
            Node *temp = new Node();
            Node *newNode = new Node();
            newNode->data = value;
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
        }
    }

    void insertAfterPosition(int value,int position){

        if(head == NULL){//Empty LL

            head = new Node();
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            head = newNode;

        }else{
            calcSize();
            if(position>_length){
                cout<<"Out of bounds!"<<endl;
            }else{
                int i = 1;
                Node *temp = new Node();
                Node *newNode = new Node();
                newNode->data = value;
                temp = head;
                while(i<position){
                    temp = temp->next;
                    i++;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    void insertBeforePosition(int value, int position){
        if(head == NULL){ // Empty ll
            head = new Node();
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            head = newNode;
        }else{
            calcSize();
            if(position>_length){
                cout<<"Out of bounds!"<<endl;
            }else{
                int i = 1;
                Node *temp = new Node();
                Node *newNode = new Node();
                newNode->data = value;
                temp = head;
                while(i < position - 1){
                    temp = temp->next;
                    i++;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    void deleteFromBeginning(){
        if(head == NULL){
            cout<<"Empty list";
        }else{
            Node *temp = new Node();
            temp = head;
            head = temp->next;
            delete temp;
        }
    }

    void deleteFromEnd(){

        if(head == NULL){
            cout<<"Empty list";
        }else{
            Node *temp = new Node();
            temp = head;
            Node *previous = new Node();
            previous = head;
            while(temp->next != NULL){
                previous = temp;
                temp = temp->next;
            }
            if(temp==head){//One node in the list
                head = NULL;
            }else{
                previous->next = NULL;
            }
            delete temp;
        }

    }

    void deleteAtPosition(int position){
        if(head == NULL){
            cout<<"Empty list";
        }else{
            Node *temp = new Node();
            Node *next = new Node();
            temp = head;
            int i = 1;
            while(i < position -1){
                temp = temp->next;
                i++;
            }
            next = temp->next;
            temp->next = next->next;
            delete next;
        }
    }

    void printLL()
    {
        Node *temp = NULL;
        temp = head;
        while(temp!= NULL)
        {
            cout<<"[ "<<temp->data<<" ] ";
            temp = temp->next;
        }
    }

    void calcSize(){
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

    int _size()
    {
        calcSize();
        return _length;
    }
};
int main()
{
    TLL ll;

    ll.insertAtBeginning(1);
    ll.insertAtEnd(5);
    ll.insertAtEnd(10);
    ll.insertAtEnd(3);
    ll.insertAtBeginning(2);
    ll.insertAtEnd(25);
    ll.insertAfterPosition(15,3);
    ll.insertBeforePosition(11,4);
    ll.deleteFromBeginning();
    ll.deleteFromEnd();
    ll.deleteAtPosition(3);

    cout<<"Linked List Items: ";
    ll.printLL();

    cout<<endl;
    cout<<"Linked List Size = "<<ll._size()<<endl;
    return 0;
}
