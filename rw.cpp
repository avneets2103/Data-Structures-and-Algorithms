#include<iostream>
using namespace std;
   
int sumOfDigits(int n) 
{
    //base
    if (n==0)
    {
        return 0;
    }
    return n%10 + sumOfDigits(n/10);    
}

int main(){
    int m;
    cout<<"Enter m: "<<endl;
    cin>>m;
    cout<<sumOfDigits(m);
    return 0;}
