#include <iostream>
#include <string>
using namespace std;

bool is_Valid_String(const string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'a' && s[i] != 'b' && s[i] != 'c') {
            return false;
        }
    }

    for (int i = 0; i + 2 < s.size(); i++) {
        if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
            return true;
        }
    }

    return false;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (is_Valid_String(str))
        cout << "String matches." << endl;
    else
        cout << "String NOT match." << endl;

    return 0;
}
