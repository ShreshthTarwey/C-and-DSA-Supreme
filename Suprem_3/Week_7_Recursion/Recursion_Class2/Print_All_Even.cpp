#include<bits/stdc++.h>
using namespace std;

void printAllEven(int arr[], int size, int index){
    if(index==size){
        return;
    }
    if(!(arr[index]&1)){
        cout<<arr[index]<<" ";
    }
    printAllEven(arr,size,index+1);
}

int main(){
    int arr[] = {10,20,21,30,31,40,50,60};
    int size = 8;
    printAllEven(arr,size,0);
    return 0;
}