#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[],int size,int index){
    if(index==size){
        return true;
    }
    if(arr[index-1]>arr[index]){
        return false;
    }
    return isSorted(arr,size,index+1);
}
int main(){
    int arr[] = {10,20,30,40,33,50,60};
    int size = 7;
    cout<<isSorted(arr,7,1);
    // int
}