#include<bits/stdc++.h>

using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        int xi;
        cin>>xi;
        for(int j=0;j<xi;j++){
            int bulb;
            cin>>bulb;
            st.insert(bulb);
        }
    }
    if(st.size()>=m){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}