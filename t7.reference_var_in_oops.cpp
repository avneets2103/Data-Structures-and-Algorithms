#include<iostream>
using namespace std;

class fraction{
    int num;
    int den;
    
    public:
    fraction(int num,int den){
        this->num=num; //this operator use
        this->den=den;
    }
    void display()
    {
        cout<<num<<"/"<<den<<endl;
    }
    void add(fraction const &f){     //using refrence variable to constant value here
        num=(num*f.den + f.num*den); //num goes for f1 and f.num goes for parameterised object
        den=f.den*den;
    }

    void multiply(fraction const &f){
        num=num*f.num;
        den=den*f.den;
    }

    //for finding simplified form then we need greatest common divisor
    void simplifier(){
        int gcd=1;
        int j = min(num,den);
        for (int i = 1; i <= j; i++)
        {
            if (num%i==0 && den%i==0)
            {
                gcd=i;
            }
        }
        num=num/gcd;
        den=den/gcd;
    }
};

int main(){
    //pass by reference in objects
    fraction f1(2,10),f2(4,7);
    f1.multiply(f2);
    f1.display();
    f1.simplifier();
    f1.display();
    return 0;}
