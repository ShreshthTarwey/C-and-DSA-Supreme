#include<iostream>
using namespace std;
void inverted_numeric(int rows){
    int num=1;
    for(int row=0;row<rows;row++){
        num=1;
        for(int col=0;col<rows-row;col++){
            cout<<num++;
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows: "<<endl;
    cin>>n;
    inverted_numeric(n);
    return 0;
}