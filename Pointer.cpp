#include<iostream>

using namespace std;

int main(){
    int *ptr;
    ptr = new int;
    delete ptr;
    *ptr = 5;
    cout<<*ptr;
    return 0;
}