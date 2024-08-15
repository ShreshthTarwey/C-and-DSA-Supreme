#include<iostream>
using namespace std;
void mix(int rows){
    //1st half
    for(int row=0;row<rows;row++){
        // PART-1
        for(int col=0;col<rows-row;col++){
            cout<<"* ";
        }
        // PART-2
        for(int col=0;col<2*row+1;col++){
            cout<<"  ";
        }
        // PART-3
        for(int col=0;col<rows-row;col++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int row=0;row<rows;row++){
        for(int col=0;col<=row;col++){
            cout<<"* ";
        }
        for(int space=0;space<(2*rows)-(2*row+1);space++){
            cout<<"  ";
        }
        for(int col=0;col<=row;col++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    mix(n);
    return 0;
}