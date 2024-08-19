#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Only For square matrix
void transpose(vector<vector<int>>&arr){//TC-> O(n^2) SC-> O(1)
    for(int i=0;i<arr.size();i++){
        for(int j=i;j<arr[0].size();j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}
void generaltranspose(vector<vector<int>>&arr){
    int ans[100][100];
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            ans[j][i]=arr[i][j];
        }
    }
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>>arr(3,vector<int>(4,0));
    cout<<"Enter the elements of matrix:-"<<endl;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cin>>arr[i][j];
        }
    }
    // transpose(arr);
    generaltranspose(arr);
    // for(int i=0;i<arr.size();i++){
    //     for(int j=0;j<arr[0].size();j++){
    //         cout<<arr[i][j]<<" ";
    // }
    // cout<<endl;
    // }
}