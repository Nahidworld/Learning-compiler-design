//write a program to determine whether the given input is operator or not
#include<iostream>
using namespace std;

char op;

bool isOperator(char op)
{
    return(op == '+' || op == '-' || op == '*'|| op == '/'|| op == '%'|| op == '=' );
}

int main()
{
    string x;
    cout << "Input Something: ";
    cin >> x;

    int operatorCount = 1;
    for(int i=0; i<x.length(); i++)
    {
        char ch =x[i];
        if(isOperator(ch))
        {
            cout << "Operator " << operatorCount++ <<"th : " <<ch <<endl;
        }
    }
    cout << "Total Operator "<<operatorCount-1;
    return 0;
}

