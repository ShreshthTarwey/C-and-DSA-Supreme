#include<iostream>
#include<vector>
using namespace std;
int main(){ 
    vector<vector<int>> arr(4,vector<int>(3,0));
    cout<<"Enter matrix elements:-"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
}