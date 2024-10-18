#include<iostream>
using namespace std;
int mySqrt(int x) {
        int s=0;
        int e=x; //or you can write x/2 also but it is faling for x=1
        int ans = -1;
        while(s<=e){
            long long int mid = s+(e-s)/2;
            if(mid*mid==x){
                return mid;
            }
            else if(mid*mid>x){
                e=mid-1;
            }
            else{
                ans = mid;
                s = mid+1;
            }
        }
        return ans;
    }