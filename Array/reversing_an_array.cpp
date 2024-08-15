#include<iostream>
#include<algorithm>
using namespace std;
void reverseArray(int arr[],int size){
    int i=0,j=size-1;
    while(j>=i){
        // if(i==j){
        //     break;
        // }
        swap(arr[i++],arr[j--]);
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element number" <<i<<endl;
        cin>>arr[i];
    }
    // Using reverse function from algorithm library
    int size=sizeof(arr)/sizeof(arr[0]);
    reverse(arr,arr+size);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}