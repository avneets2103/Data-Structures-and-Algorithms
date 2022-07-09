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

Node* mergeTwoSortedLinkedLists(Node* head1, Node* head2){
    Node* fi=NULL;
    Node* ft=NULL;

    if(head1==NULL && head2==NULL){
        return NULL;
    }

    if(head1==NULL && head2!=NULL){
        return head2;
    }

    if(head1!=NULL && head2==NULL){
        return head1;
    }

    if(head1->data > head2->data){
        fi=head2;
        ft=head2;
        head2=head2->next;
    }
    else{
        fi=head1;
        ft=head1;
        head1=head1->next;
    }

    while(head1!=NULL && head2!=NULL){   
    if(head1->data > head2->data){
        ft->next=head2;
        ft=head2;
        head2=head2->next;
        
    }
    else{
        ft->next=head1;
        ft=head1;
        head1=head1->next;
    }
    }

    if(head2==NULL){
        ft->next=head1;
    }
    if(head1==NULL){
        ft->next=head2;
    }
    return fi;
}
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

//sorting using recursion
Node* mergeSort(Node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    Node* new_node = midPoint(head);
    Node*new_head=new_node->next;
    new_node->next=NULL;

    Node*sorted1=mergeSort(head);
    Node*sorted2=mergeSort(new_head);
    Node* final = mergeTwoSortedLinkedLists(sorted1,sorted2);
    return final;
}

int main(){return 0;}
