//Tawfik Yasser
//Dequeue using arrays
#include <iostream>
using namespace std;
const int dequeue_size = 5;
int dequeue[dequeue_size];
int f = -1, r = -1;

void enqueueFront(int value){
    if( (f==0 && r== dequeue_size-1) || (f == r+1) ){
        cout<<"Dequeue Full"<<endl;
    }else if(f==-1 && r==-1){
        f = r = 0;
        dequeue[f] = value;
    }else if(f == 0){
        f = dequeue_size -1;
        dequeue[f] = value;
    }else{
        f--;
        dequeue[f] = value;
    }
}
void enqueueRear(int value){
    if( (f==0 && r== dequeue_size-1) || (f == r+1) ){
        cout<<"Dequeue Full"<<endl;
    }else if(f == -1 && r == -1){
        f = r = 0;
        dequeue[r] = value;
    }else if(r == dequeue_size-1){
        r = 0;
        dequeue[r] = value;
    }else{
        r++; dequeue[r] = value;
    }
}
void dequeueFront(){
    if(r == -1 && f == -1){
        cout<<"Dequeue Empty"<<endl;
    }else if(f == r){
        f = r = -1;
    }else if(f == dequeue_size-1){
        f = 0;
    }else{
        f++;
    }
}
void dequeueRear(){
    if(r == -1 && f == -1){
        cout<<"Dequeue Empty"<<endl;
    }else if(f == r){
        f = r = -1;
    }else if(r == 0){
        r = dequeue_size -1;
    }else{
        r--;
    }
}
void display(){
    int i = f;
    while(i != r)
    {
        cout<<dequeue[i]<<" ";
        i = (i+1) % dequeue_size;
    }
    cout<<dequeue[r]<<endl;
}
void getFront(){
    if(f ==-1 && r ==-1){
        cout<<"Empty dequeue"<<endl;
    }else{
        cout<<dequeue[f]<<endl;
    }
}
void getRear(){
    if(f ==-1 && r ==-1){
        cout<<"Empty dequeue"<<endl;
    }else{
        cout<<dequeue[r]<<endl;
    }
}
int main()
{
    enqueueFront(5);
    enqueueRear(2);
    enqueueRear(-1);
    enqueueFront(3);
    display();
    dequeueFront();
    display();
    dequeueRear();
    display();
    getFront();
    getRear();
    return 0;
}
