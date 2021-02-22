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
class DCLL{
private:
    Node *head;
    Node *tail;
    int _length;
public:
    DCLL(){head = tail = NULL;}
    void createDCLL(){
        int con = 1;
        while(con == 1){
            Node *newNode = new Node();
            cout<<"Enter node data: "<<endl;
            int d;
            cin>>d;
            newNode->data = d;
            if(head == NULL){
                head = tail = newNode;
                head->next = head;
                head->prev = head;
            }else{
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
        do{
            cout<<"[ "<<temp->data<<" ] ";
            temp = temp->next;
        }while(temp->next != tail->next);
        cout<<"[ "<<temp->data<<" ] ";
    }
};
int main()
{
    DCLL dcll;
    dcll.createDCLL();
    return 0;
}
