#include<bits/stdc++.h>
#include<numeric>
using namespace std;

long long gcd(long long a, long long b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long g = arr[0];
        for(int i=1;i<n;i++){
            g = gcd(g,arr[i]);
        }
        int x=2;
        while(gcd(x,g)!=1){
            x++;
        }
        cout<<x<<endl;
    }
}