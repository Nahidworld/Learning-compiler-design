#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//delimiter check
bool isDelimiter(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

//operator check
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=';
}

//punctuation check
bool isPunctuation(char ch) {
    return ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';' || ch == '[' || ch == ']';
}

//keyword check
bool isKeyword(const string& str) {
    const char* keyword[] = {"int", "char", "float", "double", "if", "else", "for", 
                            "while", "do", "switch", "case", "break", "continue", 
                            "return", "void", "class"};
    const int totalKeyword = sizeof(keyword) / sizeof(keyword[0]); 
    
    for (int i = 0; i < totalKeyword; ++i) {
        if (str == keyword[i]) {
            return true;
        }
    }
    
    return false;
}

//header check
bool isHeader(const string& str) {
    return str == "#include";
}

// Function to tokenize a line of code
void tokenize(const string& line) {
    string token;
    bool inString = false;

    for (char ch : line) {
        if (isDelimiter(ch) && !inString) {
            if (!token.empty()) {
                if (isKeyword(token)) {
                    cout << "Keyword: " << token << endl;
                } else if (isHeader(token)) {
                    cout << "Header: " << token << endl;
                } else if (token == "itn") {
                    cout << "Keyword: int" << endl;
                } else {
                    cout << "Identifier: " << token << endl;
                }
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
        if (isKeyword(token)) {
            cout << "Keyword: " << token << endl;
        } else if (isHeader(token)) {
            cout << "Header: " << token << endl;
        } else if (token == "itn") {
            cout << "Keyword: int" << endl;
        } else {
            cout << "Identifier: " << token << endl;
        }
    }
}

// Function to perform lexical analysis on a source file
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
    string filename = "lex_input.txt.txt";
    lexicalAnalysis(filename);
    return 0;
}
