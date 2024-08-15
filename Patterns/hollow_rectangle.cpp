#include<iostream>
using namespace std;
void hollow(int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==(n-1)){
                cout<<"*";
            }
            else if(j==0 || j==(m-1)){
                cout<<"*";
            }
            else{
                cout<< " ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n,m;
    cout<<"Enter number of rows and column: "<<endl;
    cin>>n>>m;
    hollow(n,m);
    return 0;

}