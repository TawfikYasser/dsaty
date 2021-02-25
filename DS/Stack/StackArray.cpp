//Tawfik Yasser
#include <iostream>

using namespace std;
class Stack_Array
{
private:
    int _size = 0;
    int stackArray[1];
    int top = 0;
public:
    Stack_Array(int stack_size)
    {
        _size = stack_size;
        stackArray[_size];
        top = -1;
    }

    void push(int value)
    {
        if(top == _size-1)
        {
            cout<<"Overflow"<<endl;
        }
        else
        {
            top++;
            stackArray[top] = value;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Underflow"<<endl;
        }
        else
        {
            top--;
        }
    }

    void peek()
    {
        if(top == -1)
        {
            cout<<"Empty stack"<<endl;
        }
        else
        {
            cout<<stackArray[top]<<endl;
        }
    }

    void print()
    {
        if(top == -1)
        {
            cout<<"Empty stack"<<endl;
        }
        else
        {
            for(int i = top; i>=0 ; i--)
            {
                cout<<stackArray[i]<<" ";
            }
        }

    }

    int search(int value)
    {
        if(top == -1)
        {
            cout<<"Empty stack"<<endl;
        }
        else
        {
            for(int i = top; i>=0 ; i--)
            {
                if(stackArray[top] == value){
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Stack_Array s(5);
    s.push(5);
    s.print();
    return 0;
}
