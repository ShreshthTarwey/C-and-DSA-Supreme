#include<iostream>
using namespace std;

class llnode {
public:
    int fun(int x, int y, int z);  // No default values
};
int llnode::fun(int x=0, int y=0, int z=0) {
    return x + y+z;
}





int main() {
    int z=10;
    llnode obj;
    cout<<obj.fun(z);
    return 0;
}
