#include<iostream>
using namespace std;


int main(){
    int arr[6] = {2,12,13,16,19,-1};
    int val = 17;
    int pos=-1;
    for(int i=0;i<5;i++){
        if(val<arr[i]){
            pos = i;
        }
    }
    for(int i=5;i>pos;i--){
        arr[i] =  arr[i-1];
    }
    arr[pos] = val;
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }

}