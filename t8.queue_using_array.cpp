//Queue: It is of type FIFO i.e. first in first out
//There are 2 different points for entry and exit
//Eg: Line of buying tickets

//Functions:
//1. enqueue(<element>): to insert
//2. front(): to peek the element 
//3. dequeue

#include<iostream>
using namespace std;

template<typename T>
class queue_by_array{
    T* data;
    int next_index;
    int front;
    int capacity=2;
public:
    queue_by_array(){
        data=new T[2];
        front=-1;
        next_index=0;
    }
    void enqueue(T element){
        if (front==-1)
        {
            front++;
        }
        if (next_index==capacity)
        {
            T* new_data=new T[2*capacity];
            for (int i = 0; i < capacity; i++)
            {
                new_data[i]=data[i];
            }
            delete [] data;
            data=new_data;
            capacity*=2;
        }
        data[next_index]=element;
        next_index++;
    }
    int front_element(){
    if (front==-1)
    {
        cout<<"Empty queue"<<endl;
        return 0;
    }
    return data[front];
    }
    int dequeue(){
    if (front==-1)
    {
        cout<<"Already empty queue"<<endl;
        return 0;
    }
    return data[front++];
    }
    bool isEmpty(){
    return front==-1;
    }
    int size(){
    if (front==-1)
    {
        return 0;
    }
    return next_index-front;
    }
};

int main(){
    queue_by_array<int> q1;
    cout<<"Enter number of elements you wanna enter: "<<endl;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin>>input;
        q1.enqueue(input);
    }
    cout<<"The front of queue is: "<<q1.front_element()<<endl; 
    cout<<"How mnay times you wanna dequeue: "<<endl;
    int times;
    cin>>times;
    for (int i = 0; i < times; i++)
    {
        q1.dequeue();
    }
    cout<<"The front of queue is: "<<q1.front_element()<<endl; 
    cout<<q1.isEmpty()<<endl;
    cout<<q1.size()<<endl;
    return 0;}
