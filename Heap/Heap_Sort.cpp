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
    if(largest!=index)
    {
        swap(arr[index],arr[largest]);
        Heapify(arr,largest,n);
    }
}
void HeapSort(int arr[],int n)
{
    for(int i = n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        Heapify(arr,0,i);
    }
}
void BuildHeap(int arr[],int n)
{
    for(int i=(n-1)/2;i>=0;i--)
    {
        Heapify(arr,i,n--);
    }
}
void printHeap(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {22,50,6,9,54,4,99,105,16};
    BuildHeap(arr,9);
    printHeap(arr,9);
    HeapSort(arr,9);
    printHeap(arr,9);

}