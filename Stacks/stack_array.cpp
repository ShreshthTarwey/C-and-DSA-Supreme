#include<iostream>
using namespace std;
class stack{
    public:
    int rear;
    int *arr;
    int size;
    stack(int n) {
        rear = -1;
        arr = new int[n];
        this->size = n;
    }
    void push(int v){
        if(size==rear){
            cout<<"Stack overflow"<<endl;
            return;
        }
        arr[++rear] = v;
    }
    void pop(){
        if(rear==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        arr[rear--] = -1;
    }
    
};