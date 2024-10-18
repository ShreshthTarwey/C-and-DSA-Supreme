#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int start,int mid,int end){
    int left = start;
    int right = mid+1;
    int index = 0;
    vector<int> temp(end-start+1);
    while(left<=mid && right<=end){
        if(arr[left]<=arr[right]){
            temp[index++] = arr[left++];
        }
        else{
            temp[index++] = arr[right++];
        }
    }
    while(left<=mid){
        temp[index++] = arr[left++];
    }
    while(right<=end){
        temp[index++] = arr[right++];
    }
    index = 0;
    while(start<=end){
        arr[start++] = temp[index++];
    }
}
void mergeSort(vector<int>& arr,int start,int end){//TC->O(nlogn)  SC->O(n)
    if(start==end){
        return;
    }

    int mid = start + (end-start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main(){
    vector<int> arr = {3,2,4,1,3};
    mergeSort(arr,0,4);
    for(int i:arr){
        cout<<i<<" ";
    }
}