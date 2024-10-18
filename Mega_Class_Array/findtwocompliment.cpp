#include<iostream>
#include<vector>
using namespace std;
vector<int>findtwocompliment(vector<int> arr){
    int n=arr.size();
    vector<int>two(n+1,0);
    for(int i=n-1;i>=0;i--){
        two[i+1]=arr[i]==1?0:1;
    }
    int c=1;
    for(int i=n;i>=0;i--){
        int sum=two[i]+c;
        two[i]=sum%2;
        c=sum/2;
    }
    return two;
}
int main(){
    vector<int> arr={1,0,1,0,1,1};
    vector<int> ans = findtwocompliment(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
}