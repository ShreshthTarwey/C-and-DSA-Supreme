#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    // cin.ignore();
    while (q--)
    {
        string s, t;
        int len;
        cin>>len;
        cin >> s >> t;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}