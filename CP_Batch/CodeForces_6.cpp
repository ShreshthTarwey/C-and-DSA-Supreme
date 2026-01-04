#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        bool hasOdd = false;
        bool hasEven = false;
        for(int i=0;i<n;i++){
            cin>>arr[i];
           if((arr[i]&1) && hasOdd==false){
            hasOdd = !hasOdd;
           }
           else if((arr[i]&1)==0 && hasEven==false){
            hasEven = !hasEven;
           }
        }
        if(hasOdd && hasEven){
            sort(arr.begin(),arr.end());
        }
        
        for(auto it:arr){
            cout<<it<<" ";
        }
        cout<<endl;

    }
}