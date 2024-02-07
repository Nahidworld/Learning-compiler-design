//write a program to determine whether the given input is numeric or not
#include<iostream>
#include<cctype>
using namespace std;

bool isnumerical(const string& a)
{
    char ch;
    {
        for (int i =0; i<a.size(); i++)
        {
            char ch = a[i];
            if (!isdigit(ch) && ch!= '.')
            {
                return false;
            }
        }
    }
    int pointCount = 0;
    for (int i =0; i<a.size(); i++)
    {
        if (ch == '.')
        {
            pointCount++;
        }
    }

    return pointCount <= 1;
}

int main()
{
    string x;
    cout << "Input Something: ";
    cin >> x;

    if (isnumerical(x))
    {
        cout <<x << " is a Numerical constant!" <<endl;
    }
    else
    {
        cout <<x << " is not a Numerical constant!" <<endl;
    }
}
