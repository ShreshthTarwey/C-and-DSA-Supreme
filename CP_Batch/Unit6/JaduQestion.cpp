#include<bits/stdc++.h>

using namespace std;

void recFun(vector<string>& ans, string temp, int index, int k){
    if(temp.length()==k){
        ans.push_back(temp);
        return;
    }
    // if(index>0 && temp[index-1])

    vector<char> crr = {'1', '2', '3'};

    for(int i=0;i<3;i++){
        // if(i>0 && temp[i-1]=='1') continue;
        // temp+= crr[i];
        if(temp[temp.length()-1]== crr[i]) continue;
        recFun(ans, temp+crr[i], index+1, k);
    }

}

int main(){
    int k;
    cin>>k;
    vector<string>ans;
    string temp = "";
    recFun(ans, temp, 0, k);
    for(auto it: ans){
        cout<<it<<" ";
    }

}