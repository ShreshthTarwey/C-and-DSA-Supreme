#include<iostream>
using namespace std;

int fact(int n,int acc=1){ //Tail Recursion
    if(n==0){
        return acc;
    }
    return fact(n-1,acc*n);
}

int main(){
    int n;
    cin>>n;
    cout<<fact(n);
}