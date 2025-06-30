#include<iostream>
using namespace std;
int main(){
    int arr1[5] = {2,8,10,11,18};
    int arr2[5] = {1,9,12,20,22};
    int i=0;
    int j=0;
    int result[10];
    int index = 0;
    while(i<5 && j<5){
        if(arr1[i]<arr2[j]){
            result[index++] = arr1[i++];
        }
        else{
            result[index++] = arr2[j++];
        }
    }
    while(i<5){
        result[index++] = arr1[i++];
    }
    while(j<5){
        result[index++] = arr2[j++];
    }
    for(int i=0;i<10;i++){
        cout<<result[i]<<" ";
    }
}