#include<bits/stdc++.h>

using namespace std;



int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int index = -1;
    int i=0;
    int j=0;
    int sum = 0;
    int ans = INT_MAX;
    while(j<n){
        sum+=arr[j];
        if(j-i+1==k){
            if(sum<ans){
                ans = sum;
                index = i+1;
            }
            sum -= arr[i];
            i++;
        }
        j++;
    }
    cout<<index;
}