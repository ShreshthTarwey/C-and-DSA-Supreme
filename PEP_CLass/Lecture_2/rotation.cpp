#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int temp = arr[n-1];
        for(int i=n-1;i>0;i--){
        arr[i] = arr[i-1];    
        }
        arr[0] = temp;

    }
    
    for(auto i:arr){
        cout<<i<<" ";
    }
}