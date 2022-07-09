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

void print(Node *head)
{
    Node *temp = head; // we use temp as if we are using head we are actually using our head address which is risky.
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteNodeRec(Node *head, int pos) {
   if(pos==0){
       head=head->next;
       return head;
   }
   Node* x=deleteNodeRec(head->next,pos-1);
   head->next=x;
   return head;
}

Node*removeDuplicates(Node* head){
    Node* temp1=head;
    if (head->next==NULL)
    {
        return head;
    }
    if(head==NULL)
    {
        return head;
    }
    while(temp1->next != NULL){
        static int cnt = 1;
        temp1=temp1->next;
        if (temp1 == NULL)
        {
            break;
        }
        if(temp1->data == head->data){
            deleteNodeRec(head,cnt);
        }
        cout<<cnt<<endl;
        cnt++;
    }
    removeDuplicates(head->next);
    return head;
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

int main() { 
    Node *head = take_input();
    int n;
    cout << "ENTER n: " << endl;
    cin >> n;
    removeDuplicates(head);
    print(head);
    return 0; }
