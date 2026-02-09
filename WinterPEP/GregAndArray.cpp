#include<bits/stdc++.h>

using namespace std;


int main(){
    long long n,m,k;
    cin>>n>>m>>k;
    vector<long long>nums(n);
    for(long long i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<vector<long long>>operations;
    for(long long i=0;i<m;i++){
        long long l,r,d;
        cin>>l>>r>>d;
        operations.push_back({l,r,d});
    }

    vector<vector<long long>>queries;

    for(long long i=0;i<k;i++){
        long long x,y;
        cin>>x>>y;
        queries.push_back({x,y});
    }
    
    vector<long long>OpCount(m);
    vector<long long>diffArr1(m);
    for(long long i=0;i<k;i++){
        long long x = queries[i][0]-1;
        long long y = queries[i][1]-1;
        diffArr1[x]++;
        if(y+1<m){
            diffArr1[y+1]--;
        }
    }
    OpCount[0] = diffArr1[0];
    for(long long i=1;i<m;i++){
        OpCount[i] = OpCount[i-1] + diffArr1[i];
    }

    vector<long long>diffArr2(n);
    diffArr2[0] = nums[0];
    for(long long i=1;i<n;i++){
        diffArr2[i] = nums[i] - nums[i-1];
    }

    for(long long i=0;i<OpCount.size();i++){

        long long l = operations[i][0] - 1;
        long long r = operations[i][1] - 1;
        long long v = operations[i][2];

        diffArr2[l] += v * OpCount[i];
        if(r+1<diffArr2.size()){
            diffArr2[r+1] -= v * OpCount[i];
        }
        
    }

    cout<<diffArr2[0]<<" ";
    long long sum = diffArr2[0];
    for(long long i=1;i<diffArr2.size();i++){
        sum += diffArr2[i];
        cout<<sum<<" ";
    }



}