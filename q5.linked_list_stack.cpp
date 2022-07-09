#include<iostream>
using namespace std;

class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

class Stack{
   Node* head;
   int size;
	// Define the data members
   public:
    Stack(){
        // Implement the Constructor
        head=NULL;
        int size=0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize(){
        // Implement the getSize() function
        return size;
    }

    bool isEmpty(){
        // Implement the isEmpty() function
        if (size==0)
        {
            return true;
        }
        else{
            return false;
        }
    }

    void push(int element){
        // Implement the push() function
        Node* new_node=new Node(element);
        new_node->next=head;
        head=new_node;
        size++;
    }

    int pop(){
        // Implement the pop() function
        if(size!=0){
        Node* temp=head;
        head=head->next;
        return temp->data;
        size--;
}
        else{
            cout<<"Empty stack"<<endl;
            return 0;
        }
    }
    
    int top() {
        // Implement the top() function
        if (size!=NULL)
        {
            return head->data;
        }
        else{
            cout<<"empty stack"<<endl;
            return 0;
        }
    }
};

int main(){return 0;}
