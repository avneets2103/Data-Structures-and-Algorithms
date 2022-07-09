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

class Pair{
    public:
    Node* head;
    Node* tail;
};

Pair reverseLL(Node* head){
    if(head==NULL || head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }

    Pair smallAns=reverseLL(head->next);
    smallAns.tail->next=head;
    head->next=NULL;
    Pair ans;
    ans.head=smallAns.head;
    ans.tail=head;
    return (ans);
}

Node* reverseLL_double(Node* head){
    return(reverseLL(head).head);
}

int main(){return 0;}
