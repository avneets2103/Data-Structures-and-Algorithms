#include<iostream>
using namespace std;

template<typename T>
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


BinaryTreeNode<int>* buildtreehelper(int *in,int *post,int postS,int postE,int inS,int inE){
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
    root->left=buildtreehelper(in,post,lposts,lposte,lins,line);
    root->right=buildtreehelper(in,post,rposts,rposte,rins,rine);
    return root;
}
BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return buildtreehelper(inorder,postorder,0,postLength-1,0,inLength-1);
}

