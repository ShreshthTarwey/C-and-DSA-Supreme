#include<iostream>
#include<algorithm>
using namespace std;
void methon1(int arr[],int n){ //Time complexity = O(n)+O(n)=O(n) Space Complexity = O(1)
    int z=0;
    int o=0;
    int t=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            z++;
        }
        else if(arr[i]==1){
            o++;
        }
        else{
            t++;
        }
    }
    for(int i=0;i<n;i++){
        if(z!=0){
            arr[i]=0;
            z--;
            continue;
        }
        else if(o!=0){
            arr[i]=1;
            o--;
            continue;
        }
        else{
            arr[i]=2;
        }
}
}
void method2(int arr[],int n){ //Time Complexity:

// The first loop counts the occurrences of 0, 1, and 2. This loop runs n times, 
//so the time complexity is O(n).
// The fill function is called three times:
// fill(arr, arr + z, 0) runs z times.
// fill(arr + z, arr + z + o, 1) runs o times.
// fill(arr + o + z, arr + o + z + t, 2) runs t times.
// Since z + o + t = n, these three calls together run in O(n) time.

// Thus, the overall time complexity of method2 is O(n).
//Space complexity = O(1)
    int z=0;
    int o=0;
    int t=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            z++;
        }
        else if(arr[i]==1){
            o++;
        }
        else{
            t++;
        }
    }
    fill(arr,arr+z,0);
    fill(arr+z,arr+z+o,1);
    fill(arr+o+z,arr+o+z+t,2);
}
void method3(int arr[], int n){//TC = O(nlogn) SC= O(nlogn)
    sort(arr,arr+n);
}
int main(){
    int arr[]={0,0,2,1,1,2,2,0,0,0};
    // methon1(arr,10);
    // method2(arr,10);
    method3(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}