#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int kth(vector<int>&arr,int k){
    sort(arr.begin(),arr.end());
    return arr[k-1];
}
int main(){
    vector<int> arr = {-10,44,5,8,90,-4,-66,10};
    int k = 1;
    cout<<kth(arr,k);
}