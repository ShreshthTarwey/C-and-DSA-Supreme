#include<iostream>
//We are not allowed to use % or / operator 
using namespace  std;
int findQuotient(int divisor,int divident){
    int s=0;
    int e = divident;
    int mid = s+((e-s)>>1); //x>>y is x/2^y
    int ans;
    while(s<=e){
        if(divisor*mid==divident){
            ans =  mid;
            break;
        }
        else if(divisor*mid<divident){
            ans = mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid = s+((e-s)>>1);
    }
    return ans;
}
int main(){
    int divident = -3;
    int divisor = -2;
    int ans = findQuotient(abs(divisor),abs(divident));
    if((divisor>0 && divident<0) || (divisor<0 && divident>0)){
        ans = -ans;
    }
    cout<<"The Quotient is: "<<ans;
}