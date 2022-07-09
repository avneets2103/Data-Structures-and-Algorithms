#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int length(Node* head){
    int cnt=0;
    while(head != NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}

Node *appendLastNToFirst(Node *head, int n)
{
    int l=length(head);
    Node*temp2=head;
    Node*temp=head;
    if(n>l){
        return NULL;
    }
    if (n==0)
    {
        return head;
    }
    
    for (int i = 0; i < l-n-1; i++)
    {
        temp=temp->next;
    }
    Node* new_head=temp->next;
    
    for (int i = 0; i < l-1; i++)
    {
        temp2=temp2->next;   
    }
    temp2->next=head;
    temp->next=NULL;
    return new_head;
}

Node *take_input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    while (data != -1)
    {
        Node *n1 = new Node(data);
        if (head == NULL)
        {
            head = n1;
        }
        else{
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n1;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head; // we use temp as if we are using head we are actually using our head address which is risky.
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = take_input();
    int n;
    cout << "ENTER n: " << endl;
    cin >> n;
    Node *new_head = appendLastNToFirst(head, n);
    cout << "works" << endl;
    print(new_head);
    cout << "works_yet";
    return 0;
}
