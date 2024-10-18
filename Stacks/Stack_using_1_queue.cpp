#include<iostream>
#include<queue>
using namespace std;
class Stack{
    queue<int> q;
    public:
    void push(int x){
        if(q.empty()){
            q.push(x);
            return;

        }
        else{
            q.push(x);
            rotate();
        }
        printStack();

    }
    void rotate(){
        int x = q.front();
        q.pop();
        if(q.empty()){
            q.push(x);
            return;
        }
        rotate();
        q.push(x);
    }
    int pop(){
        if(q.empty()){
            cout<<"Stack is empty"<<endl;
            exit(0);
        }
        int x = q.front();

        q.pop();
        if(q.empty()){
            return x;
        }
        rotate();

        return x;
    }
    void printStack() {
        queue<int> temp = q;
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();  
        }
        cout << endl; 
    }
};
int main(){
    Stack obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.push(50);
    // // obj.rotate();
    // obj.printStack();
    cout<<"The popped element is: "<<obj.pop()<<endl;
    // obj.printStack();
    cout<<"The popped element is: "<<obj.pop()<<endl;
    // obj.printStack();
    cout<<"The popped element is: "<<obj.pop()<<endl;
    // obj.printStack();
    cout<<"The popped element is: "<<obj.pop()<<endl;
    // obj.printStack();
    cout<<"The popped element is: "<<obj.pop()<<endl;
    // obj.pri/ntStack();
}