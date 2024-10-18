#include<iostream>
#include<vector>
using namespace std;
int fingOddoccuringelement(vector<int>&arr){
    int n=arr.size()-1;
    int s=0;
    int e= n;
    int mid = s+(e-s)/2;
    while(s<=e){
        if(s==e){
            return s;
        }
        //duplicate element not found
        if(mid-1>=0 && arr[mid-1]!=arr[mid] && mid+1<n && arr[mid+1]!=arr[mid]){
            return mid;
        }
        //element found left 
        else if(mid-1>=0 && arr[mid-1]==arr[mid]){
            int pairstart = mid-1;
            if(pairstart&1){
                e = mid-1;
            }
            else{
                s=mid+1;
            }
        }
        //element found in right
        else if(mid+1<n && arr[mid+1] == arr[mid]){
            int pairstarting = mid;
            if(pairstarting&1){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        // return -1;
        mid = s +(e-s)/2;
    }
    return -1;
}
int main(){
    // vector<int>arr = {1,1,2,2,3,3,4,4,5,6,6,4,4,2,2};
    vector<int>arr = {1,2,2,3,3};
    int ans = fingOddoccuringelement(arr);
    cout<<"Answer index: "<<ans<<endl;
    cout<<"Answer Element: "<<arr[ans]<<endl;
}