#include<iostream>
using namespace std;
void swapping1(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void swapping2(int &a,int &b){
    swap(a,b);
}
void swapping3(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}
void swapping4(int &a,int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}
int main(){
    int a,b;
    cin>>a>>b;
    // swapping1(a,b);
    // swapping2(a,b);
    // swapping3(a,b);
    swapping4(a,b);
    cout<<a<<" "<<b;
}