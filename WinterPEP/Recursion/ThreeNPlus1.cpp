#include<bits/stdc++.h>

using namespace std;

int fun(int n){
    if(n==1) return 1;
    if(!(n&1)){
        return 1 + fun(n/2);
    }
    return 1 + (fun((3*n)+1));
}

int main(){
    int n; cin>>n;
    cout<<fun(n);
}