#include<bits/stdc++.h>

using namespace std;


int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<vector<int>>operations;
    for(int i=0;i<m;i++){
        int l,r,d;
        cin>>l>>r>>d;
        operations.push_back({l,r,d});
    }

    vector<vector<int>>queries;

    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        queries.push_back({x,y});
    }
    
    vector<int>OpCount(m);
    vector<int>diffArr1(m);
    for(int i=0;i<k;i++){
        int x = queries[i][0]-1;
        int y = queries[i][1]-1;
        diffArr1[x]++;
        if(y+1<m){
            diffArr1[y+1]--;
        }
    }
    OpCount[0] = diffArr1[0];
    for(int i=1;i<m;i++){
        OpCount[i] = OpCount[i-1] + diffArr1[i];
    }

    vector<int>diffArr2(n);
    diffArr2[0] = nums[0];
    for(int i=1;i<n;i++){
        diffArr2[i] = nums[i] - nums[i-1];
    }

    for(int i=0;i<OpCount.size();i++){

        int l = operations[i][0] - 1;
        int r = operations[i][1] - 1;
        int v = operations[i][2];

        diffArr2[l] += v * OpCount[i];
        if(r+1<diffArr2.size()){
            diffArr2[r+1] -= v * OpCount[i];
        }
        
    }

    cout<<diffArr2[0]<<" ";
    int sum = diffArr2[0];
    for(int i=1;i<diffArr2.size();i++){
        sum += diffArr2[i];
        cout<<sum<<" ";
    }
    


}