#include<iostream>
#include<vector>
using namespace std;
class Queue{
    vector<int>v;
    int front;
    int rear;
    int size;
    public:
    Queue(int cap){
        v.resize(cap);
        front=-1;
        rear=-1;
        size=cap;
    }
    void push(int val){
        if(Empty()){
            front++;
            v[++rear] = val;
        }
        else{
            v[++rear]=val;
        }
        size++;
    }
    void pop(){
        v[front++]=-1;
        size--;
    }
    bool Empty(){
        if(front==-1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }
    void size(){
        cout<<"The size of queue is: "<<size;
    }
    void front(){
        if(Empty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
        cout<<"The front element is: "<<v[front];
        }
    }
};