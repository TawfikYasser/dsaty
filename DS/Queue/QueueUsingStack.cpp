// Tawfik Yasser
// Queue using stack
#include <iostream>
using namespace std;
const int queue_size = 5;
int stack1[queue_size], stack2[queue_size];
int top1 = -1, top2 = -1;
int counter = 0;
void pushToStack1(int value){
    if(top1 == queue_size-1){
        cout<<"Overflow"<<endl;
    }else{
        top1++;
        stack1[top1] = value;
    }
}
void pushToStack2(int value){
    if(top2 == queue_size-1){
        cout<<"Overflow"<<endl;
    }else{
        top2++;
        stack2[top2] = value;
    }
}
int popFromStack1(){
    return stack1[top1--];
}
int popFromStack2(){
    return stack2[top2--];
}
void enqueue(int value){
    pushToStack1(value);
    counter++;
}
void dequeue(){
    if(top1 == -1){
        cout<<"Empty queue"<<endl;
    }else{
        for(int i=0; i<counter;i++)
            pushToStack2(popFromStack1());
        popFromStack2();
        counter--;
        for(int i =0;i<counter;i++)
            pushToStack1(popFromStack2());
    }
}
void display(){
    for(int i=0;i<=top1;i++)
        cout<<stack1[i]<<" ";
}
void peek(){
    cout<<stack1[0]<<endl;
}
int main()
{
    enqueue(5);
    enqueue(2);
    enqueue(-1);
    display();
    cout<<endl;
    peek();
    dequeue();
    display();
    cout<<endl;
    peek();
    return 0;
}
