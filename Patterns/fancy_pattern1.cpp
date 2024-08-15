#include<iostream>
using namespace std;
void fancy(int rows){
    for(int row=0;row<rows;row++){
    int start_num_index=8-row;
    int count = row+1;
    int num=row+1;
        for(int col=0;col<17;col++){
            if(col==start_num_index&& count>0){
                cout<<num;
                start_num_index+=2;
                count--;
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows upto 9: ";
    cin>>n;
    fancy(n);
    return 0;
}