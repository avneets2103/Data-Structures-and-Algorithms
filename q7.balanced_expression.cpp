#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expression)
{
    stack<char> s;
    int size=expression.size();
    int i = 0;
    while (i<size)
    {
        if (expression[i] == '(')
        {
            s.push(expression[i]);
        }
        if (expression[i] == ')')
        {
        if(s.size()==0){
                return false;
            }
        if(s.top()=='('){
            s.pop();    
            }
        else{
            return false;
        }
    i++;
    }
    return true;
}
}

bool isBalanced(string expression)
{
    stack<char> s;
    int size=expression.size();
    int i = 0;
    while (i<size)
    {
        if(expression[i]=='(' || expression[i]=='{')
        {
            s.push(expression[i]);
        }
        if(expression[i]==')' || expression[i]=='}')
        {
            if(s.size()==0)
            {
                return false;
            }
            if(expression[i]==')' && s.top()=='(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            if(expression[i]=='}' && s.top()=='{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    i++;
    }
    return true;
}


int main(){
    
}