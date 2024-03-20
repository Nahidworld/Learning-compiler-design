#include<iostream>
using namespace std;

bool isValid(string s) {
    if (!(s[0] >= 'a' && s[0] <= 'z') && !(s[0] >= 'A' && s[0] <= 'Z') && s[0] != '_') {
        cout << "First character is not a letter or underscore\n";
        return false;
    }

    for (int i = 1; i < s.length(); ++i) {
        char ch = s[i];
        if (!(ch >= 'a' && ch <= 'z') && !(ch >= 'A' && ch <= 'Z') && !(ch >= '0' && ch <= '9') && ch != '_') {
            cout << "Contains special characters\n";
            return false;
        }
    }

    return true;
}

int main() {
    string var;
    cout << "Give Input: ";
    getline(cin, var);

    if (isValid(var)) {
        cout << "Your input is valid!\n\n";
    } else {
        cout << "Your input is invalid!\n\n";
    }

    return 0;
}


