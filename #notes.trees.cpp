#include<iostream>
using namespace std;

/*
[1.] Vectors:

These are just dynamic arrays, already defined in a class form of vector<T> where T is for template <typename T>
T stores the type of data being stored in the vector
Making a vector: */
#include<vector>
vector<int> v;
/*
Vector functions: 
> When we need to add a new element in a vector we use vector_name.pushback(element_data)
> Similarly we have vector_name.pop_back(element_data)
> Similarly we have vector_name.at(index_number) to access the data at the given index number
> vector_name.size() is a important inbuilt function in a vector which tells the number of elements in the vector

Implementation:*/
int main(){    
    v.push_back(10);
    v.push_back(20);
    v.pop_back();
    cout<<v.at(0);
    cout<<v.size();
}

/*
[2.] Generic Trees: 

Every node in a tree has children count ranging from 0 to n (as many as uh want)
Thus every node must carry 
1. its data
2. address of every children it has and as we dont already know the number of children a node is gonna have, thus we have to make a vector of tree_node* type to store address of the children node
Implementation: */
template <typename T>
class treeNode{
    public:
    T data;
    vector<treeNode<T>*> children;
    treeNode(T data){
        this->data=data;
    }
    ~treeNode(){
        for(int i = 0; i<this->children.size(); i++){
            delete children[i];
        }
    }
};

int main(){

    //dynamically making a tree_node
    treeNode<int>* root = new treeNode<int>(10);
    treeNode<int>* child2 = new treeNode<int>(30);
    //static tree_node
    treeNode<int> child1(20);

    //linking
    root->children.push_back(&child1);
    root->children.push_back(child2);
    return 0;
}

/*
[3.] Printing a tree normally: 
   root
 /      \
tree1  tree2

Here our target is to print something like:
node->data:children[0]->data,children[1]->data,...

Thus we let recursion do our work for the children and we do our task for the root node

Implementation:*/
void print_tree(treeNode<int>* root){
    cout<<root->data<<":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print_tree(root->children[i]);
    }
}

/*
[4.] Input (basic):
    root
 /       \
tree1   tree2

Here we take input for root_data and make a treeNode named root
Now we use recursion to do this for every child and add their address in the children vector of root
Implementation: */
treeNode<int>* take_input(){
    int root_data;
    cout<<"Enter data: "<<endl;
    cin>>root_data;
    treeNode<int>* root = new treeNode<int>(root_data);
    int child_count;
    cout<<"Enter number of children of "<<root_data<<endl;
    cin>>child_count;
    for (int i = 0; i < child_count; i++)
    {
        treeNode<int>* child_input = take_input();
        root->children.push_back(child_input);
    }
    return root;
}

/*
[5.] Level wise printing:  
<Note: This one isnt done using recursion>

Algo:
We maintain a queue, in which we keep adding the nodes whose children arent called yet
We keep on adding them and remove them from the begining, thus in this way the printing occurs level wise 
As here first the root is printed then all its children are printed(due to queue order) and goes on
Note: This is a much better way to print data for someone who dont understands recursion. 

Implementation: */
#include<queue>

void print_level_wise(treeNode<int>* root){
    queue<treeNode<int>*> rest_nodes;
    rest_nodes.push(root);
    while(rest_nodes.size()!=0){
        treeNode<int>* front_node=rest_nodes.front();
        rest_nodes.pop();
        cout<<front_node->data<<":";
        for (int i = 0; i < front_node->children.size(); i++)
        {
            rest_nodes.push(front_node->children[i]);
            cout<<front_node->children[i]->data<<",";
        }
        cout<<endl;
    }
}

/*
[6.] Input level wise: 
<Note: We arent using recursion here too>

Algo: 
We maintain a queue, in which we keep adding the nodes whose children arent calley yet
We keep on adding them and remove them from the begining by asing them theri child count

Implementation: */

treeNode<int>* input_level_wise(){
    queue<treeNode<int>*> rest_nodes;
    int root_data;
    cout<<"Enter root_data"<<endl;
    cin>>root_data;
    treeNode<int>* root = new treeNode<int>(root_data);
    rest_nodes.push(root);
    while(rest_nodes.size()!=0){
        treeNode<int>* front = rest_nodes.front();
        rest_nodes.pop();
        cout<<"Enter number of children of "<<front->data<<endl;
        int child_count;
        cin>>child_count;
        for (int i = 0; i < child_count; i++)
        {
            cout<<"Enter the child"<<i<<" of "<<front->data;
            int child_data;
            cin>>child_data;
            treeNode<int>* child = new treeNode<int>(child_data);
            rest_nodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}

//[7.] Application and basic programs on the tree data type: 

/*
[a.] Number nd Sum of nodes:

We approach this easily via recursion as all have to do is 
return 1+sum of children node counts for every child. (number of nodes)
return root->data + sum of children sum for every child. (sum of nodes) 
Implementation: */
int number_of_nodes(treeNode<int>* root){
    //base
    if(root->children.size()==0){
        return 1;
    }
    //induction
    int descendent_sum=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        descendent_sum+=number_of_nodes(root->children[i]);
    }
    return 1+descendent_sum;
}

int sum_of_nodes(treeNode<int>* root){
    //base
    if(root->children.size()==0){
        return root->data;
    }
    //
    int descendentsum=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        descendentsum+=sum_of_nodes(root->children[i]);
    }
    return root->data+descendentsum;
}

