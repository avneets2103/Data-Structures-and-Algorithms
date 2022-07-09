/*
Stack:
1. These are abstract data type which means that you can do insertion and deletion in a specific order onyl and operations cant be random.
2. First come last serve (or) Last in first out (or) Last push first pop
3. There is only one entry and exit point
4. Insert at the top: push(element)
5. Deletion of last top most element and printing it too: pop()
6. Accessing the top element: peek() 
7. To check if our stack is empty or not: isEmpty()
*/

#include<iostream>
using namespace std;

//using array
class stack{
    private:
    int* a;
    int top;
    int n;

    public: 
    stack(int n){     
        a=new int[n];
        this->n=n;
        top=-1;
    }
    void push(int element){
        if (top<n-1)
        {
            top++;
            a[top]=element;
            cout<<element<<" was pushed in the stack."<<endl;
        }
        else{
            cout<<"Stack overlaoding"<<endl;
        }
    }
    int pop(){
        if (top>-1)
        {
            return a[top--];
        }
        else{
            cout<<"Stack underlaoding"<<endl;
            return 0;
        }
    }
    int seek(){
        if (top>-1)
        {
            return a[top];
        }
        else{
            cout<<"Empty stack"<<endl;
            return 0;
        }
    }
    bool isEmpty(){
        if (top ==-1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    int size(){
        return top+1;
    }
};

int main(){
    cout<<"Enter max limit of our stack: "<<endl;
    int n;
    cin>>n;
    stack s1(n);
    s1.push(23);
    s1.push(543);
    cout<<s1.pop()<<endl;
    cout<<s1.seek()<<endl;
    return 0;}
