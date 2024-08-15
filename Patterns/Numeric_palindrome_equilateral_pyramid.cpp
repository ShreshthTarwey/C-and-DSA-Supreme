#include<iostream>
using namespace std;
void palindrome(int rows){
    int k=rows;
    for(int row=0;row<rows;row++){
        int c=1;
        for(int col=0;col<k;col++){
            if(col<rows-row-1){
                cout<<" ";
            }
            else if(col<rows){
                cout<<c++;
            }
            else if(col==rows){
                c=c-2;
                cout<<c--;
            }
            else{
                cout<<c--;
            }
        
    }
    cout<<endl;
    k++;
}
}
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    palindrome(n);
    return 0;
}