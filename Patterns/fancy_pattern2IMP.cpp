#include<iostream>
using namespace std;
int fancy(int rows){
    int c=1;
    for(int row=0;row<rows;row++){
        for(int col=0;col<=row;col++){
            cout<<c;
            c++;
            if(col<row){ // did'nt understand
                cout<<"*";
            }
        }
        cout<<endl;
    }
    int start = c-rows;
    for(int row=0;row<rows;row++){
        int k=start;
        for(int col=0;col<=rows-row-1;col++){
            cout<<k++;
            if(col<rows-row-1){ // did'nt understand
                cout<<"*";
            }
        }
        start =  start - (rows-row-1);
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    fancy(n);
    return 0;
}