#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class queue_using_LL{
    int size;
    Node *front, *rear;
    public:
    queue_using_LL(){
        front=rear=NULL;
    }
    void enQueue(int x){
        Node*temp=new Node(x);
        if (rear==NULL){
            front=rear=temp;
            return;
        }
    }
    void deQueue(){
        if (front==NULL)
        {
            return;
        }
        Node*temp=front;
        front=front->next;
        if (front==NULL)
        {
            rear=NULL;
        }
        delete(temp);
    }
};

int main(){return 0;}
