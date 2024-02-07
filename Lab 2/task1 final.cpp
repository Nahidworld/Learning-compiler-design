//write a program to determine whether the given input is numeric or not
#include<iostream>

using namespace std;

bool isnumerical(const string& a)
{
    bool isNumeric = true;
    int pointCount = 0;

    for (int i = 0; i < a.length(); i++)
    {
        char ch = a[i];
        if (!(ch >= '0' && ch <= '9') && ch != '.' && ch != '-')
        {
            isNumeric = false;
            break;
        }

        if (ch == '.')
        {
            pointCount++;
        }
    }
    return isNumeric && pointCount <= 1;
}

int main()
{
    string x;
    cout << "Input Something: ";
    cin >> x;

    if (isnumerical(x))
        cout << x << " is a Numerical constant!" << endl << endl;
    else
        cout << x << " is not a Numerical constant!" << endl << endl;

    return 0;
}
