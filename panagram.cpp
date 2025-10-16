#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    string str = "";
    for(auto i:s){
        str+=tolower(i);
    }
    vector<int> map(256,0);
    for(auto i:str){
        map[i]++;
    }
    vector<char>ans;
    for(int i='a';i<='z';i++){
        if(map[i]==0){
            ans.push_back(i);
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }

}