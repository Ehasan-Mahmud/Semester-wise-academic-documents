#include<bits/stdc++.h>
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
int main() {
    int count=0;
    string filename="binput.c";
    ifstream file(filename);
    if (!file.is_open()) {
        cout<<"Error opening the (binput.c) File.\n";
        return 1;
    }

    stack<char> s;
    string line;

    bool balanced=true;
    while (getline(file,line)) {
        for (size_t i=0;i<line.size();++i) {
            char c=line[i];


            if (isOpening(c)) {
                s.push(c);
            }
            else if (isClosing(c)) {
                if (s.empty() || !matches(s.top(), c)) {
                    balanced=false;
                    break;
                }
                s.pop();
            }
        }
    }

    if (!s.empty()) {
        balanced= false;
    }

    if (balanced) {
        cout<<"All PARENTHESIS are BALANCED.\n";
    } else {
        cout << "Parentheses are NOT BALANCED.\n";
    }
    ///cout<<count<<endl;

    file.close();
    return 0;
}

