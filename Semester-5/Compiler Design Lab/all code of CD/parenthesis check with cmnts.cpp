#include <bits/stdc++.h>
using namespace std;

bool isOpening(char c) {
    return c=='('||c=='{'||c=='[';
}

bool isClosing(char c) {
    return c==')'||c=='}'||c==']';
}

bool matches(char open, char close) {
    return (open=='(' && close==')') ||
           (open=='{' && close=='}') ||
           (open=='[' && close==']');
}

struct Paren {
    char c;
    int line;
};

int main() {
    ifstream file("inn.c");
    if (!file.is_open()) {
        cout<<"Error opening the file.\n";
        return 1;
    }

    stack<Paren> s;
    string line;
    bool inSingleLineComment=false;
    bool inMultiLineComment=false;
    bool inString=false;
    int lineNum=0;
    bool balanced=true;

    while (getline(file,line)) {
        ++lineNum;
        for (size_t i=0;i<line.size();++i) {
            char c=line[i];

            if (!inString && !inMultiLineComment && i+1 < line.size() && line[i]=='/' && line[i+1]=='/') {
                inSingleLineComment=true;
                break;
            }

            if (!inString && !inSingleLineComment && i + 1 < line.size()) {
                if (!inMultiLineComment && line[i]=='/' && line[i+1]=='*') {
                    inMultiLineComment=true;
                    ++i;
                    continue;
                }
                if (inMultiLineComment && line[i]=='*' && line[i+1]=='/') {
                    inMultiLineComment=false;
                    ++i;
                    continue;
                }
            }

            if (inMultiLineComment || inSingleLineComment)
                continue;

            if (c=='"' && !inString) {
                inString=true;
                continue;
            } else if (c=='"' && inString) {
                inString=false;
                continue;
            }

            if (inString)
                continue;

            if (isOpening(c)) {
                s.push({c,lineNum});
            } else if (isClosing(c)) {
                if (s.empty() || !matches(s.top().c, c)) {
                    cout << "Unmatched Closing '" << c << "' at line " << lineNum << endl;
                    balanced=false;
                } else {
                    s.pop();
                }
            }
        }
        inSingleLineComment=false;
    }

    while (!s.empty()) {
        cout << "Unmatched Opening '" << s.top().c << "' at line " << s.top().line << endl;
        s.pop();
        balanced=false;
    }

    if (balanced)
        cout<<"All parentheses are BALANCED.\n";
    else
        cout<<"Parentheses are NOT BALANCED.\n";

    file.close();
    return 0;
}

