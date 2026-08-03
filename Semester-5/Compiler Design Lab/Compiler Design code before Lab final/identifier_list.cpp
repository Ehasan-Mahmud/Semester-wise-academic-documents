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
    for (size_t i = 0; i < token.size(); ++i) {
        if (token[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!isdigit(token[i])) {
            return false;
        }
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

void classifyTokens(const vector<string>& tokens) {
    set<string> foundKeywords, foundIdentifiers, foundConstants, foundOperators;

    for (const string& token : tokens) {
        if (isKeyword(token)) {
            foundKeywords.insert(token);
        } else if (isOperator(token)) {
            foundOperators.insert(token);
        } else if (isNumber(token)) {
            foundConstants.insert(token);
        } else if (isIdentifier(token)) {
            foundIdentifiers.insert(token);
        }
    }


    cout << "Identifier: ";
    for (const auto& i : foundIdentifiers) {
            if(i=="main") continue;
            cout << i << ", ";}

    cout << endl;

    cout << "Operator: ";
    for (const auto& o : foundOperators) cout << o << ", ";
    cout << endl;

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
            ++i;
            continue;
        }

        if (isdigit(c)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }

            string number;
            bool hasDot = false;

            while (i < line.size() && (isdigit(line[i]) || line[i] == '.')) {
                if (line[i] == '.') {
                    if (hasDot) break;
                    hasDot = true;
                }
                number += line[i];
                ++i;
            }

            tokens.push_back(number);
            continue;
        }

        if (isalpha(c) || c == '_') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }

            string word;
            while (i < line.size() && (isalnum(line[i]) || line[i] == '_')) {
                word += line[i];
                ++i;
            }

            tokens.push_back(word);
            continue;
        }

        if (ispunct(c)) {
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

            if (isOperator(op)) {
                tokens.push_back(op);
            }

            ++i;
            continue;
        }

        ++i;
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    ifstream file("input.c");
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

    classifyTokens(allTokens);
    file.close();
    return 0;
}

