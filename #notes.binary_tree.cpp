#include<iostream>
using namespace std;

/*
[1.] A binary tree is a type of tree where the number of children of a node can be either 0, 1 or 2.

Thus here we define 2 nodes by default for every node i.e. left and right
Here a node can be traversed to be NULL as left and right are by default NULL here which needs to be updated only if there is a a children in Left anf Right resp.
Thus an edge case in tree node i.e. root == NULL is here a base case for finding if a node as no children in a specific direction or not.

Also whenever calling for left->data or right->data then we first have to check if left is null or not and same for right or the program wont run and show run time error.

Implementation:*/

template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<int>* left;
    BinaryTreeNode<int>* right;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

/*
[2.] Printing normally: 

Q: We want to print like:
node:L<left>,R<right> 


Algo: 
We simply just do our task for the root node, and leave the rest of task on recursion
Implementation: */

void print_binary_tree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L: "<<root->left->data<<",";
    }
    if(root->right!=NULL){
        cout<<"R: "<<root->right->data;
    }
    cout<<endl;
    print_binary_tree(root->left);
    print_binary_tree(root->right);
}

/*
[3.] Input normally:

Q: Here using recursion the data will be taken in preorder fashion which can be approached only by someone wo knows recursion and not general people

Algo:
We take input for root node and if data entered is -1 implies that the sepecific node is NULL
*/

BinaryTreeNode<int>* takeInput(){
    int root_data;
    cout<<"Enter data:"<<endl;
    cin>>root_data;
    if(root_data==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(root_data);
    BinaryTreeNode<int>* left = takeInput();
    BinaryTreeNode<int>* right = takeInput();
    root->left=left;
    root->right=right;
    return root;
}

/*
[4.] Level wise Input:

<Note: No recursion used>
Algo: We here do the same thing as in trees where we made a queue and kept adding,

*/

#include<queue>
BinaryTreeNode<int>* takeInput_level(){
    int root_data;
    cout<<"Enter root data: "<<endl;
    cin>>root_data;
    if(root_data==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(root_data);
    queue<BinaryTreeNode<int>*> unused;
    unused.push(root);
    while (unused.size()!=0)
    {
        BinaryTreeNode<int>* front = unused.front();
        unused.pop();
        cout<<"Enter data of left child of "<<front->data<<endl;
        int left_data;
        cin>>left_data;
        BinaryTreeNode<int>* left_child=new BinaryTreeNode<int>(left_data);
        cout<<"Enter data of right child of "<<front->data<<endl;
        int right_data;
        cin>>right_data;
        BinaryTreeNode<int>* right_child=new BinaryTreeNode<int>(right_data);
        front->left=left_child;
        front->right=right_child;
    }
    return root;
}

/*
[5.] Level wise printing: 

Algo: Here we again use a queue for this type of level printing, 
Implementataion: */

void print_binary_tree_level_wise(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> unprinted;
    unprinted.push(root);
    while(unprinted.size()!=0){
        BinaryTreeNode<int>* front = unprinted.front();
        unprinted.pop();
        cout<<front->data<<": ";
        if(front->left!=NULL){
            cout<<"L"<<front->left->data<<" ";
        }
        if(front->right!=NULL){
            cout<<"R"<<front->right->data;
        }
        cout<<endl;
    }
}

/*
[6.] Construct Tree:

    1
   / \
  2   3
 /   / \
4   5   6
Inorder: 4 2 1 5 3 6
PreOrder: 1 2 4 3 5 6  
PostOrder: 4 2 5 6 3 1 

[a.] Using InOrder and PreOrder:
1. First we find the root of the tree as it is the first element of the PreOrder array
2. Then to find the size of the left side we search the root in the InOrder and find root_index
3. Size of right side of root is Inorder_end - root_index
4. For using recursion we have to provide the PreOrder of the left side and right side and Inorder of the left side and right side respectively

Implementation:*/
BinaryTreeNode<int>* constructTree1(int* pre, int preS, int preE ,int* in, int inS, int inE){
    if(inS>inE || preS>preE){
        return NULL;
    }
    int root_data=pre[preS];
    int root_index;
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(root_data);
    for (int i = inS; i <= inE; i++)
    {
        if(in[i]==root_data){
            root_index=i;
        }
    }
    int LpreS=preS+1;
    int LpreE=preS+(root_index-inS);
    int LinS=inS;
    int LinE=root_index-1;
    int RpreS=preS+(root_index-inS)+1;
    int RpreE=preE;
    int RinS=root_index+1;
    int RinE=inE;

    root->left = constructTree1(pre,LpreS,LpreE,in,LinS,LinE);
    root->right = constructTree1(pre,LpreS,LpreE,in,RpreS,RpreE);
    return root;
}

/*
[b.] Using Inorder and PostOrder:
1. First we find the root_data as it is the end of the PostOrder or pre[preE]
2. Then we search for the root_data in the inorder
3. Then we find the length of the left side using root_index from inorder
4. Then we find the length of the right side using root_index and left_length

Implementation:*/

BinaryTreeNode<int>* constructTree2(int* post, int postS ,int postE ,int* in, int inS ,int inE){
    if(postS>postE)return NULL;
    int rootData=post[postE];
    int rootIndex=-1;
    for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}

    int lposts=postS;
    int lposte=postS+rootIndex-inS-1;
    int lins=inS;
    int line=rootIndex;
    int rposts=postS-inS+rootIndex;
    int rposte=postE-1;
    int rins=rootIndex+1;
    int rine=inE;
    BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
    root->left=constructTree2(post,lposts,lposte,in,lins,line);
    root->right=constructTree2(post,rposts,rposte,in,rins,rine);
    return root;
}

/*
[7.] Diameter of a binary tree:
It refers to the longest path available between 2 nodes.
This can be in 3 cases:
1. Left subtree has those 2 nodes and thus diameter is dependent only on left subtree
2. Right subtree has those 2 nodes and this diameter is dependent only on right subtree
3. Both farthest nodes are in the other subtrees, thus diameter is height1+height2
*/
int height(BinaryTreeNode<int>* root);
int diameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return max(max(diameter(root->left),diameter(root->right)),height(root->left)+height(root->right));
}

