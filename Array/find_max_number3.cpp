#include<iostream>
#include<limits.h> // you can include this file if you are getting any errors in INT_MIN or INT_MAX
using namespace std;
int findMax(int arr[],int size){
    int num= INT32_MIN;
    for(int i=0;i<size;i++){
        // if(arr[i]>num){
        //     num=arr[i];
        // }
        // OR
        num = max(num,arr[i]); // we have a inbuild max function in C++
    }
    return num;

}
int main(){
    int arr[5]={33,-9,66,78,9};
    cout<<"The max number is "<<findMax(arr,5);
}