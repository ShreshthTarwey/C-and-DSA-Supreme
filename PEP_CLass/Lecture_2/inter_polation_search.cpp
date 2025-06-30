#include<iostream>
#include<vector>
using namespace std;
int interpoltationSearch(vector<int>arr,int s,int e,int x){
    if(s<=e && x>=arr[s] && x<=arr[e]){
        int pos = s + ((x-arr[s])*(e-s))/(arr[e]-arr[s]);
        if(arr[pos]==x){
            return pos;
        }
        else if(arr[pos]>x){
            return interpoltationSearch(arr,s,pos-1,x);
        }
        else{
            return interpoltationSearch(arr,pos+1,e,x);
        }
    }
    else{
        return -1;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s = 0;
    int e = arr.size()-1;
    int x;
    cin>>x;
    cout<<interpoltationSearch(arr,s,e,x);
}