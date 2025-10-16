#include<iostream>
#include<vector>
using namespace std;

void heapifyDown(vector<int> &arr, int n,int i){
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;
    int largest = i;
    if(leftChild<n && arr[largest]>arr[leftChild]){
        largest = leftChild;
    }
    if(rightChild<n && arr[largest]>arr[rightChild]){
        largest = rightChild;
    }
    swap(arr[i],arr[largest]);

}
void heapifyUp(vector<int> &arr, int n){
    while(n>0){
        int parent = (n-1)/2;
        if(arr[parent]<arr[n]){
            swap(arr[parent],arr[n]);
        }
        n = parent;
    }

}
void heapSort(vector<int>& arr){
    int n = arr.size();
    for(int i = (n/2)-1;i>=0;i--){
        heapifyDown(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapifyDown(arr,i,0);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int index = arr.size()-1;
    // // for(int i=index;i>=0;i--)
    // // heapifyUp(arr,i);
    
    // heapifyDown(arr,0);
    // for(int i:arr){
    //     cout<<i<<" ";
    // }
    heapSort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
}