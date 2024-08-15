#include<iostream>
using namespace std;
void method1(int arr[],int n){//TC=O(n) SC=O(1)
    for(int i=0;i<n;i++){
        arr[i]=~(arr[i]) & 1;
    }
}
void method2(int arr[],int n){//TC=O(n) SC=O(1)
    for(int i=0;i<n;i++){
        arr[i]=arr[i]^1;
    }
}
void method3(int arr[],int n){//TC=O(n) SC=O(1)
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            arr[i]=1;
        }
        else{
            arr[i]=0;
        }
    }
}
int main(){
    int arr[]={0,1,1,0,0,1,1,0,1,0,0};
    // method1(arr,11);
    // method2(arr,11);
    method3(arr,11);
    for(int i=0;i<11;i++){
        cout<<arr[i]<<" ";
    }
}