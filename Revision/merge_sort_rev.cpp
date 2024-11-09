#include<iostream>
using namespace std;
void merge(int arr[],int start,int mid,int end){
    int temp[end-start+1];
    int l = start;
    int r = mid+1;
    int i = 0;
    while(l<=mid && r<=end){
        if(arr[l]<=arr[r]){
            temp[i++] = arr[l++];
        }
        else{
            temp[i++] = arr[r++];
        }
    }
    while(l<=mid){
        temp[i++] = arr[l++];
    }
    while(r<=end){
        temp[i++] = arr[r++];
    }
    i = 0;
    while(start<=end){
        arr[start++] = temp[i++];
    }
}
void mergeSort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
int main(){
    int arr[]={22,3,67,-9,60,-98,8};
    mergeSort(arr,0,6);
    for(auto i : arr){
        cout<<i<<" ";
    }
}