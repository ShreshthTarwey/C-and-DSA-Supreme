#include<iostream>
using namespace std;
void hollow(int rows){
    for(int row=0;row<rows;row++){
        for(int space=0;space<row;space++){
            cout<<" ";
        }
        for(int star=0;star<rows-row;star++){
            if(star==0||row==0||star==rows-row-1){
            cout<<"* ";}
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