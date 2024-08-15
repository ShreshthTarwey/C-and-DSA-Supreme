#include<iostream>
using namespace std;
void fancy(int rows){
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
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    fancy(n);
    return 0;
}