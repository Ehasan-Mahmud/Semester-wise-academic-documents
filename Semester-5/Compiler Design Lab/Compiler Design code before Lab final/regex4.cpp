#include <iostream>
using namespace std;
int main()
{
	string str;
	cout<<"Enter a string (pattern: (a|b)*b(a|b)*): ";
	getline(cin, str);
    bool is_valid = true;
    int len = str.size();
    int c;
    for(c=0; c<str.size(); c++){
        if(str[c]=='b') break;
    }
    if(c == str.size()) is_valid=false;

    int i=0;
    if(str[i]=='a' || str[i]=='b'){
        while(str[i]=='a'|| str[i]=='b') i++;
    }

    if(i != str.size()) is_valid = false;

	if(is_valid) cout << "valid\n";
	else cout << "Invalid\n";
	return 0;
}


