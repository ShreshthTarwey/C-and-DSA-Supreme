#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<int> arr2(n*n,0);
    int index = 0;
    int k = 0;
    for(int k=0;k<n*n;k++){
        int num = INT_MAX;
        int l,m=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]<=num && arr[i][j]!=-1){
                    num = arr[i][j];
                    l = i;
                    m = j;
                }
            }
        }
        arr[l][m] = -1;
        arr2[index++] = num;
    }
    for(int i=0;i<index;i++){
        cout<<arr2[i]<<" ";
    }
}