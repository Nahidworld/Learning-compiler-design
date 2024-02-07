//write a program to determine whether the given input is comment line or not
#include<iostream>
#include<string>
using namespace std;

bool isComment(const string& line)
{
    if(line.length()<2)
        return false;
    if(line[0] == '/')
    {
        if(line[1] == '/'){
            return true;
        }
        else if(line[1] == '*'){
            return true;
        }
    }
}

int main()
{
    string line;
    cout << "Input Your code : ";
    getline(cin,line);


    if(isComment(line))
    {
        cout << "There is comment!"<<endl;
        if(line[1]='/'){
            cout << "This is single line comment!"<<endl;
        }
        else if (line[1]='*'){
            cout << "This is multiple line comment!"<<endl;
        }

    }
    else
    {
        cout << "There is No comment!"<<endl<<endl;
    }

    return 0;
}

