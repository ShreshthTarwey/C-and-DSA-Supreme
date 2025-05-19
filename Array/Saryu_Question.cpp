#include <iostream>
// #include<unordered_map>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    // int arr[n];
    vector<int>arr(n);
    int maxVal = INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        maxVal = max(maxVal,arr[i]);
    }
    // unordered_map<int,int> map;
    vector<int> freq(maxVal+1,0);
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    int ans = 0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        if(freq[arr[i]]>0 && freq[arr[i]]%2!=0)
        {
            // cout<<freq[arr[i]]<<" ";
            ans+=arr[i];
            // ans+=freq[arr[i]];
            // i+=freq[arr[i]]-1;
            freq[arr[i]] = 0;
        }
      
    }
    cout<<ans;

}
