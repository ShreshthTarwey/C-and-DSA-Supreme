#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int maxx = 0;
    long long count = arr[arr.size()-1];
    maxx = arr[arr.size()-1];

    for(int i=arr.size()-2;i>=0;i--){
        maxx = min(maxx-1, arr[i]);
        if(maxx<0){
            maxx=0;
        }
        count+=maxx;
    }
    cout<<count;
}