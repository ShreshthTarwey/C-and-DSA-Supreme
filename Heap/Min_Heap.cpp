#include<iostream>
using namespace std;
class Heap{
    int *arr;
    int size;
    int maxSize;
    public:
    Heap(int x)
    {
        arr = new int[x];
        size=0;
        maxSize = x;
    }
    ~Heap(){
        delete [] arr;
    }
    bool isFull()
    {
        return size==maxSize;
    }
    void insert(int data){
        if(isFull()){
            cout<<"Heap Overflow"<<endl;
            return;
        }
        arr[size++] = data;
        int index = size-1;
        while(index>0 && arr[(index-1)/2]>arr[index]){
            swap(arr[(index-1)/2],arr[index]);
            index = (index-1)/2;
        }
    }
    bool isEmpty()
    {
        
    }
}