#include<iostream>
using namespace std;
void upper_hollow(int rows){
    for(int row=0;row<rows;row++){
        for(int space=0;space<rows-row-1;space++){
            cout<<" ";
        }
        for(int col=0;col<=row;col++){
            if(col==0||row==col){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void lower_hollow(int rows){
    for(int row=0;row<rows;row++){
        for(int space=0;space<row;space++){
            cout<<" ";
        }
        for(int col=0;col<rows-row;col++){
            if(col==0||col==rows-row-1){
                cout<<"* ";
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
    upper_hollow(n);
    lower_hollow(n);
    return 0;
}