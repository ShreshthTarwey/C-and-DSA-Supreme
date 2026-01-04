#include<bits/stdc++.h>

using namespace std;
void printSubarrays_utility(vector<int>& arr, int start, int end){
    //Base case
    if(end==arr.size()){
        return;
    }


    for(int i=start;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    printSubarrays_utility(arr,start,end+1);
    
    return;
}
void printSubarrays(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        printSubarrays_utility(arr,i,i);
    }
}

int main(){
    // int arr[] = {1,2,3,4,5};
    vector<int>arr = {1,2,3,4,5};
    printSubarrays(arr);
}