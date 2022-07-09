#include<iostream>
using namespace std;

class complex{
    private:
    int real;
    int img;

    public:
    complex(int real,int img){
        this->real=real;
        this->img=img;
        cout<<"complex number stored as: "<<real<<" + "<<img<<"i"<<endl;
    }
    void add(complex c){
        real=real+c.real;
        img=img+c.img;
        cout<<"Addition success"<<endl;
    }
    void multiply(complex f){
        real=real*f.real-img*f.img;
        img=real*f.img+f.real*img;
    }
    void display(){
        cout<<real<<" + "<<img<<"i"<<endl;
        cout<<"Multiplication success"<<endl;
    }
};

int main(){
    complex c1(3,5),c2(4,-4);
    complex c3(3,5);
    c1.add(c2);
    c1.display();
    c3.multiply(c2);
    c3.display();
    return 0;}
