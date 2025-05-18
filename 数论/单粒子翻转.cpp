#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 998244353;

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
}//快速幂

int main()
{
    ll n;
    string str;
    cin >> n >> str;
    ll ans = 0;
    ll pow2_n = fastpow(2, n);
    ll pow1_2 = fastpow(2, mod - 2);

    ans = (pow2_n - 1) * pow1_2 % mod;
    cout << ans << endl;
    return 0;
}