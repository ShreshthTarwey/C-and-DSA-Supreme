#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&arr,int start,int mid,int end){
    int i = start;
    int j = mid+1;//forgot this
    int index = 0;//forgot this
    vector<int>temp(end-start+1,0);//Forgot this
    while(i<=mid && j<=end){//forgot this
        if(arr[i]>arr[j]){
            temp[index++] = arr[j++];
        }
        else{
            temp[index++] = arr[i++];
        }
    }
    while(i<=mid){
        temp[index++] = arr[i++];
    }
    while(j<=end){
        temp[index++] = arr[j++];
    }
    index = 0;
    while(start<=end){ //Forgot this
        arr[start++] = temp[index++];
    }
}
void print(vector<int>&arr){

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void mergeSort(vector<int>&arr,int start,int end){
    if(start==end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
    print(arr);

}
int main(){
    vector<int>arr = {55,-9,88,5,67,32,45,-10,-1,99};
    int start = 0;
    int end = arr.size()-1;
    mergeSort(arr,start,end);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}