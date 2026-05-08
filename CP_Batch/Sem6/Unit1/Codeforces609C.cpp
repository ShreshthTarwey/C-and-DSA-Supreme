#include<bits/stdc++.h>

using namespace std;

int fun(vector<int> arr, priority_queue<int>pq, int avg){
    int n = arr.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        if(abs(arr[i]-avg)>1){
            ans+= abs(arr[i] - avg);
            int x = pq.top();
            pq.pop();
            pq.push(x - abs(arr[i]-avg));
        }
        else if(abs(pq.top()-avg)>1){
            ans += abs(pq.top()-avg);
            int x = pq.top();
            pq.pop();
            pq.push(x + abs(pq.top()-avg));
        }
        else{
            pq.pop();
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);

    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        pq.push(arr[i]);
    }
    long long sum = accumulate(arr.begin(), arr.end(), 0);
    int avg_1 = floor(sum/(double)arr.size());
    int avg_2 = ceil(sum/(double)arr.size());

    // sort(arr.begin(), arr.end());

    int ans = INT_MAX;
    ans = min(ans, fun(arr, pq, avg_1));
    ans = min(ans, fun(arr, pq, avg_2));
    cout<<ans<<"\n";
}