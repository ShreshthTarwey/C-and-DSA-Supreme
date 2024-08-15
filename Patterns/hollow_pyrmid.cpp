#include<iostream>
using namespace std;
void hollow(int rows){
    for(int row=0;row<rows;row++){
        for(int space=0;space<=rows-row-1;space++){
            cout<<" ";
        }
        for(int star=0;star<=row;star++){
            if(row==rows-1||row==star||star==0){
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
    hollow(n);
    return 0;
}