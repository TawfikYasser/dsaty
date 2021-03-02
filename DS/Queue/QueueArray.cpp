#include <iostream>

using namespace std;
const int queue_size = 5;
int queue[queue_size];
int front = -1;
int rear = -1;
void enqueue(int value){
    if(rear == queue_size-1){
        cout<<"Overflow"<<endl;
    }else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = value;
    }else{
        rear++;
        queue[rear] = value;
    }
}
void dequeue(){
    if(front == -1 && rear == -1){
        cout<<"Empty queue"<<endl;
    }else if(rear == front){
        front = rear = -1;
    }else{
        front++;
    }
}
void peek(){
    if(front == -1 && rear == -1){
        cout<<"Empty queue"<<endl;
    }else{
        cout<<queue[front]<<endl;
    }
}
void print(){
    if(front == rear){
        cout<<queue[front]<<endl;
    }else{
        for(int i = front ; i <rear +1 ;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    print();
    peek();
    dequeue();
    print();
    peek();
    return 0;
}
