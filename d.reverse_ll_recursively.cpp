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

Node* reverseLinkedListRec(Node* head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    //recursive call
    Node* new_node=reverseLinkedListRec(head->next);
    Node* temp=new_node;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return new_node;
}

int main(){return 0;}
