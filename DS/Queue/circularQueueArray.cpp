//Tawfik Yasser
#include <iostream>

using namespace std;
const int queue_size = 5;
int cQueue[queue_size];
int front = -1;
int rear = -1;
void enqueue(int value)
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        cQueue[rear] = value;
    }
    else if( ((rear+1)%queue_size) == front )
    {
        cout<<"Full Queue"<<endl;
    }
    else
    {
        rear = (rear+1)%queue_size;
        cQueue[rear] = value;
    }
}

void dequeue()
{
    if((front == -1 && rear == -1) || (front == rear))
    {
        front = rear = -1;
    }
    else
    {
        front = (front+1)%queue_size;
    }
}

void peek()
{
    if(front == -1 && rear == -1)
    {
        cout<<"Empty queue"<<endl;
    }
    else
    {
        cout<<cQueue[front]<<endl;
    }
}

void print(){
    if(front == -1 && rear == -1){
        cout<<"Empty queue"<<endl;
    }else if(front == rear){
        cout<<cQueue[front]<<endl;
    }else{
        int i = front;
        while(i != rear){
            cout<<cQueue[i]<<" ";
            i = (i+1)%queue_size;
        }
        cout<<cQueue[rear];
    }
}
int main()
{
    enqueue(5);
    enqueue(3);
    enqueue(2);
    enqueue(-1);
    enqueue(0);
    print();
    cout<<endl;
    dequeue();
    enqueue(9);
    print();
    cout<<endl;
    peek();
    return 0;
}