/*
[b.] Max_data_node:

Here we have to return the max node's address from the complete tree
Thus we start with taking a max_node and set it to root and then compare the node->data of the children to the max_node and update it to the new node if data stored in the new node is larger thanthe data of the original max node
*/

treeNode<int>* max_data_node(treeNode<int>* root){
    treeNode<int>* max_node=root;
    for (int i = 0; i < root->children.size(); i++)
    {
        if(max_node->data < max_data_node(root->children[i])->data){
            max_node=root->children[i];
        }
    }
    return max_node;
}

/*
[c.] Height of tree: 

Here we get the height of each sub tree using recursion and return the max of them + 1
Implementation: */

int height(treeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int max_height=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        if(max_height<height(root->children[i])){
            max_height=height(root->children[i]);
        }
    }
    return max_height+1;
}

/*
[d.]Leaf node counting: 

We count leaf node for every sub_tree and return the sum of all
Implementation: */

int getLeafNodeCount(treeNode<int>* root) {
    //edge_case
    if(root==NULL){
        return 0;
    }

    //base
    if(root->children.size()==0){
        return 1;
    }
    //induction
    int cnt=0;
    for (int i = 0; i < root->children.size(); i++)
    {
        cnt+=getLeafNodeCount(root->children[i]);
    }
    return cnt; 
}
/*

/*
[e.] Contains x:

We check if root->data == x then we return true
If any of the children trees contains the number x then we update the bool variable to true and return it.
Implementation: */

bool isPresent(treeNode<int>* root, int x){
    if(root->data==x){
        return true;
    }
    bool ans = false;
    for (int i = 0; i < root->children.size(); i++)
    {
        if(isPresent(root->children[i],x)){
            ans=true;
        }
        return ans;
    }    
}

/*

//[8.] Traversals
// 1. PreOrder: ROOT -> LEFT -> RIGHT
// 2. Postorder: LEFT -> RIGHT ->ROOT
/*
We use very basic recursion again here, 
for root_printing we use cout<<root->data;
for printing left side we call recursion.
for prinitng right side we call recursion again.
*/

void preOrder(treeNode<int>* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

// bs preorder ko upr neeche krna hai 
void PostOrder(treeNode<int>* root){
    if(root==NULL){
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        PostOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}

/*
[9.] Deletion:
For deleting we make a destructor in the class itself and that destuctor uses recursion to deletie the child nmodes first and then itself.*/

//The destructor is:

//  ~TreeNode(){
//         for(int i = 0; i<this->children.size(); i++){
//             delete children[i];
//         }
//     }

//[10] Questions:

/*
[a.] Count nodes with data greater than x
Q: Given a tree and an integer x, find and return the number of nodes which contains data greater than x.

Use recursion bruh
Implementation:*/

int count_nodes_larger_than_x(int x, treeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int count = 0;
    if(root->data>x){
        count++;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += count_nodes_larger_than_x(x,root->children[i]);
    }
    return count;
}

/*
[b.] Node with max child sum:
Q: Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.

First define a child_sum function to get the sum of the child nodes foe a specific root_node
Then define a max_node and put root in it.
We get a loop to get the nodes under every sub tree with largest child_sum
Now if for the node, the data is more than data of the max_node we update the value of max_node by the node returned by the child.
We finally return the max_node.
Implementation:*/

int childSum(treeNode<int>* root){
    int sum = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum+=root->children[i]->data;
    }
    return sum;
}

treeNode<int>* max_child_sum(treeNode<int>* root){
    treeNode<int>* max_node=root;
    for (int i = 0; i < root->children.size(); i++)
    {
        treeNode<int>* this_sum=max_child_sum(root->children[i]);
        if(childSum(this_sum)>childSum(max_node)){
            max_node=this_sum;
        }
    }
    return max_node;  
}

/*
[c.] Structurally identical: 
Q: Given two generic trees, return true if they are structurally identical. Otherwise return false.

Here to check if the 2 trees are structurally identical first we check if the node1->children.size()==node2->children.size() and then we will check if the sub trees of every child is identical too, if even one of them is inidentical, we return false
*/

bool isIdentical(treeNode<int>* root1, treeNode<int>* root2){
    bool truth = true;
    if(root1->children.size()!=root2->children.size()){
        truth=false;
        return truth;
    }
    for (int i = 0; i < root1->children.size(); i++)
    {
        if(!isIdentical(root1->children[i], root2->children[i])){
            truth = false;
        }
    }
    return truth;
}

/*
[d.] 
Q:Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.

We have case 1 where the root->data is more than x, in that case we already update the return_node to root;
>> In that case we will check if the children have any such min element larger than x too or not,
>If no that means root is the largest of all here and we return return_node
>If yes then we have to compare tha data of the returned node from the child and the min_Node and update it if the min_node->data > returned_node->data

We have case 2 where tha root->data is less than x, for that case, thus we update it the min_node_more _than_x from the children[0] and then continue the job.
If none has any value greater than x then we return NULL as the min_more_than_x is never updated here.
Implementation: */

treeNode<int>* getNextLargerElement(treeNode<int>* root, int x) {
    treeNode<int>* min_more_than_x=NULL;
    if(root->data>x){
        min_more_than_x=root;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        if(min_more_than_x==NULL){
            min_more_than_x=getNextLargerElement(root->children[i],x);
            continue;
        }
        if(getNextLargerElement(root->children[i],x)==NULL){
            continue;
        }
        if(min_more_than_x->data > getNextLargerElement(root->children[i],x)->data){
            min_more_than_x=getNextLargerElement(root->children[i],x);
        }
    }
    return min_more_than_x;
}

