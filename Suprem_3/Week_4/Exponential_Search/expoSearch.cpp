#include<iostream>
using namespace std;
int binarySearch(int arr[],int start,int end,int x){
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]>x){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}
int expoSearch(int arr[],int n,int x){
    if(arr[0]==x) return 0;
    int i=1;
    while(i<n && arr[i]<=x){
        i*=2;
    }
    return binarySearch(arr,i/2,min(i,n),x);
}
int main(){
    int arr[] = {13,19,22,34,38,40,44,47,55};
    cout<<expoSearch(arr,9,44);
}