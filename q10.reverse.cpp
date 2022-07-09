// reversing a linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int length(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        head=head->next;
        cnt++;
    }
    return cnt;
}

Node* reverse(Node *head)
{
    int len = length(head);
    for (int k = 0; k < len; k++)
    {
        Node *temp = head;
        Node *temp2 = head;
        if (k==len-1)
        {
            temp->next=NULL;
            break;
        }
        for (int i = 0; i < len-k; i++)
        {
            temp = temp->next;
        }
        for (int j = 0; j < len-k-1; j++)
        {
            temp2 = temp2->next;
        }
        temp->next=temp2;
    }
    while (head != NULL)
    {
        head=head->next;
    }
    return head;    
}

Node* printReverse(Node* head){
    //base
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        cout<<head->data<<" ";
        return head;
    }

    //induction
    printReverse(head->next);
    return head;
}