#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    vector<int>arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cin.ignore();
    string s1;
    getline(cin,s1);
    reverse(arr.begin(),arr.end());
    reverse(s1.begin(),s1.end());
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<s1;


}