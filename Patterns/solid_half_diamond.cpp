#include <iostream>
using namespace std;
void diamond(int rows){
    int c=1;
    for(int row=0;row<2*rows-1;row++){
        if(row<rows){
             for(int col=0;col<=row;col++){
            cout<<"*";
        }
        }
        else{
            for(int col=0;col<=rows-c-1;col++){
                cout<<"*";
            }
            c++;
        }
       cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    diamond(n);
    return 0;
}