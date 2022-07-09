/*
Dynamic stack:
We want to get no size constraint on our stack
*/

#include<iostream>
using namespace std;

class stack{
    private:
    int* a;
    int top;
    int present;

    public:
    stack(){
        a=new int[2];
        top==-1;
        present=2;
    }
    void push(int element){
        if (top==present-1)
        {
            //doubling array
            int*newData=new int[2*present];
            for (int i = 0; i < present; i++)
            {
                newData[i]=a[i];
            }
            present=present*2;
            delete [] a;
            a=newData;
        }
        top++;
        a[top]=element;
    }
    int peek(){
        if (top==-1)
        {
            cout<<"Empty stack"<<endl;
            return 0;
        }
        else{
            return a[top];
        }
    }
    int pop(){
        if (top==-1)
        {
            cout<<"Empty stack"<<endl;
            return 0;
        }
        else{
            return a[top--];
        }
    }  
};

int main(){
    stack s1;
    s1.push(12);
    s1.push(23);
    s1.push(34);
    s1.push(52);
    cout<<s1.pop()<<endl;
    cout<<s1.peek()<<endl;
    return 0;}
