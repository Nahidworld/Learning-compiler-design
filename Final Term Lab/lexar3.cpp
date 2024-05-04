//lexar
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// delimiter check
bool isDelimiter(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

// operator :
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=';
}

// is punctuation :
bool isPunctuation(char ch) {
    return ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';' || ch == '[' || ch == ']';
}

// keyword check
bool isKeyword(const string& str) {
    const char* keywords[] = {"int", "char", "float", "double", "if", "else", "for", 
                            "while", "do", "switch", "case", "break", "continue", 
                            "return", "void", "class"};
    const int numOfKeywords = sizeof(keywords) / sizeof(keywords[0]);  //(total size/size of one element)
    
    for (int i = 0; i < numOfKeywords; ++i) {
        if (str == keywords[i]) {
            return true;
        }
    }
    
    return false;
}


// tokenizing a line of code
void tokenize(const string& line) {
    string token;
    bool inString = false;

    for (char ch : line) {
        if (isDelimiter(ch) && !inString) {
            if (!token.empty()) {
                if (isKeyword(token)) {
                    cout << "Keyword: " << token << endl;
                } else {
                    cout << "Token: " << token << endl;
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
        } else {
        }
    }
}

// lexar
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
