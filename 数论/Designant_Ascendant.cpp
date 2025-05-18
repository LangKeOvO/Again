//https://ac.nowcoder.com/acm/contest/110273/D
//快速幂+模逆元求组合数+map+（*多次取模*重点）
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;
ll n, F[N], G[N], maxx;
unordered_map<ll, ll> mp;

ll fastpow(ll base, ll pow)
{
    ll res = 1;
    while(pow)
    {
        if(pow & 1) res = res * base % mod;
        pow >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

ll ccc(ll a, ll b)
{
    return F[a] * G[b] % mod * G[a - b] % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    F[0] = G[0] = 1;
    for(ll i = 1; i <= n; i++)
    {
        F[i] = F[i - 1] * i % mod;
        G[i] = G[i - 1] * fastpow(i, mod - 2) % mod;
    }

    vector<ll> a(n + 1);

    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        mp[a[i]]++;
    }

    ll ans = 0;
    for(auto &[x, c] : mp)
    {
        if(c >= 8)
        {
            ans += ccc(c, 8) % mod;
            ans %= mod;
            for(ll k = 2; k <= min(c - 6, maxx / x); k++)
            {
                if(mp.count(k * x))
                {
                    ans += ccc(c, 6 + k) % mod * ccc(mp[k * x], 1) % mod;
                    ans %= mod;
                }
            }
        }
    }
    ans %= mod;
    cout << ans;
    return 0;
}