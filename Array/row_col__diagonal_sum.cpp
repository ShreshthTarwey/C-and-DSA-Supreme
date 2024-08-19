#include<iostream>
#include<vector>
using namespace std;
int row_wise_sum(vector<vector<int>>arr){//TC-> O(n^2) SC-> O(1)
    cout<<"Row wise sum is: "<<endl;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum=0;
        for(int j=0;j<arr[0].size();j++){
            sum+=arr[i][j];
        }
        cout<<sum<<endl;
    }
}
void col_wise_sum(vector<vector<int>>arr){//TC-> O(n^2) SC-> O(1)
    int sum=0;
    for(int j=0;j<arr[0].size();j++){
        sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i][j];
        }
        cout<<sum<<endl;
    }
}
void diagonal(vector<vector<int>>arr){// Optimised TC-> O(n) SC-> O(1)
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i][i];
    }
    cout<<"The sum of 1st diagonal is: "<<sum<<endl;
}
void diagonal2(vector<vector<int>>arr){// TC-> O(n^2) SC-> O(1)
    int sum=0;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            if(i+j==arr.size()-1){
                sum+=arr[i][j];
            }
        }
    }
    cout<<"The sum of 2nd diagonal is: "<<sum<<endl;
}
int main(){ 
    vector<vector<int>> arr(4,vector<int>(4,0));
    cout<<"Enter matrix elements:-"<<endl;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cin>>arr[i][j];
        }
    }
    row_wise_sum(arr);
    cout<<"Col wise sum is:-"<<endl;
    col_wise_sum(arr);
    diagonal(arr);
    diagonal2(arr);
}