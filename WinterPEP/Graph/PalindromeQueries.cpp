#include <bits/stdc++.h>
using namespace std;
int main() {
	int q;
	string s;
	cin>>q;
	cin>>s;
	int n = s.length();
	vector<vector<int>>mat(s.length()+1, vector<int>(26, 0));

	for(int i=0;i<n;i++){
		mat[i][s[i]-'a']+=1;
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<26;j++){
			mat[i][j] += mat[i-1][j];
		}
	}

	for(int i=0;i<q;i++){
		int l,r; cin>>l>>r;
		--l; --r;
		int cnt = 0;

		for(int j=0;j<26;j++){
			int currCnt = mat[r][j] - (l - 1 < 0 ? 0 : mat[l-1][j]);
			if(currCnt%2!=0) cnt++;
		}
		int len = r - l + 1;
		if(cnt<2 && cnt %2 == len%2){
			cout<<"Possible"<<"\n";
		}
		else{
			cout<<"Impossible"<<"\n";
		}
	}
}