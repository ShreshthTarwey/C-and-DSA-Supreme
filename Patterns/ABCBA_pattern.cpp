#include<iostream>
using namespace std;
void ABCBA(int rows){
for(int row=0;row<rows;row++){
    char ch='A';
    for(int col=0;col<=row;col++){
        cout<<ch;
        ch++;
    }
    ch--;
    while(ch>'A'){
        ch--;
        cout<<ch;
    }
    cout<<endl;
}
}
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    ABCBA(n);
    return 0;
}