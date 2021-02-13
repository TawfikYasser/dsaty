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
    int _length;
public:
    DLL(){head = NULL;}
    void dummyDLL(){
        Node *temp = new Node();
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
                head = temp = newNode;
            }else{
                temp->next = newNode;
                newNode->prev = temp;
                temp = newNode;
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
};
int main()
{
    DLL dll ;
    dll.dummyDLL();
    return 0;
}
