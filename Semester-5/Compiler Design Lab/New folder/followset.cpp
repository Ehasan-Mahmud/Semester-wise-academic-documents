#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string trim(const string &s) {
    int start = 0, end = s.size() - 1;
    while (start <= end && isspace(s[start])) start++;
    while (end >= start && isspace(s[end])) end--;
    return s.substr(start, end - start + 1);
}

void computeFirst(char symbol, map<char, set<char>>& first, map<char, vector<string>>& productions) {
    if (!first[symbol].empty()) return;
    if ((symbol >= 'a' && symbol <= 'z') || symbol == '(' || symbol == ')' || symbol == '+' || symbol == '*' || symbol == '-') {
        first[symbol].insert(symbol);
        return;
    }
    for (string prod : productions[symbol]) {
        prod = trim(prod);
        if (prod == "#") {
            first[symbol].insert('#');
            continue;
        }
        for (int i = 0; i < prod.size(); i++) {
            char c = prod[i];
            computeFirst(c, first, productions);
            for (char x : first[c]) {
                if (x != '#') first[symbol].insert(x);
            }
            if (first[c].count('#') == 0) break;
            if (i == prod.size() - 1) first[symbol].insert('#');
        }
    }
}

void computeFollow(map<char, set<char>>& follow, map<char, set<char>>& first, map<char, vector<string>>& productions, char startSymbol) {
    follow[startSymbol].insert('$');
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto &p : productions) {
            char A = p.first;
            for (string prod : p.second) {
                for (int i = 0; i < prod.size(); i++) {
                    char B = prod[i];
                    if (B >= 'A' && B <= 'Z') {
                        set<char> trailer;
                        if (i + 1 < prod.size()) {
                            char next = prod[i + 1];
                            if (next >= 'A' && next <= 'Z') {
                                for (char x : first[next]) {
                                    if (x != '#') trailer.insert(x);
                                }
                                if (first[next].count('#')) {
                                    for (char x : follow[A]) trailer.insert(x);
                                }
                            } else {
                                trailer.insert(next);
                            }
                        } else {
                            for (char x : follow[A]) trailer.insert(x);
                        }
                        int before = follow[B].size();
                        for (char x : trailer) follow[B].insert(x);
                        if (follow[B].size() != before) changed = true;
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    map<char, vector<string>> productions;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        char lhs = line[0];
        string rhs = line.substr(line.find("->") + 2);
        stringstream ss(rhs);
        string part;
        while (getline(ss, part, '|')) {
            productions[lhs].push_back(trim(part));
        }
    }

    map<char, set<char>> first;
    for (auto &p : productions)
        computeFirst(p.first, first, productions);

    map<char, set<char>> follow;
    computeFollow(follow, first, productions, 'S');

    for (auto &p : productions) {
        cout << "FOLLOW(" << p.first << "): ";
        for (char c : follow[p.first])
            cout << c << " ";
        cout << "\n";
    }

    return 0;
}
/*


3
S -> AB
A -> a | #
B -> b


5
S -> AB
A -> a | #
B -> bC
C -> c | #
D -> d

*/
