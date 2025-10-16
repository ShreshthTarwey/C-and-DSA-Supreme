#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<int>&cooksRank,int nP,int limit){
    int currP = 0;
    for(int i=0;i<cooksRank.size();i++){
        int currRank = cooksRank[i],j=1;
        int timeTaken = 0;
        while(true){
            if(timeTaken+currRank*j<=limit){
                timeTaken += currRank*j;
                j++;
                currP++;
            }
            else{
                break;
            }
        }
        if(currP>=nP){
            return true;
        }
    }
    return false;
}
int minTime(vector<int>&cooksRank,int nP,int nC){
    int start = 0;
    int maxx = *max_element(cooksRank.begin(),cooksRank.end());
    int end = maxx*((nP*(nP+1))/2);
    int ans = -1;
    while(start<=end){
        int mid = (start+end)>>1;
        if(isPossible(cooksRank,nP,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int nC,nP;
        cin>>nP>>nC;
        vector<int>cooksRanks;
        for(int i=0;i<nC;i++){
            int j; cin>>j;
            cooksRanks.push_back(j);
        }
        cout<<minTime(cooksRanks,nP,nC)<<endl;
    }
}