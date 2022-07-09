/*
Variations:

a) Doubly LL
b) Circular LL
c) Circularly Doubly LL
*/

#include<iostream>
using namespace std;

class Doubly_Node{
    public:
    int data;
    Doubly_Node *next,*prev;
    Doubly_Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};

class Circular_Node{
    public:
    int data;
    Circular_Node* next; 
    //tail->next=head
};

int main(){return 0;}
