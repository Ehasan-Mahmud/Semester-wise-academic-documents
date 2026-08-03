#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {
    string filename = "a.c";
    ifstream file(filename);

    if(!file.is_open()){
        cout<<"Invalid File"<<endl;
        return 1;
    }
    int t_cmnt = 0;
    string line;
    bool flag = false;

    while (getline(file, line)) {
        size_t pos;

        if (flag) {
            pos = line.find("*/");
            if (pos != string::npos){
                flag = false;
                line = line.substr(pos + 2);
            }
        }

        pos = line.find("//");
        if (pos != string::npos) {
            t_cmnt++;
            line = line.substr(0, pos);
        }

        pos = line.find("/*");
        if (pos != string::npos){
            t_cmnt++;
            flag = true;
            size_t endPos = line.find("*/", pos + 2);
            if (endPos != string::npos) {
                flag = false;
            }
        }
    }

    file.close();
    cout<<t_cmnt<<endl;
    return 0;
}
