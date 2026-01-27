#include<bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int low, int high){
    int i = low-1;
    int j = low;
    int pivot = arr[high];
    for(int k = j;k<high;k++){
        if(arr[k]<pivot){
            i++;
            swap(arr[i], arr[k]);
        }
    }
    
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low>high) return;
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot-1);
    quickSort(arr, pivot+1, high);
}

int main(){
    vector<int>arr = {5,4,3,2,1};
    quickSort(arr, 0, arr.size()-1);
    for(auto it: arr){
        cout<<it<<" ";
    }
}