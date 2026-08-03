#include <bits/stdc++.h>
using namespace std;

unordered_set<string> keywords = {
    "auto","break","case","char","const","continue","default","do",
    "double","else","enum","extern","float","for","goto","if",
    "inline","int","long","register","restrict","return","short",
    "signed","sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while","_Bool","_Complex","_Imaginary","main"
};

unordered_set<string> operators = {
    "+","-","*","/","%","++","--","=","==","!=","<","<=",">",">=",
    "&&","||","!","&","|","^","~","<<",">>"
};

bool isOperator(const string& token) {
    return operators.count(token);
}

bool isKeyword(const string& token) {
    return keywords.count(token);
}

bool isNumber(const string& token) {
    if (token.empty()) return false;
    bool hasDecimal = false;
    for (char c : token) {
        if (c == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!isdigit(c)) return false;
    }
    return true;
}

bool isIdentifier(const string& token) {
    if (token.empty()) return false;
    if (!isalpha(token[0]) && token[0] != '_') return false;
    for (char c : token) {
        if (!isalnum(c) && c != '_') return false;
    }
    return true;
}

vector<string> tokenize(const string& line) {
    vector<string> tokens;
    string token;
    size_t i = 0;

    while (i < line.size()) {
        char c = line[i];

        if (isspace(c)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            i++;
            continue;
        }

        if (isalnum(c) || c == '_') {
            token += c;
            i++;
            continue;
        }

        if (!token.empty()) {
            tokens.push_back(token);
            token.clear();
        }

        string op(1, c);
        if (i + 1 < line.size()) {
            string twoCharOp = op + line[i + 1];
            if (isOperator(twoCharOp)) {
                tokens.push_back(twoCharOp);
                i += 2;
                continue;
            }
        }

        if (isOperator(op)) tokens.push_back(op);
        i++;
    }

    if (!token.empty()) tokens.push_back(token);

    return tokens;
}

int main() {
    ifstream file("in.c");
    if (!file.is_open()) {
        cout << "Error opening file.\n";
        return 1;
    }

    vector<string> allTokens;
    string line;
    while (getline(file, line)) {
        vector<string> tokens = tokenize(line);
        allTokens.insert(allTokens.end(), tokens.begin(), tokens.end());
    }

    set<string> validIdentifiers, invalidIdentifiers;
    set<string> foundKeywords, foundOperators, foundConstants;

    for (string token : allTokens) {
        if (isKeyword(token)) foundKeywords.insert(token);
        else if (isOperator(token)) foundOperators.insert(token);
        else if (isNumber(token)) foundConstants.insert(token);
        else if (isIdentifier(token)) validIdentifiers.insert(token);
        else invalidIdentifiers.insert(token);
    }

    cout << "Keywords: ";
    for (auto k : foundKeywords) cout << k << " ";
    cout << "\nOperators: ";
    for (auto o : foundOperators) cout << o << " ";
    cout << "\nConstants: ";
    for (auto c : foundConstants) cout << c << " ";
    cout << "\nValid Identifiers: ";
    for (auto v : validIdentifiers) cout << v << " ";
    cout << "\nInvalid Identifiers: ";
    for (auto i : invalidIdentifiers) cout << i << " ";
    cout << endl;

    file.close();
    return 0;
}
