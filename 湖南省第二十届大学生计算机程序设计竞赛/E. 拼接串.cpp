#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0, mask = 1 << 18;
    cin >> n;
    vector<int> a(n + 1), dp(1 << 18, 0);

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = i, s = 0; j <= n; j++)
        {
            if(s >> (a[j] - 1) & 1) break;
            s |= 1 << (a[j] - 1);
            dp[s] = max(dp[s], j - i + 1);
            ans = max(ans, dp[s]);
        }
    }

    for(int i = 0; i < mask; i++)
    {
        for(int j = i; j > 0; j = (j - 1) & i)
        {
            ans = max(ans, dp[i ^ j] + dp[j]);
        }
    }

    cout << ans << endl;
    return 0;
}