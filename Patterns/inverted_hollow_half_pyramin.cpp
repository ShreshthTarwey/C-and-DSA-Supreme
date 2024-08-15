#include<iostream>
using namespace std;
void inverted_hollow(int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<rows-row;col++){
            if(row==0||col==0||col==rows-row-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows"<<endl;
    cin>>n;
    inverted_hollow(n);
    return 0;
}