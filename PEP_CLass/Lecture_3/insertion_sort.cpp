#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr(10);
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    for(int i=1;i<10;i++){
        int key = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for(auto i:arr){
        cout<<i<<" ";
    }
}