#include<iostream>
#include<cmath>
using namespace std;
int binartytodecimal(int n){
    int decimal=0;
    int i=0;
    int digit;
    while(n!=0){
        digit=n%10;
        decimal=decimal+digit*pow(2,i++); // digit+=rem*pow(base,i++)
        n/=10;
    }
    return decimal;
}
int binartytodecimal2(int n){
    int decimal=0;
    int i=0;
    int digit;
    while(n>0){
        digit=n&1;
        decimal=decimal+digit*pow(2,i++); // digit+=rem*pow(base,i++)
        n/=10;
    }
    return decimal;
}
int main(){
    int n;
    cout<<"Enter your number: "<<endl;
    cin>>n;
    cout<<"The decimal number is : "<<binartytodecimal2(n);
}