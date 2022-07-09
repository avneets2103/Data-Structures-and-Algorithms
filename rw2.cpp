#include<iostream>
using namespace std;

bool ispresent(int input[],int size,int x){
    //base
    if(size==0){
        return false;
    }
    if (input[0]==x)
    {
        return true;
    }
    else{
        if (ispresent(input+1,size-1,x))
        {
            return true;
        }
        else{
            return false;
        }
        
    }
}

int main(){
    int arr[5]={2,4,62,5,3};
    cout<<ispresent(arr,5,1);
    return 0;}
