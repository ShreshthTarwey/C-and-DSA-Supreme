#include<iostream>
using namespace std;
bool isPrime(int n){
    if(n==1 || n==0){
        return false;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int m = 1;
    for(int i=0;i<=1000;i++){
        if(!isPrime(n*m+1)){
            cout<<m;
            break;
        }
        m++;
    }
}