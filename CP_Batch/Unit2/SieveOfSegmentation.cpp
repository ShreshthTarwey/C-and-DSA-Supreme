#include<bits/stdc++.h>

using namespace std;

void sieve(int n, vector<int>& primes){
    vector<bool>isPrimes(n+1, true);
    isPrimes[0] = isPrimes[1] = false;
    for(int i=2;i*i<=n;i++){
        if(isPrimes[i]){
            // primes.push_back(i);
            for(int j = i*i;j<=n;j+=i){
                isPrimes[j] = false;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(isPrimes[i]){
            primes.push_back(i);
        }
    }
}

void sieveOfSegmentation(int l, int r){
    vector<int>prime;
    sieve(sqrt(r), prime);
    vector<bool>isPrime(r-l+1, true);
    for(auto p: prime){
        int sm = (l/p) * p;
        if(sm<l){
            sm+=p;
        }
        for(int j = sm;j<=r;j+=p){
            isPrime[j-l] = false;
        }
    }
    for(int i=0;i<isPrime.size();i++){
        if(isPrime[i]){
            cout<<i+l<<" ";
        }
    }
}

int main(){
    int l,r;
    cin>>l>>r;
    sieveOfSegmentation(l,r);
}