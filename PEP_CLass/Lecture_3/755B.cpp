#include<iostream>
#include<string>
#include<vector>
using namespace std;

void removeString(vector<string>&arr,string x){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==x){
            arr[i] = "NA";
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    cin.ignore();
    vector<string>arr1(n);
    vector<string>arr2(m);
    for(int i=0;i<n;i++){
        string line;
        getline(cin,line);
        arr1[i] = line;
    }
    for(int i=0;i<m;i++){
        string line;
        getline(cin,line);
        arr2[i] = line;
    }
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(arr1[i]!="NA"){
            removeString(arr2,arr1[i]);

            i++;

        }
        else{
            i++;
            if(i<n)
            removeString(arr2,arr1[i]);
            i++;
        }
        // if(i<n)
        if(arr2[j]!="NA"){
            removeString(arr1,arr2[j]);

            j++;
        }
        else{
            j++;
            if(j<m)
            removeString(arr1,arr2[j]);
            j++;
        }
        // if(j<m)
    }
    if(i>=n){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}