#include <iostream>
using namespace std;
int main()
{
	string str;
	cout<<"Enter a string (pattern: a*b+): ";
	getline(cin, str);
    bool is_valid = true;
    int i=0;
    if(str[i]=='a'){
        while(str[i]=='a') i++;
    }
    if(str[i]=='b'){
        while(str[i]=='b') i++;
    }
    else{
        is_valid = false;
    }
    if(i != str.size()){
        is_valid = false;
    }
	if(is_valid) cout << "valid\n";
	else cout << "Invalid\n";
	return 0;
}

