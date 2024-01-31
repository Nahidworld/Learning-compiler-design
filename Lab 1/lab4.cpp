///write a program to calculate the factorial of the given number (using loop)
#include<iostream>
using namespace std;

//Factorial function
double findFactorial(int number) {
    long fact = 1;

    //factorial value
    for (int i = number; i > 1; i--) {
        fact = fact * i;
    }
    return fact;
}
int main() {
    int num;
    // take input
    do {
        cout << "Enter a positive integer: ";
        cin >> num;

        if (num <= 0) {
            cout << "Please enter a positive integer." << endl;
        }
    } while (num <= 0);

    // display result
    cout << "Factorial = " << findFactorial(num) << endl;

    return 0;
}


