/*
Templates:

*/

#include<iostream>
using namespace std;

template <typename T, typename V>
class Pair{
    T x;
    V y;

    public:
    void setX(T x){
        this->x=x;
    }
    T getX(){
        return x;
    }
    void setY(V y){
        this->y=y;
    }
    V getY(){
        return y;
    }
}; 

int main(){
    Pair <int,double> p1;
    Pair <char,bool> p2;
    p1.setX(4);
    p1.setY(6.5);
    cout<<p1.getX()<<" "<<p1.getY()<<endl;
    p2.setX('c');
    p2.setY(true);
    cout<<p2.getX()<<" "<<p2.getY()<<endl;
    //TRIPLET
    Pair<int,int> p4;
    p4.setX(15);
    p4.setY(16);
    Pair <Pair<int,int> , int> p3;
    //you can do this nesting at any level too, its nt limited till here only
    p3.setY(65);
    p3.setX(p4);  
    cout<<p3.getX().getX()<<" ";
    cout<<p3.getX().getY()<<" ";
    cout<<p3.getY()<<endl;
    return 0;}
