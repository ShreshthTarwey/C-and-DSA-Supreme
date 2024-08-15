#include<iostream>
using namespace std;
int floys(int n){
    int k=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<k++<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    floys(n);
    return 0;
}