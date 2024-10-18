#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={9,55,3,4,1,88};
    int n = 6;
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[min]<arr[j]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    for(int i:arr){
        cout<<i<<" ";
    }
}