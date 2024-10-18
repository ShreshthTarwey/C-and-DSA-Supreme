#include<iostream>
using namespace std;
class Queue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    Queue(int cap){
        arr = new int[cap];
        front = -1;
        rear = -1;
        size = cap;
    }
    void push(int val){
        if(isEmpty()){
            front++;
            arr[++rear] = val; 
        }
        else if(rear == size-1){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[++rear] = val;
        }
    }
    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }
        else if(front==rear){
            arr[front]=-1;
            front = -1;
            rear =-1;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }
    void getSize(){
        if(front==-1 && rear==-1){
            cout<<0<<endl;
            return;
        }
        else{
            cout<<rear-front+1<<endl;
        }
    }
    void getFront(){
        if(front==-1){
            cout<<"Queue is Empty"<<endl;
        }
        else{
            cout<<arr[front]<<endl;
        }
    }
    void getRear(){
        if(rear==-1){
            cout<<"Queue is Empty"<<endl;
        }
        else{
            cout<<arr[rear]<<endl;
        }
    }
    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }

};
int main(){
    Queue obj(6);
    obj.push(10);
    obj.push(40);
    obj.push(20);
    obj.push(50);
    obj.push(60);
    obj.push(70);
    // obj.push(10);
    obj.pop();
    obj.getFront();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.getSize();
    obj.pop();
}