#include<iostream>
using namespace std;
int Add(int x,int y){
    if(y==0){
        return x;
    }
    return Add(x+1,y-1);
}
int main(){
    int a=5;
    int b=3;
    cout<<"Additon using recursion "<<Add(a,b)<<endl;
}