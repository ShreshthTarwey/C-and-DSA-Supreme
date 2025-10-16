#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int k;
    cin>>k;
    vector<int>result;
    while(k--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end(),greater<int>());
        sort(result.begin(),result.end(),greater<int>());
        vector<int>temp;
        int i=0;
        int j=0;
        while(i<arr.size() && j<result.size()){
            if(arr[i]>=result[j]){
                temp.push_back(arr[i++]);
            }
            else{
                temp.push_back(result[j++]);
            }
        }
        while(i<arr.size()){
            temp.push_back(arr[i++]);
        }
        while(j<result.size()){
            temp.push_back(result[j++]);
        }
        result = temp;
    }
    for(auto i:result){
        cout<<i<<" ";
    }
}