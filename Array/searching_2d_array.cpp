#include<iostream>
using namespace std;
bool sea(int arr[][4],int n,int m,int target){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==target){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int arr[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    if(sea(arr,4,4,50)){
        cout<<"The target exist";
    }
    else{
        cout<<"Target do not exist";
    }
}