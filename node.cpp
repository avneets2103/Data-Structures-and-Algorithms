#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next; //address of a node thus a node pointer
    
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
