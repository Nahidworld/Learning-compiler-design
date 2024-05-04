#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isDelimiter(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=';
}

bool isPunctuation(char ch) {
    return ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';' || ch == '[' || ch == ']';
}

void tokenize(const string& line) {
    string token;
    bool inString = false;

    for (char ch : line) {
        if (isDelimiter(ch) && !inString) {
            if (!token.empty()) {
                cout << "Token: " << token << endl;
                token.clear();
            }
        } else if (isOperator(ch) && !inString) {
            if (!token.empty()) {
                cout << "Token: " << token << endl;
                token.clear();
            }
            cout << "Operator: " << ch << endl;
        } else if (isPunctuation(ch) && !inString) {
            if (!token.empty()) {
                cout << "Token: " << token << endl;
                token.clear();
            }
            cout << "Punctuation: " << ch << endl;
        } else {
            if (ch == '"') {
                inString = !inString;
            }
            token += ch;
        }
    }

    if (!token.empty()) {
        cout << "Token: " << token << endl;
    }
}

void lexicalAnalysis(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    int lineNumber = 0;

    cout << "Input Source File: " << filename << endl << endl;
    cout << "Lexical Analysis Report:" << endl;
    cout << "------------------------" << endl << endl;

    while (getline(file, line)) {
        lineNumber++;
        cout << "Line " << lineNumber << ":" << endl;
        tokenize(line);
        cout << endl;
    }

    cout << "------------------------" << endl;
    cout << "End of Lexical Analysis Report." << endl;
}

int main() {
    string filename = "source.txt";
    lexicalAnalysis(filename);
    return 0;
}
