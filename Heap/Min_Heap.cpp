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
        return size==0;
    }
    void print()
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void Heapify(int index)
    {
        int smallest = index;
        int left = 2*index+1;
        int right = 2*index+2;
        if(left<size && arr[left]<arr[smallest])
        smallest = left;
        if(right<size && arr[right]<arr[smallest])
        smallest = right;
        if(smallest!=index)
        {
            swap(arr[smallest],arr[index]);
            Heapify(smallest);
        }
    }
    void Delete()
    {
        if(isEmpty()){
            cout<<"Heap Underflow"<<endl;
            return;
        }
        cout<<arr[0]<<" was deleted"<<endl;
        swap(arr[0],arr[size-1]);
        size--;
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
    obj.print();
    obj.Delete();
    obj.Delete();
    obj.print();
    obj.Delete();
    // obj.Delete();

}
