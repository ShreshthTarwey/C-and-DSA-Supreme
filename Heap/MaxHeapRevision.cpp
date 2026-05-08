#include<bits/stdc++.h>

using namespace std;

class Heap{
    int *arr;
    int size;
    int maxSize;
    public:
    Heap(int x){
        arr = new int[x];
        this->size = 0;
        this->maxSize = x;
    }
    ~Heap(){
        delete []arr;
    }
    bool isFull(){
        return size == maxSize;
    }
    bool isEmpty(){
        return size==0;
    }
    void insert(int x){
        if(isFull()){
            cout<<"Heap Overflow"<<endl;
            return;
        }
        arr[size] = x;
        size++;
        int index = size-1;
        while(index>0 && arr[(index-1)/2]<arr[index]){
            swap(arr[(index-1)/2], arr[index]);
            index = (index-1)/2;
        }
    }
    void heapifyDown(int index){
        int largest = index;
        int left = index*2 + 1;
        int right = index*2 + 2;
        if(left<size && arr[largest]<arr[left]){
            largest = left;
        }
        if(right<size && arr[largest]<arr[right]){
            largest = right;
        }
        if(largest != index){
            swap(arr[largest], arr[index]);
            heapifyDown(largest);
        }
    }
    void deletion(){
        if(size==0){
            cout<<"Heap is empty"<<endl;
            return;
        }
        if(size==1){
            size--;
            return;
        }
        swap(arr[0], arr[size-1]);
        size--;
        heapifyDown(0);
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
};


int main(){
    Heap *obj = new Heap(10);
    obj->insert(10);
    obj->insert(20);
    obj->insert(30);
    obj->insert(40);
    obj->insert(60);
    obj->insert(5000);
    obj->deletion();
    obj->print();
}