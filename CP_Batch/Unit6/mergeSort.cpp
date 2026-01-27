#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>&arr, int start, int mid, int end){
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
    // arr = temp;
    int index = 0;
    for(int i=start;i<=end;i++){
        arr[i] = temp[index++];
    }
    return;
}

void mergeSort(vector<int>& arr, int start, int end){
    if(start>=end) return;
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
    vector<int> arr = {5,4,3,2,1};
    mergeSort(arr, 0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}