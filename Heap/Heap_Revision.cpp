#include<iostream>
using namespace std;
class Heap{
    int *arr;
    int size;
    int maxSize;
    public:
    Heap(int x){
        arr = new int[x];
        size=0;
        maxSize = x;
    }
    bool isFull(){
        return (size==maxSize);
    }
    void insert(int data)
    {
        if(isFull()){
            cout<<"Heap Overflow"<<endl;
            return;
        }
        cout<<data<<" is inserted"<<endl;
        arr[size++] = data;
        int index = size-1;
        while(index>0 && arr[(index-1)/2]<arr[index])
        {
            swap(arr[(index-1)/2],arr[index]);
            index = (index-1)/2;
        }
    }
    bool isEmpty()
    {
        return size==0;
    }
    void Heapify(int arr[],int index,int size)
    {
        int largest = index;
        int left = 2*index+1;
        int right = 2*index+2;
        if(left<size && arr[left]>arr[largest])
        {
            largest = left;
        }
        if(right<size && arr[right]>arr[largest])
        {
            largest = right;
        }
        if(largest!=index)
        {
            swap(arr[largest],arr[index]);
            Heapify(arr,largest,size);
        }
    }
    void Delete()
    {
        if(isEmpty()){
            cout<<"Heap Underflow"<<endl;
            return;
        }
        if(size==1)
        {
            return;
        }
        cout<<arr[0]<<" got deleted"<<endl;
        swap(arr[0],arr[size-1]);
        size--;
        Heapify(arr,0,size);
    }
    void printHeap()
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    int arr1[] = {22,50,6,9,54,4,99,105,16};
    Heap obj(9);
    for(int i=0;i<9;i++)
    {
        obj.insert(arr1[i]);
    }
    obj.printHeap();
}