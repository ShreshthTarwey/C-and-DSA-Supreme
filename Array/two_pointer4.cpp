#include<iostream>
using namespace std;
void two_pointer(int arr[],int size){
    int i=0;
    int j=size-1;
    while(j>=i){
        cout<<arr[i++]<<" ";
        if(j>i){
            cout<<arr[j--]<<" ";
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    two_pointer(arr,n);
}