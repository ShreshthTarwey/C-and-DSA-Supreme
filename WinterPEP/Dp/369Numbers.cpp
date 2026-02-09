#include <bits/stdc++.h>
long long dp[51][17][17][17][2];
using namespace std;
const int MOD = 1000000007;
int digitDp(string &s, int idx, int count3, int count6, int count9, bool limit)
{
    if(max({count3, count6, count9})>=17) return 0;
    if (idx == s.length())
    {
        // return (count3 == count6 && count6 == count9) && (count3 > 0);
        return (count3 == count6) && (count6 == count9) && (count3 > 0);
    }
    if(dp[idx][count3][count6][count9][limit]!=-1) return dp[idx][count3][count6][count9][limit];
    char high = (limit ? '9' : s[idx]);
    long long ans = 0;
    for (char c = '0'; c <= high; c++)
    {
        if (c != high)
        {
            
            ans += digitDp(s, idx + 1, count3 + (c == '3'), count6 + (c == '6'), count9 + (c=='9'), true);
            
        }
        else
        {
            ans += digitDp(s, idx + 1, count3 + (c == '3'), count6 + (c == '6'), count9 + (c=='9'), limit);
        }
        ans = ans%MOD;
    }
    return dp[idx][count3][count6][count9][limit] = (ans)%MOD;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // int a, b;
        // cin >> a >> b;
        string s, k;
        cin>>s;
        cin>>k;
        memset(dp, -1, sizeof(dp));
        // string s = to_string(a-1);
        // string k = to_string(b);
        int ans1 = digitDp(k, 0, 0, 0, 0, 0);
        memset(dp, -1, sizeof(dp));
        int ans2 = digitDp(s, 0, 0, 0, 0, 0);
        cout << ((ans1 - ans2) + MOD) % MOD << endl;
    }
}