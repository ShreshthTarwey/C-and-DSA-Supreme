#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // priority_queue<int>pq;//Max
    // priority_queue<int, vector<int>, greater<int>>pq2;//Minn
    int minn = arr[0];
    int maxx = arr[0];
    int ans = 0;
    for(auto &it: arr){
        if(it>maxx){
            ans++;
            maxx = it;
        }
        else if(it<minn){
            minn = it;
            ans++;
        }
    }
    cout<<ans<<"\n";
}