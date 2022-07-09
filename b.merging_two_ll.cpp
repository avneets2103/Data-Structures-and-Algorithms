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

int main(){return 0;}
