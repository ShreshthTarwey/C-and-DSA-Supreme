#include<iostream>
using namespace std;
void inverted(int rows){
    for(int row=0;row<rows;row++){
        for(int space=0;space<row;space++){
            cout<<" ";
        }
        for(int star=0;star<rows-row;star++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows: "<<endl;
    cin>>n;
    inverted(n);
    return 0;
}