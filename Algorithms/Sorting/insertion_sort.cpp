#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={9,55,3,4,1,88};
    int i=0;
    int j=1;
    for(int k=0;k<6;k++){
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]<temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        i++;
    }
    for(int i: arr){
        cout<<i<<" ";
    }
}