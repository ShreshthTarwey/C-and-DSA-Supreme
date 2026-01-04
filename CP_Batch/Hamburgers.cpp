#include<bits/stdc++.h>

using namespace std;


// check(mid, nB, nS, nC, pB, pS, pC, rupees)

bool check(long long mid, int nB, int nS, int nC, int pB, int pS, int pC, long long rupees, int countB, int countS, int countC){
    long long reqBread = (mid * countB) - nB;
    if(reqBread<0){
        reqBread = 0;
    }
    long long reqSau = (mid * countS) - nS;
    if(reqSau<0){
        reqSau = 0;
    }
    long long reqChees = (mid * countC) - nC;
    if(reqChees<0){
        reqChees = 0;
    }

    long long reqMoney = (reqBread * pB) + (reqSau * pS) + (reqChees * pC);

    return reqMoney<=rupees;

}


int main(){
    string recipe;
    cin>>recipe;
    int nB,nS,nC;
    cin>>nB>>nS>>nC;
    int pB,pS,pC;
    cin>>pB>>pS>>pC;
    long long rupees;
    cin>>rupees;

    long long low = 0;
    long long high = 1e13;
    long long ans = 0;
    
    int countB = 0;
    int countS = 0;
    int countC = 0;


    for(auto it : recipe){
        if(it == 'B') countB++;
        if(it == 'S') countS++;
        if(it == 'C') countC++;
    }





    while(low<=high){
        long long mid = low + (high - low)/2;
        if(check(mid, nB, nS, nC, pB, pS, pC, rupees, countB, countS, countC)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }

    }
    cout<<ans;

    return 0;

}