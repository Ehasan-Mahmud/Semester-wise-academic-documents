#include<iostream>
using namespace std;
namespace first_space
{
void f()
{
    cout<<"inside first space"<<endl;
}

namespace second_space
{
void f()
{
    cout<<"inside second space"<<endl;
}
}
}
using namespace first_space::second_space;
int main()
{
    f();
    return 0;

}

