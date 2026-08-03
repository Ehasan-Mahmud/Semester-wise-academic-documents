#include <bits/stdc++.h>
using namespace std;
const int INF = 1e6;

void FloydW(int b[][3]) {
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (b[i][k] < INF && b[k][j] < INF)
                    b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << "Minimum Cost from " << i << ":\n";
        for (int j = 0; j < 3; j++) {
            if (b[i][j] == INF)
                cout << "INF ";
            else
                cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int b[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            b[i][j] = (i == j) ? 0 : INF;

    b[0][1]  = 10;
    b[1][2]  = 15;
    b[2][0]  = 12;

    FloydW(b);
    return 0;
}
