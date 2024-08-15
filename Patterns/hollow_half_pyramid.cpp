#include<iostream>
using namespace std;
void hollow(int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<row+1;col++){
            if(col==0 || row==rows-1 || row==col){
            cout<<"*";}
        
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
void hollow2(int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<row+1;col++){
            if(row==0||row==1||row==rows-1){
                cout<<"*";
            }
            else{
                if(col==0||col==row+1-1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows"<<endl;
    cin>>n;
    // hollow(n);
    hollow2(n);
}