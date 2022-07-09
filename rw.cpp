#include<iostream>
using namespace std;

int main(){
    char arr[]="hello";
    char arr3[]={'h','e','l','l','o'};
    char*ptr=arr;
    cout<<*ptr<<endl;
    cout<<ptr<<endl;
    cout<<arr<<endl;
    cout<<*arr<<endl;
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(arr3)<<endl;
    cout<<endl;
    int arr2[]={1,3,5,7};
    int*ptr2=arr2;
    cout<<*ptr2<<endl;
    cout<<ptr2<<endl;
    cout<<arr2<<endl;
    cout<<*arr2<<endl;
    cout<<sizeof(arr2)/sizeof(int)<<endl;
    return 0;}
