#include<bits/stdc++.h>

using namespace std;

class CircularQueue{
    public:
    int *arr;
    int capacity;
    int size;
    int front;
    int rear;

    CircularQueue(int size){
        this->capacity = size;
        this->size = 0;
        this->rear = -1;
        this->front = -1;
        this->arr = new int[size];
    }

    void push(int x){
        if(isFull()){
            cout<<"OverFlow"<<endl;
            return;
        }
        if(rear == -1 && front == -1){
            rear++;
            front++;
            arr[rear] = x;
            size++;
            rear++;
            rear = rear % capacity;
            return;
        }
        arr[rear] = x;
        rear++;
        rear = rear % capacity;
        size++;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return;
        }
        arr[front] = -1;
        front++;
        front = front%capacity;
        size--;
        if(front == rear){
            front = -1;
            rear = -1;
        }
    }

    int getTop(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    bool isFull(){
        return size == capacity;
    }

    bool isEmpty(){
        return size == 0;
    }
}



int main(){

}