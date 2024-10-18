#include<iostream>
#include<vector>
using namespace std;
    int findFirstOccurence(vector<int>&nums,int target){
        int s=0;
        int e=nums.size()-1;
        int mid;
        int ans=-1;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target){
                ans=mid;
                e=mid-1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    int findLastOccurence(vector<int>&nums,int target){
        int s=0;
        int e=nums.size()-1;
        int mid;
        int ans=-1;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target){
                ans=mid;
                s=mid+1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
int main(){
    vector<int> arr = {10,20,30,42,55,66,333,455,567,600,600,600};
    int target=600;
    // cin>>target;
    // int ans;
    int first = findFirstOccurence(arr,target);
    // cout<<ans<<endl;
    // cout<<"---------------------------------------------"<<endl;
    int last = findLastOccurence(arr,target);
    // cout<<ans;
    // explanation-----> {10,20,20,20,30,40}; the total occurence can be calculated using a formula last-first+1
    cout<<last-first+1;
}