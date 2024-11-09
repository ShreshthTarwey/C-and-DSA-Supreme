#include<iostream>
using namespace std;
int partition(int arr[],int l,int r){
    int pos=0;
    int i=0;
    int start = l;
    int end = r;
    while(i<=end){
        if(arr[i]<=arr[end]){
            swap(arr[pos++],arr[i++]);
        }
        else{
            i++;
        }
    }
    return pos-1;
}
void quickSort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int piviot = partition(arr,start,end);
    quickSort(arr,start,piviot-1);
    quickSort(arr,piviot+1,end);
}
int main(){
    int arr[] = {6,44,8,-1,89,-90};
    quickSort(arr,0,5);
    for(auto i : arr){
        cout<<i<<" ";
    }
}