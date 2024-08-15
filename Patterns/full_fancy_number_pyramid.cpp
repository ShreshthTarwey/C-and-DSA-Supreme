#include<iostream>
using namespace std;
void upper_fancy(int rows){
    for(int row=0;row<rows;row++){
        for(int col=0;col<row*2+1;col++){
            if(col%2!=0){
                cout<<" * ";
            }
            else{
                cout<<row+1;
            }
        }
        cout<<endl;
    }
}
void lower_fancy(int rows){
    for(int row=0;row<rows-1;row++){
        for(int col=0;col<2*(rows-1)-2*row-1;col++){
            if(col%2!=0){
                cout<<" * ";
            }
            else{
                cout<<rows-row-1;
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    upper_fancy(n);
    lower_fancy(n);

    return 0;
}