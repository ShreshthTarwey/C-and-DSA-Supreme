#include<bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int countZeros = 0;
        for(auto it: s){
            if(it == '0') countZeros++;
        }
        // bool flag = isPalindrome(s);

        if(countZeros==1){
            cout<<"BOB"<<endl;
        }
        else if(countZeros%2!=0){
            cout<<"ALICE"<<endl;
        }
        else{
            cout<<"BOB"<<endl;
        }
    }
}