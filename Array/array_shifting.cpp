#include<iostream>
using namespace std;
void method1(int arr[],int n,int k){
    for(int i=0;i<k;i++){
        int temp=arr[n-1];
        for(int j=n-1;j>0;j--){
            arr[j]=arr[j-1];
        }
        arr[0]=temp;
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    method1(arr,5,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}