#include<bits/stdc++.h>

using namespace std;


bool isPowerOfFour(int n) {
        if(n==1){
            return true;
        }
        if(n<1){
           return false;
        }
        if(n%4!=0){
           return false;
        }
       
        return isPowerOfFour(n/4);
    }

int main(){
    cout<<isPowerOfFour(16)<<endl;
    cout<<isPowerOfFour(18);
}