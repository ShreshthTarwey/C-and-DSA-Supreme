#include<iostream>
using namespace std;
void rotateArray(int arr[],int n,int shift){
    int finalShift=shift%n;
    if(finalShift==0){
        return;
    }
    int temp[10000];
    int index=0;
    for(int i=n-finalShift;i<n;i++){
        temp[index++]=arr[i];
    }
    for(int i=n-1;i>=finalShift;i--){
        arr[i]=arr[i-finalShift];
    }
    for(int i=0;i<finalShift;i++){
        arr[i]=temp[i];
    }
}
int main(){
    int arr[]={1,2,3,4,5,6};
    rotateArray(arr,6,4);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}