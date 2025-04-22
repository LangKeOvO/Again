#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
ll m, n, ans;

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
    cin >> m >> n;
    ll to = fastpow(m, n) % mod;
    ll ans = (to + mod - m) % mod;
    cout << ans % mod;
    
    return 0;
}