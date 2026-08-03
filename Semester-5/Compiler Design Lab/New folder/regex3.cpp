#include <iostream>
using namespace std;
int main()
{
	string str;
	cout<<"Enter a string (pattern: (ab)*aba): ";
	getline(cin, str);
    bool is_valid = true;
    int len = str.size();

    if(str[len-1]=='a' && str[len-2]=='b' && str[len-3]=='a');
    else is_valid = false;

    int i=0;
    if(str[i]=='a' && str[i+1]=='b'){
        while(str[i]=='a'&& str[i+1]=='b') i += 2;
    }
    i++;

    if(i != str.size()) is_valid = false;

	if(is_valid) cout << "valid\n";
	else cout << "Invalid\n";
	return 0;
}


