#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
ll n, ans, m;
vector<ll> a;

// vector<ll> primer(ll n)
// {
//     vector<ll> p(n + 1, 0);
//     vector<ll> pri(n + 1, 0);
//     for(ll i = 2; i <= n; i++)
//     {
//         if(p[i] == 0)
//         {
//             p[i] = i;
//             pri[++m] = i;
//         }
//         for(ll j = 1; j <= m && pri[j] <= p[i] && i * pri[j] <= n; j++)
//         {
//             p[i * pri[j]] = pri[j];
//         }
//     }
//     return pri;
// }

vector<ll> primer(ll n)
{
    vector<ll> v(n + 1, 0);
    vector<ll> pri(n + 1, 0);
    for(ll i = 2; i <= n; i++)
    {
        if(v[i]) continue;
        pri[++m] = i;
        for(ll j = i; j <= n / i; j++)
        {
            v[i * j] = 1;
        }
    }
    return pri;
}

int main()
{
    cin >> n;

    a = primer(n);

    // for(ll i = 1; i <= m; i++)
    // {
    //     cout << a[i] << " ";
    // }
    for(ll i = 1; i <= m; i++)
    {
        ll x = n / a[i];;
        ans += x * a[i];
        ans %= mod;
    }
    cout << ans;
    return 0;
}