// You are using GCC
#include<iostream>
using namespace std;

void Heapify(int arr[],int index,int n)
{
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    if(left<n && arr[left]>arr[largest])
    {
        largest = left;
    }
    if(right<n && arr[right]>arr[largest])
    {
        largest = right;
    }
    if(largest!=index){
        swap(arr[index],arr[largest]);
        Heapify(arr,largest,n);
    }
}
void BuildHeap(int arr[],int n)
{
    for(int i=(n-1)/2;i>=0;i--)
    {
        Heapify(arr,i,n);
    }
}
void insert(int arr[],int data,int& n)
{
    arr[n] = data;
    int index = n;
    n++;
    while(index>0 && arr[(index-1)/2]<arr[index])
    {
        swap(arr[index],arr[(index-1)/2]);
        index = (index-1)/2;
    }
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    BuildHeap(arr,n);
    int x;
    cin>>x;
    insert(arr,x,n);
    print(arr,n);
    // 
    return 0;
}

// Sample Testcase
// Testcase 1 - Failed
// Expected Output
// 6 4 5 1 2 3 
// Output
// 6 3 5 2 1 4 