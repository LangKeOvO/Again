#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

int main()
{
    long long ans = 1, n, k;
    cin >> n >> k;
    for(long long i = 1; i <= n - k + 1; i++)
    {
        ans = (ans * 2) % mod;
    }

    cout << ans % mod << endl;
    return 0;
}