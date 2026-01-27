#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int start, int mid, int end){
    vector<int>temp;
    int i = start;
    int j = mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }
    int index = 0;
    for(int i=start;i<=end;i++){
        arr[i] = temp[index++];
    }
    return;
}

void mergeSortIterative(vector<int>& arr){
    int n = arr.size();
    for(int curr_size = 1;curr_size<=n-1;curr_size=2*curr_size){
        for(int start = 0;start<n-1;start += 2*curr_size){
            int mid = start + curr_size - 1;
            int end = start + 2*curr_size - 1;
            mid = min(mid, n-1);
            end = min(end, n-1);
            merge(arr, start,mid,end);
        }
    }
}
int main(){
    vector<int> arr = {5,4,8,3,2,77,90,1};
    mergeSortIterative(arr);
    for(auto it: arr){
        cout<<it<<" ";
    }   
}