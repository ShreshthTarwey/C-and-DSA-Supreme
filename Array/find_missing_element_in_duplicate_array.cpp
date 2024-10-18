#include<iostream>
#include<vector>
using namespace std;
void findMissing(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int index = abs(arr[i]);
        if(arr[index-1]>0){
            arr[index-1]*=-1;
        }
}
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            cout<<i+1<<" ";
        }
    }
}
void sortingMethod(vector<int>&arr){
    int i=0;
    int n = arr.size();
    while(i<n){
            int index = arr[i]-1;
            if(arr[index]!=arr[i]){
                swap(arr[index],arr[i]);
            }
        else{
            i++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int> arr = {5,4,3,4,1};
    // findMissing(arr);
    sortingMethod(arr);
}