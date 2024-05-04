#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;

bool isDelimiter(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

// bool isOperator(const string& op) {
//     return op == "+" || op == "-" || op == "*" || op == "/" || op == "%" || op == "=" ||
//            op == "<<" || op == ">>" || op == "==" || op == "!=" || op == "&&" || op == "||" || op == "!" ||
//            op == "<=" || op == ">=";
// }
bool isOperator(const string& op) {
    return op == "+" || op == "-" || op == "*" || op == "/" || op == "%" || op == "=" ||
           op == "<<" || op == ">>" || op == "==" || op == "!=" || op == "&&" || op == "||" || op == "!" ||
           op == "<=" || op == ">=";
}

bool isPunctuation(char ch) {
    return ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';' || ch == '[' || ch == ']' ||
           ch == ',' || ch == '.' || ch == ':' || ch == '`' || ch == '~';
}

bool isKeyword(const string& str) {
    const char* keyword[] = {"int", "char", "float", "double", "if", "else", "for", 
                            "while", "do", "switch", "case", "break", "continue", 
                            "return", "void", "class", "main", "const", "static", "extern", "inline",
                            "template", "typename", "namespace", "try", "catch", "throw", "volatile",
                            "true", "false"};
    const int totalKeyword = sizeof(keyword) / sizeof(keyword[0]); 
    
    for (int i = 0; i < totalKeyword; ++i) {
        if (str == keyword[i]) {
            return true;
        }
    }
    
    return false;
}

bool isHeader(const string& str) {
    const string headers[] = {"#include", "<iostream>", "<fstream>", "<string>", "<sstream>",
                              "<vector>", "<map>", "<unordered_map>", "<set>", "<unordered_set>",
                              "<algorithm>", "<cmath>", "<cstdlib>", "<ctime>", "<cstdio>", "#include <iostream>"};
    const int totalHeaders = sizeof(headers) / sizeof(headers[0]); 
    
    for (int i = 0; i < totalHeaders; ++i) {
        if (str == headers[i]) {
            return true;
        }
    }
    
    return false;
}

bool isValidIdentifier(string s) {
    if (!(s[0] >= 'a' && s[0] <= 'z') && !(s[0] >= 'A' && s[0] <= 'Z') && s[0] != '_') {
        return false;
    }

    for (int i = 1; i < s.length(); ++i) {
        char ch = s[i];
        if (!(ch >= 'a' && ch <= 'z') && !(ch >= 'A' && ch <= 'Z') && !(ch >= '0' && ch <= '9') && ch != '_') {
            return false;
        }
    }

    return true;
}

bool isConstant(const string& token) {
    stringstream ss(token);
    double val;
    ss >> val;
    return !ss.fail() && ss.eof();
}

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
                } else if (isValidIdentifier(token)) {
                    cout << "Identifier: " << token << endl;
                } else if (isConstant(token)) {
                    cout << "Constant: " << token << endl;
                } else {
                    cout << "Invalid Identifier: " << token << endl;
                }
                token.clear();
            }
        } else if (isOperator(string(1, ch)) && !inString) {
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
        } else if (isValidIdentifier(token)) {
            cout << "Identifier: " << token << endl;
        } else if (isConstant(token)) {
            cout << "Constant: " << token << endl;
        } else {
            cout << "Invalid Identifier: " << token << endl;
        }
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
    cout << "#Nahid: 22-46078-1" << endl;
}

int main() {
    string filename = "lex_input.txt.txt";
    lexicalAnalysis(filename);
    return 0;
}
