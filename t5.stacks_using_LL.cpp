#include<iostream>
using namespace std;

template <typename T>
class node{
    public: 
    T data;
    node<T>* next;
    node(T data){
        this->data=data;
        next=NULL;
    }
};

template<typename T>
class stack{
    node<T>* head;
    node<T>* tail;
    public:
    stack(){
        head=NULL;
        tail=NULL;
        int size=0;
    }
    void push1(T element){
        node<T>* new_node=new node<T>(element);
        if (head==NULL)
        {
            head=new_node;
            tail=new_node;
        }
        else{
            tail->next=new_node;
            tail=tail->next;
        }
    }

    //O(n)
    T pop1(){
        if (head==NULL)
        {
            cout<<"Empty stack"<<endl;
        }
        else{
            node<T>* temp = head;
            while (temp!=tail)
            {
                temp=temp->next;
            }
            tail=temp;
            tail->next=NULL;
        }
    }
    T peek1(){
        if (tail!=NULL)
        {
            return tail->data;
        }
        else{
            cout<<"empty stack"<<endl;
            return 0;
        }
    }
    //O(1)
    //rather than putting data at the tail we rather do it for the head i.e. we mantain our LL backwards
    //for this you must change push also in this way
    void push2(T element){

        node*<T> new_node=new node<T>(element);
        new_node->next=head;
        head=new_node;
        size++;
    }
    T pop2(){
        if(head!=NULL){
        node*<T> temp=head;
        head=head->next;
        return temp->data;}
        else{
            cout<<"Empty stack"<<endl;
            size--;
            return 0;
        }
    }
    T peek2(){
        if (head!=NULL)
        {
            return head->data;
        }
        else{
            cout<<"empty stack"<<endl;
            return 0;
        }
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        if (size==0)
        {
            return True;
        }
        else{
            return false;
        }
    }
};

int main(){
    return 0;}
