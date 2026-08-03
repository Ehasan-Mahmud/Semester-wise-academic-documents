#include<bits/stdc++.h>
using namespace std;

int main()
{
    string inputProduction, leftSide = "", rightSide = "";
    cout << "Enter a production Rule: " << endl;
    getline(cin, inputProduction);
    inputProduction += '\n';

    for (int index = 0; index < inputProduction.size() - 1; ) {
        if (inputProduction[index] == '-' && inputProduction[index + 1] == '>') {
            index += 2;
            while (inputProduction[index] != '\n') {
                rightSide += inputProduction[index];
                index++;
            }
        }
        else {
            leftSide += inputProduction[index];
            index++;
        }
    }

    vector<string> rightProductions;
    stringstream ss(rightSide);

    while (ss.good()) {
        string part;
        getline(ss, part, '|');
        rightProductions.push_back(part);
    }

    string nonLeftRecursionRule, leftRecursionRule;
    bool hasLeftRecursion = false;

    for (int i = 0; i < rightProductions.size(); i++) {

        if (leftSide[0] == rightProductions[i][0]) {
            hasLeftRecursion = true;

            string suffix = "";
            for (int j = 1; j < rightProductions[i].size(); j++) {
                suffix += rightProductions[i][j];
            }

            if (leftRecursionRule.size() == 0) {
                string rule = leftSide + "'" + "->" + suffix + leftSide + "'";
                leftRecursionRule = rule;
            }
            else {
                leftRecursionRule = leftRecursionRule + "|" + suffix + leftSide + "'";
            }
        }
        else {
            if (nonLeftRecursionRule.size() == 0) {
                string rule = leftSide + "->" + rightProductions[i] + leftSide + "'";
                nonLeftRecursionRule = rule;
            }
            else {
                nonLeftRecursionRule = nonLeftRecursionRule + "|" + rightProductions[i] + leftSide + "'";
            }
        }
    }

    leftRecursionRule += "|eps";

    if (!hasLeftRecursion) {
        cout << "There is no left recursion" << endl;
    }
    else {
        cout << nonLeftRecursionRule << endl;
        cout << leftRecursionRule << endl;
    }
}


///E->E+T|T

