#include<iostream>
#include<vector>
using namespace std;
void findFirstOccurence(vector<int>& arr,int target,int &ans){
    int s=0;
    int e=arr.size()-1;
    int mid;
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]==target){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
}
void findLastOccurence(vector<int>& arr,int target,int &ans){
    int s=0;
    int e=arr.size()-1;
    int mid;
    while(s<=e){
        mid=s+(e-s)/2;
        if(arr[mid]==target){
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
}
int main(){
    vector<int> arr = {10,20,30,42,55,66,333,455,567,600,600,600};
    int target=600;
    // cin>>target;
    int ans;
    findFirstOccurence(arr,target,ans);
    cout<<ans<<endl;
    cout<<"---------------------------------------------"<<endl;
    findLastOccurence(arr,target,ans);
    cout<<ans;
}