#include<iostream>
using namespace std;
pair<int,int> checkpairs(int arr[],int n,int target){//TC -> O(n^2) SC->O(1)
    pair<int,int> ans=make_pair(-1,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]+arr[j]==target){
                ans.first=arr[i];
                ans.second=arr[j];
                return ans;
            }
        }
    }
    return ans;
}
int main(){
    int arr[]={10,20,30,40};
    pair<int,int> ans=checkpairs(arr,4,600);
    if(ans.first==-1 && ans.second==-1){
        cout<<"Pair not found";
    }
    else{
        cout<<ans.first<<","<<ans.second<<endl;
    }
} 