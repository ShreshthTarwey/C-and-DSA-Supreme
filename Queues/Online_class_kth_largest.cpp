#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int kth_largest(vector<int>&arr,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<arr.size();i++){
        if(pq.size()<k){
            pq.push(arr[i]);
        }
        else{
            if(pq.top()<arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }
    return pq.top();
}
int main(){
    vector<int> arr = {-10,44,5,8,90,-4,-66,10};
    int k = 6;
    cout<<kth_largest(arr,k);
}