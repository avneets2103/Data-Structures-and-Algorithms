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


Node *midPoint(Node* head){
    if(head==NULL){return NULL;}
    Node* slow=head;
    Node* fast=head->next;
    while(slow!=NULL && fast != NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
