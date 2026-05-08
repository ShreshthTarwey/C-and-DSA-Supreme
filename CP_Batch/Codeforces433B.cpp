#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<long long>arr2 = arr;
    sort(arr2.begin(), arr2.end());
    vector<long long>prefix1(n);
    prefix1[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix1[i] = arr[i] + prefix1[i-1];
    }
    vector<long long>prefix2(n);
    prefix2[0] = arr2[0];
    for(int i=1;i<n;i++){
        prefix2[i] = arr2[i] + prefix2[i-1];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1){
            long long ans = 0;
            if(l-2>=0){
                ans -= prefix1[l-2];
            }
            ans+= prefix1[r-1];
            cout<<ans<<"\n";
        }
        else{
            long long ans = 0;
            if(l-2>=0){
                ans -= prefix2[l-2];
            }
            ans += prefix2[r-1];
            cout<<ans<<"\n";
        }
    }
}