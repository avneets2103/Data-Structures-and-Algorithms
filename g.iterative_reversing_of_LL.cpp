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

Node* reverseLinkedList(Node* head){
    Node* current = head;
    Node *prev = NULL, *next = NULL;
            while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
    head = prev;
}

int main(){return 0;}
