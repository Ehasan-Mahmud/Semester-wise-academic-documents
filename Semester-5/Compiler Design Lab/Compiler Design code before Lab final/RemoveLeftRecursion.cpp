#include <bits/stdc++.h>
using namespace std;

int main()
{
    string prod, left = "", right = "";
    cout << "Enter a production rule: " << endl;
    getline(cin, prod);
    prod += '\n';

    for (int i = 0; i < prod.size() - 1;) {
        if (prod[i] == '-' && prod[i + 1] == '>') {
            i += 2;
            while (prod[i] != '\n') {
                right += prod[i];
                i++;
            }
        }
        else {
            left += prod[i];
            i++;
        }
    }

    vector<string> alts;
    stringstream ss(right);

    while (ss.good()) {
        string t;
        getline(ss, t, '|');
        alts.push_back(t);
    }

    string noLR = "", leftRe = "";
    bool hasLR = false;

    for (int i = 0; i < alts.size(); i++) {
        if (left[0] == alts[i][0]) {
            hasLR = true;
            string suf = "";
            for (int j = 1; j < alts[i].size(); j++)
                suf += alts[i][j];

            if (leftRe.size() == 0) leftRe = left + "'" + "->" + suf + left + "'";
            else leftRe = leftRe + "|" + suf + left + "'";
        }
        else {
            if (noLR.size() == 0) noLR = left + "->" + alts[i] + left + "'";
            else noLR = noLR + "|" + alts[i] + left + "'";
        }
    }

    leftRe += "|eps";

    if (!hasLR) cout << "There is no left recursion" << endl;
    else {
        cout << noLR << endl;
        cout << leftRe << endl;
    }
}



///E->E+T|T
///A->Aa|Ab|c


