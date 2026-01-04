#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    // vector<int>arr(n, 0);
    vector<int>cahiye(n,0);
    vector<int>hai(n,0);


    for(int i=0;i<n;i++){
        cin>>cahiye[i];
    }

    for(int i=0;i<n;i++){
        cin>>hai[i];
    }

    vector<int>temp(n,0);

    for(int i=0;i<n;i++){
        temp[i] = (hai[i]/cahiye[i]);
    }

    while(k>0){
       auto it = min_element(temp.begin(), temp.end());
       int index = distance(temp.begin(), it);
       hai[index]++;
       k--;
       temp[index] = hai[index] / cahiye[index];
    }

    auto it = min_element(temp.begin(), temp.end());
    cout<<temp[distance(temp.begin(), it)];
    
}