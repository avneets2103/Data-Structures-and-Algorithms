#include<iostream>
using namespace std;

//dynamic

template<typename T>
class stack{
    T* a;
    int top;
    int capacity;

    public:
    stack(){
        a=new T[2];
        top=-1;
        capacity=2;
    }
    void push(T element){
        if (top==capacity-1)
        {
            newData=new T[capacity*2];
            for (int i = 0; i < capacity; i++)
            {
                newData[i]=a[i];
            }
            capacity*=2;
            delete [] a;
            a=newData;
        }
        a[++top]=element;
    }
    T pop(){
        if (top==-1)
        {
            cout<<"Empty stack"<<endl;
            return 0;
        }
        else{
            return a[top--];
        }
    }
    T peek(){
        if (top==-1)
        {
            cout<<"Empty stack"<<endl;
            return 0;
        }
        else{
            return a[top];
        }
    }
};

//return 0 in template cases as 0 is valid in every case either a bool, double, char etc.

int main(){return 0;}
