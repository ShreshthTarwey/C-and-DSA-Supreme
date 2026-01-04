#include<bits/stdc++.h>

using namespace std;

bool check(int n, int mid){
    return mid*2>=n;
}

int fun(int n, int m){
    int left = 1;
    int right = n;
    int ans = -1;
    while(left<=right){
        int mid = (left+right)/2;
        // int steps = mid*2;
        if((mid%m==0)){
            if(check(n,mid)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }            
        }
        else{
            int num = mid;
            while(num<=n && num%m!=0){
                num++;
            }
            if(num<=n){
                if(check(n,mid)){
                    ans = num;
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else{
                return -1;
            }
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    cout<<fun(n,m);

}