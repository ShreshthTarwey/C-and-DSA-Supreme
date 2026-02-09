#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int recFun(vector<int>& arr, int index, vector<bool>& visited){
    if(index == arr.size()) return 0;
    if(index<0) return INF;
    if(index>arr.size()) return INF;
    if(visited[index]) return INF;

    visited[index] = true;

    int option1 = 1 + recFun(arr, index+1, visited);

    int option2 = 1 + recFun(arr, index+arr[index], visited);

    visited[index] = false;


    return min(option1, option2);


}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<bool>visited(n, false);
        int res = recFun(arr, 0, visited);

        cout<<((res==INF) ? -1 : res)<<endl;

    }

}