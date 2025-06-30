#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        // int i=-1;
        vector<int>arr2 = arr;
        sort(arr2.begin(),arr2.end());
        int j=0;
        int mis_match = 0;
        for(int i=0;i<n;i++){
            if(arr[i]!=arr2[i]){
                mis_match++;
            }
        }
        if (arr == arr2)
    cout << "YES"<<endl;
else if (k == 1)
    cout << "NO"<<endl;
else
    cout << "YES"<<endl;

    }
}