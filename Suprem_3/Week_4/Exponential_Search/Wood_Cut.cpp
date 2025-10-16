#include <bits/stdc++.h>
using namespace std;
long long cutWood(vector<int>&arr,int mid){
	long long sum = 0;
	for(int i=0;i<arr.size();i++){
		if(arr[i]>mid){
			sum+=arr[i]-mid;
		}
	}
	return sum;
}
int main() {
	// your code goes here
	int n;
    long long m;
	cin>>n>>m;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int r = *max_element(arr.begin(),arr.end());
	int l = 0;
	int ans = -1;
	while(l<=r){
		int mid = (l+r)>>1;
		long long woodCut = cutWood(arr,mid);
		if(woodCut>=m){
			ans = mid;
			l=mid+1;
		}
		else{
			r = mid-1;
		}
	}
	cout<<ans;
	return 0;
}