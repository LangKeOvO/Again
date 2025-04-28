#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
unsigned long long t, n, p, q;

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

void solve() {
    cin >> n >> p >> q;
    
    ll ans = 2 * p * q;
    ll gd = __gcd(10000LL, ans);
    
    ll q = ans / gd;   // 分子 q
    ll p = 10000 / gd;  // 分母 p
    
    q = fastpow(q, n);
    p = fastpow(p, n);
    
    p = fastpow(p, mod - 2);
    cout << (q * p) % mod << endl;
}
int main()
{
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}