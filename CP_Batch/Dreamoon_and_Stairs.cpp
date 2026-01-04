#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    if(n<m){
        cout<<-1;
        return 0;
    }
    if(n==m){
        cout<<n;
        return 0;
    }
    int step = 0;
    while(n>0){
        if(n%2!=0){
            step+=1;
            n-=1;
            // continue;
        }
        if(((n/2)+step)%m!=0){
            step+=2;
            n-=2;
        }
        else{
            step += n/2;
            cout<<step;
            return 0;
        }
    }
    return -1;
}