#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int a){
        data=a;
        next=NULL;
    }
};
 
Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* fwd = NULL;

    while (curr != NULL)
    {
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }

    return prev;
}

bool isPalindrome(Node* head){
    if (head==NULL || head->next == NULL)
    {
        return true;
    }

    //Find centre of list
    Node* fast = head;
    Node* slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    Node* secondHead=slow->next;
    slow->next=NULL;
    secondHead=reverse(secondHead);

    //Comparing
    Node* first=head;
    Node* second = secondHead;

    bool ans = true;

    while(second != NULL){
        if (first->data != second->data)
        {
            ans = false;
            break;
        }
        first=first->next;
        second=second->next;
    }    

    //Rejoin the two
    first=head;
    second=reverse(secondHead);
    while(first->next != NULL)
    {
        first=first->next;
    }
    first->next=second;
    return ans;
}
