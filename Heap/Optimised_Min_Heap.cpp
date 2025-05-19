#include<iostream>
using namespace std;
void Heapify(int arr[],int index,int n) //Since we are using recursion SC-> O(logn), If we would have used loops it would have been O(1)
    {
        int smallest = index;
        int left = 2*index+1;
        int right = 2*index+2;
        if(left<n && arr[left]<arr[smallest]){
            smallest = left;
        }
        if(right<n && arr[right]<arr[smallest])
            smallest = right;
        if(smallest!=index){
            swap(arr[smallest],arr[index]);
            Heapify(arr,smallest,n);
        }
    }
void BuildMinHeap(int arr[],int n){ //TC-> O(n)
    //For more optimised way we will use step down approach
    
    for(int i=(n-1)/2;i>=0;i--)
    {
        Heapify(arr,i,n);
    }
}
void printHeap(int arr[],int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int arr[] = {22,50,6,9,54,4,99,105,16};
    BuildMinHeap(arr,9);
    printHeap(arr,9);
}