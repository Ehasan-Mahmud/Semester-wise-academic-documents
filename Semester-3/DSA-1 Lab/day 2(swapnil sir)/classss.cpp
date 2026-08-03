#include<iostream>
using namespace std;

class A{
public:

    int m;
    int n;

    A(int x, int y){
        m = x; n = y;
    }

    void print(){
        cout<<"m: "<<m<<", n: "<<n<<endl;
    }
};

int main(){

    A *p = new A(3, 5);
    A x(6, 5);
    return 0;
}
