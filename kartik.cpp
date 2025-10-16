#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    string target;
    cin>>target;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            cout<<"The country "<<target<<" is found at index "<<i<<".";
            return 0;
        }
    }
    cout<<target<<" is not found.";
}