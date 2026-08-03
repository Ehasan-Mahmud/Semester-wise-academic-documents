#include <bits/stdc++.h>
using namespace std;
class X {
private:
    int y;
    vector<list<int>>z;

    int a(int b) {
        return b%y;
    }
public:
    X(int c):y(c) {
        z.resize(y);
    }

    void p(int d) {
        int e=a(d);
        z[e].push_back(d);
    }
    void q() {
        for (int f=0;f<y;++f) {
            cout << "T " <<f<< ": ";

            if (z[f].empty()) {
                cout<<"EMPTY";
            }
            else {
                for (auto g=z[f].begin();g!=z[f].end();++g) {
                    cout << *g;
                    if (next(g)!=z[f].end()) {
                        cout<<" -> ";
                    }
                }
                if (z[f].size()>1) {
                    cout<<" (V)";
                }
            }
            cout<<endl;
        }
    }
};
int main() {
    vector<int>h={10,22,37,40,52,64,77,88,99,110};
    X i(10);

    for (int j:h) {
        i.p(j);
    }
    cout<<"Final:"<<endl;
    i.q();
    return 0;
}
