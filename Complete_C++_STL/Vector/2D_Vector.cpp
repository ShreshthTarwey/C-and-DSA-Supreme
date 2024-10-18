#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> arr(5,vector<int>(5,0));
    int total_rows = arr.size();
    int size_column = arr[0].size();
    for(int i=0;i<total_rows;i++){
        for(int j=0;j<size_column;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<total_rows;i++){
        for(int j=0;j<size_column;j++){
            cout<<arr[i][j];
        }
    }
}