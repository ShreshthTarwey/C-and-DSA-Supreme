#include<iostream>
using namespace std;
void bin(int n){
    if(n>1) bin(n/2);
    cout<<n%2;
}
int main(){
    int n;
    cin>>n;
    bin(n);
    return 0;
}