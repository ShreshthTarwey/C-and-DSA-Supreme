#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxx = INT_MIN;
    int sec_max;
    for(int i=0;i<n;i++){
        if(maxx<arr[i]){
            sec_max = maxx;
            maxx = arr[i];
        }
    }
    cout<<maxx+sec_max;
}