#include<iostream>
#include<vector>
using namespace std;
bool fibo(int n){
    int a=0;
    int b=1;
    int c=0;
    while(c<=n){
        if(c==n){
            return true;
        }
        a=b;
        b=c;
        c=a+b;
    }
    return false;
}
void  NonFibonacciElements(vector<int>&nums){
    for(int i=0;i<nums.size();i++){
        if(!fibo(nums[i])){
            cout<<nums[i]<<" ";
        }
    }
}
int main(){
    vector<int>nums={1,5,3,8,9,13,4};
    NonFibonacciElements(nums);
}