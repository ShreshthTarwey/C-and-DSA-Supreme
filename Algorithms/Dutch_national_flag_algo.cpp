#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {-1,-3,4,5,6,0,7,0,-9,6,7,4,0};
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        if(arr[i]<0){
            i++;
        }
        else if(arr[j]>=0){
            j--;
        }
        else{
            swap(arr[i],arr[j]);
            i++;j--;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}