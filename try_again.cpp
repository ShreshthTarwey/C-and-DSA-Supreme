#include<iostream>
using namespace std;
int cyclic(int arr[],int n,int k){
    int finalShift=k%n;
    int temp[10000];
    int index=0;
    for(int i=n-finalShift;i<n;i++){
        temp[index++]=arr[i];
    }
    for(int i=n-1;i>=0;i--){
        if(i-finalShift>=0){
        arr[i]=arr[i-finalShift];}
    }
    for(int i=0;i<finalShift;i++){
        arr[i]=temp[i];
    }
}
int main(){
    int arr[]={1,2,3,4,5,6};
    cyclic(arr,6,5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}