#include<iostream>
using namespace std;
int main(){
    pair<int,int> pi;
    pi=make_pair(10,20);
    cout<<pi.first<<","<<pi.second<<endl;
    pi.first=100;
    pi.second=200;
    cout<<pi.first<<","<<pi.second<<endl;
}