//This is of time complexity: nh
//Although here is a problem as we have to call every node twice for 2 different outputs and we arent returning a pair rather than int
//Thus we need a better approach

pair<int,int> diameter_pair(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }

    pair<int,int> left = diameter_pair(root->left);
    pair<int,int> right = diameter_pair(root->right);
    pair<int,int> return_pair;
    return_pair.second=max(max(left.second,right.second),left.first+right.first);
    return_pair.first=max(left.first,right.first)+1;
    return return_pair;
}

/*
[8.] Basic problems for binary trees:

[a.] Count nodes:
Implementation: */

int countNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

/*
[b.] IsNodePresent:
Implementation:*/

bool isPresent(BinaryTreeNode<int>* root, int x){
    bool ans = false;
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    if(isPresent(root->left,x) || isPresent(root->right,x))
    {
        ans=true;
    }
    return ans;
}

/*
[c.] Height: 
Implementation:*/

int height(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

/*
[d.] Mirorred BT:
Implementation:*/

void mirrorBinaryTree(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    swap(root->left,root->right);
}

/*
[e.] Inorder, Preorder, Postorder:
InOrder: Left->Root->Right
PreOrder: Root->Left->Right
PostOrder: Left->Right->Root
*/

void InOrder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void PreOrder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" "; 
}

/*
[f.] Check if balanced:
Implementation:*/

bool isBalanced(BinaryTreeNode<int>* root){
    if(root==NULL){
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return (height(root->left)==height(root->right)) &  isBalanced(root->left) & isBalanced(root->right); 
}

/*
[9.]Questions:

[1.] Q1:For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion and a single space will separate them. 

eg:
If tree:
    10
   /  \
  20  30
 /  \   \
40  50  60

Output: 
10
20 30
40 50 60
*/

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pn;

    pn.push(root);
    pn.push(NULL);

    while (pn.size() != 0)
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();

        if (front == NULL)
        {
            if (pn.size() == 0)
                break;
            cout << endl;
            pn.push(NULL);
        }

        else
        {
            cout << front->data << " ";

            if (front->left)
                pn.push(front->left);
            if (front->right)
                pn.push(front->right);
        }
    }
}

/*
[2.] Deleting all present leaf nodes:
Given a binary tree, remove all leaf nodes from it. Leaf nodes are those nodes, which don't have any children.
Note:
1. Root will also be a leaf node if it doesn't have left and right child. 
2. You don't need to print the tree, just remove all leaf nodes and return the updated root.

Implementation: */
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }
    root->left=removeLeafNodes(root->left);
    root->right=removeLeafNodes(root->right);
    return root;
}

/*
[3.] Print nodes without sibling:
For a given Binary Tree of type integer, print all the nodes without any siblings.

Implementation:
*/

void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    if(root->left==NULL && root->right!=NULL){
        cout<<root->right->data<<" ";
    }
    if(root->right==NULL && root->left!=NULL){
        cout<<root->left->data<<" ";
    }
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

/*
[4.] Max-Min
*/

/*
[5.] Zig Zag tree
*/

/*
[6.] Linked list tree
*/