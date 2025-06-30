#include<iostream>
using namespace std;
long long int fact(long long int n){
    if(n==0){
        return 1;
    }
    return n * fact(n-1);
}
int fibo(long int n){
    long int a = 0;
    long int b = 1;
    long int c = 0;
    n--;
    while(n>=1){
        a=b;
        b=c;
        c=a+b;
        n--;
    }
    return c;
}
int main(){
    cout<<"Enter a number to find fibo and fact of that number: ";
    long long int n;
    cin>>n;
    // cout<<"The "<<n<<"th fibo number is: "<<fibo(n)<<endl;
    cout<<"The fact of "<<n<<" is: "<<fact(n)<<endl;
    // printf("%lld",fact(n));
}