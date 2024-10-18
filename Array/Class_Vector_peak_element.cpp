#include<iostream>
#include<vector>
using namespace std;
int peak(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(i==0 || i==n-1){
            continue;
        }
        else{
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                return i;
            }
        }
    }
}
int main(){
    vector<int> a;
    a={1,2,3,4,5,6,7,6};
    cout<<peak(a);
}