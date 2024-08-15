#include<iostream>
using namespace std;
int findUnique(int arr[],int n){
    int ans=0;
    int flag=0;
    for(int i=0;i<n;i++){
        ans=arr[i];
        flag=1;
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            if(ans==arr[j]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            return ans;
        }
    }
}
int main(){
    int arr[]={1,1,2,2,3};
    cout<<"The unique number is "<<findUnique(arr,2);
}