#include<iostream>
using namespace std;
void hollow(int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<=row;col++){
            if(row==col||row==rows-1||col==0){
                cout<<col+1<<" ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    hollow(n);
    return 0;
}