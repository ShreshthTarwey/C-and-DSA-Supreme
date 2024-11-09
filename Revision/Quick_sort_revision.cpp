#include<iostream>
#include<vector>
using namespace std;

//Forgot almost whole quick sort



int partition(vector<int>&arr,int start,int end){
    int index=0;
    int pos=0;
    while(index<=end){
        if(arr[index]<=arr[end]){
            swap(arr[pos++],arr[index++]);
        }
        else{
            index++;
        }
    }
    return pos-1;
}
void print(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void Quicksort(vector<int>&arr,int start,int end){
    if(start>=end){
        return;
    }
    int pivot = partition(arr,start,end);
    print(arr);
    Quicksort(arr,start,pivot-1);
    Quicksort(arr,pivot+1,end);
}
int main(){
    vector<int> arr = {55,-9,88,5,67,32,45,-10,-1,99};
    int start = 0;
    int end = arr.size()-1;
    Quicksort(arr,start,end);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}