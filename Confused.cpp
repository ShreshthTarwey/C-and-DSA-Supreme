#include<iostream>
using namespace std;
class queue{
    int front,rear,maxSize;
    char *arr;
    public:
    queue(int size = 5){
        front = rear = -1;
        arr = new char[size];
        maxSize = size;
    }
    void enqueue(char d){
        if((rear+1)%maxSize==front){
            cout<<"KK1";
            cout<<"Queue is full"<<endl;
        }
        else if(rear==-1 && front == -1){
            // front++;
            // arr[++rear] = d;
            cout<<"KK2";
            front=0;
            rear=0;
            arr[rear] = d;
            cout<<"Enqueued element is "<<d<<endl;
        }
        else{
            cout<<"KK3";
            rear = (rear+1)%maxSize;
            arr[rear] = d;
            cout<<"Enqueued element is "<<d<<endl;
        }
    }
    void dequeue(){
        
        if(front==-1 && rear==-1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front==rear){
            cout<<"Dequeued element is "<<arr[front]<<endl;
            front=rear = -1;

        }
        else{
            cout<<"Dequeued element is "<<arr[front]<<endl;
            front = (front+1)%maxSize;
        }
    }
     void display() {
        if (front == -1) {  // Queue is empty
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue elements are: ";
            int index = front;
            while (index != rear) {  // Traverse until the rear
                cout << arr[index] << " ";
                index = (index + 1) % maxSize;  // Circular increment
            }
            cout << arr[rear] << endl;  // Print the last element (rear)
        }
    }
};
int main(){
    queue obj;
    int x;
    cin>>x;
    while(x!=4){
        switch (x)
        {
        case 1:
            char d;
            cin>>d;
            obj.enqueue(d);
            break;
        case 2:
            obj.dequeue();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            cout<<"Exitting the program"<<endl;
            return 0;
        
        default:
            cout<<"Invalid entery"<<endl;
            break;
        }
        cin>>x;
    }
}

