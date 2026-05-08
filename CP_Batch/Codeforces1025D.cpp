#include <bits/stdc++.h>

using namespace std;

bool canMake(vector<int> &arr, int side, int l, int r, vector<vector<vector<int>>> &dp, vector<vector<int>>& good)
{
    if (l > r)
    {
        return true;
    }
    if (dp[l][r][side] != -1)
        return dp[l][r][side];
    for (int i = l; i <= r; i++)
    {
        if (side == 0) {
    if (r + 1 < arr.size() && !good[r+1][i]) continue;
} else {
    if (l - 1 >= 0 && !good[l-1][i]) continue;
}

        bool left = canMake(arr, 0, l, i - 1, dp, good);
        bool right = canMake(arr, 1, i + 1, r, dp, good);
        if (left && right)
        {
            return dp[l][r][side] = true;
        }
    }
    return dp[l][r][side] = false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0;
    int r = n - 1;
    vector<vector<int>> good(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            good[i][j] = (__gcd(arr[i], arr[j]) > 1);
        }
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    for (int i = 0; i < n; i++)
    {
        if (canMake(arr, 0, l, i - 1, dp, good) && canMake(arr, 1, i + 1, r, dp, good))
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}