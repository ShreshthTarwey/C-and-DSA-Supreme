#include<iostream>
using namespace std;
void inverted_pyramid(int n){
    for(int row=0;row<n;row++){
        for(int col=0;col<n-row;col++){
            cout<<" * ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows:"<<endl;
    cin>>n;
    inverted_pyramid(n);
    return 0;
}