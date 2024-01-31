/*Take two strings as your first and  last name then concatenate
the two strings together so that you can find your full name;
e.g. First name = "XX" Last name ="yy"
output: full name ="XX YY"
*/
#include<iostream>
#include<string>
using namespace std;

string firstName, lastName, fullName;

int main() {

    //first name
    cout << "Enter your first name: ";
    getline(cin, firstName);

    cout << "Enter your last name: ";
    getline(cin, lastName);

    // Concatenate
    fullName = firstName + " " + lastName;

    cout << "Full Name: " << fullName << endl;



    return 0;
}
