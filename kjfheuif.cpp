/*
Pattern for N = 5
1234554321
1234**4321
123****321
12******21
1********1
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int j=0;
        for(j=0;j<n-i;j++){
            cout<<j+1;
        }
        int gap=2*i;
        while(gap>0){
            cout<<"*";
            gap--;
        }
        int num=n-i;
        while(num!=0){
            cout<<num--;
        }
        cout<<endl;
    }
}