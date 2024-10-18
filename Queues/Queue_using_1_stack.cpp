#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int> s;
    public:
    void enqueue(int x){
        s.push(x);
    }
    int dequeue(){
        if(s.empty()){
            cout<<"Queue is empty"<<endl;
            exit(0);
        }
        int x = s.top();
        s.pop();
        if(s.empty()){
            return x;
        }
        int item = dequeue();
        s.push(x);
        return item;
    }
};
int main(){
    Queue obj;
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(40);
    obj.enqueue(80);
    obj.enqueue(50);
    obj.enqueue(900);
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;

}