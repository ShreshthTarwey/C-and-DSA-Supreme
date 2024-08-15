#include<iostream>
using namespace std;
int hollow(int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<rows-row;col++){
            if(col==0||row==0||col==rows-row-1){
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