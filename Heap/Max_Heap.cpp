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
    ~Heap(){
        delete []arr;
    }
    bool isFull(){
        return (size==maxSize);
    }
    void insert(int data){//TC-> nlog(n)
        if(isFull()){
            cout<<"Heap overflow"<<endl;
            return;
        }
        arr[size] = data;
        size++;
        //Re arranging to maintain the Heap Properties
        int index = size - 1;
        while(index>0 && arr[(index-1)/2]<arr[index]){
            swap(arr[index],arr[(index-1)/2]);
            index = (index-1)/2;
        }
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    bool isEmpty(){
        return size==0;
    }
    void Heapify(int index){
        int largest = index;
        int left = 2*index+1;
        int right = 2*index+2;
        if(left<size && arr[largest]<arr[left]){
            largest = left;
        }
        if(right<size && arr[largest]<arr[right]){
            largest = right;
        }
        if(largest!=index){
            swap(arr[largest],arr[index]);
            Heapify(largest);
        }
    }
    void Delete(){//  TC->log(n)
        if(isEmpty()){
            cout<<"Heap Underflow"<<endl;
            return;
        }
        cout<<arr[0]<<"Has been deleted"<<endl;
        swap(arr[0],arr[size-1]);
        size--;
        if(size==0) return;
        Heapify(0);
    }
};
int main(){
    Heap obj(10);
    obj.insert(10);
    obj.insert(20);
    obj.insert(30);
    obj.insert(40);
    obj.insert(50);
    // obj.Delete();
    // obj.Delete();
    // obj.Delete();
    // obj.Delete();
    // obj.Delete();
    // obj.Delete();
    // obj.insert(50);
    // obj.Delete();
    obj.print();
}