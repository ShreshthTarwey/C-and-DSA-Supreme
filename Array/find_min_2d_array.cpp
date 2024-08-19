#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int findMinimum(vector<vector<int>>arr){
    int minimum=INT_MAX;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            minimum=min(arr[i][j],minimum);
        }
    }
    return minimum;
}
int findMax(vector<vector<int>>arr){
    int maximum=INT_MIN;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            maximum=max(arr[i][j],maximum);
        }
    }
    return maximum;
}
int main(){ 
    vector<vector<int>> arr(4,vector<int>(3,0));
    cout<<"Enter matrix elements:-"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    
    cout<<"The minimum element in this 2d array is "<<findMinimum(arr)<<endl;
    cout<<"The maximum element in this 2d array is "<<findMax(arr)<<endl;
}