#include<bits/stdc++.h>

using namespace std;


int main(){
    int n,t;
    cin>>n>>t;
    vector<int> arr(n,-1);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    //Travelling to cells
    int i=0;
    while(i!=n-1 ){
        if(i==t-1){
            cout<<"YES";
            return 0;
        }
        if(i==0){
            i = i+arr[i];
        }
        else
        i = i+arr[i];
    }
    if(i==t-1) cout<<"YES";
    else
    cout<<"NO";
    return 0;
}