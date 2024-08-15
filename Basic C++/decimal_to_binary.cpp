#include<iostream>
#include<cmath>
using namespace std;
int decimaltoBinary(int n){
    int binary_no=0;
    int i=0;
    int digit =0;
    while(n!=0){
        digit=n%2;
        binary_no=binary_no+digit*pow(10,i++);
        n/=2;
    }
    return binary_no;
}
// Bit wise method
int decimaltoBinary2(int n){
    int binary_no=0;
    int i=0;
    int digit =0;
    while(n>0){
        digit=(n&1);
        binary_no=binary_no+digit*pow(10,i++);
        n=n>>1;
    }
    return binary_no;
}
int main(){
    int n;
    cin>>n;
    cout<<"Your binary number is:\n";
    // cout<<decimaltoBinary(n);
    cout<<decimaltoBinary2(n);

}