#include<iostream>
using namespace std;
void numeric(int rows){
    int num=1;
    for(int row=0;row<rows;row++){
        num=1;
        for(int col=0;col<row+1;col++){
            cout<<num++;
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows: "<<endl;
    cin>>n;
    numeric(n);
    return 0;
}