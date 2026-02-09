#include<bits/stdc++.h>

using namespace std;


int digitDp(string &s, int i, int nonZero, bool limit){
    if(nonZero>3) return 0;
    if(i == s.size()) return 1;

    char high = (limit ? '9' : s[i]);

    int ans = 0;
    for(char c='0'; c<=high;c++){
        if(c != high){
            ans += digitDp(s, i+1, nonZero + (c!='0'), true);
        }
        else{
            ans += digitDp(s, i+1, nonZero + (c!='0'), limit);
        }
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        long long l,r;
        cin>>l>>r;
        string s = to_string(l-1);
        string k = to_string(r);
        cout<<digitDp(k, 0, 0, 0) -  digitDp(s,0,0,0)<<endl;
    }
}