//https://ac.nowcoder.com/acm/contest/108038/F
//线性筛求模逆元+快速分解质因数中2的个数
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll mod = 998244353;

int main()
{
    ll T;
    cin >> T;
    vector<ll> qs(T + 1);

    ll maxn = 0;
    for(ll i = 1; i <= T; i++)
    {
        cin >> qs[i];
        maxn = max(maxn, qs[i]);
    }

    vector<ll> vi2(maxn + 1, 0);
    vector<ll> ei2(maxn + 1, 0);

    for(ll i = 1; i <= maxn; i++)
    {
        if(i & 1) vi2[i] = 0;
        else vi2[i] = vi2[i >> 1] + 1;

        ei2[i] = ei2[i - 1] + vi2[i];
    }

    ll maxe = ei2[maxn] + 1;
    vector<ll> inv(maxe + 1, 0);
    inv[1] = 1;
    for(ll i = 2; i <= maxn; i++)
    {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    
    for(ll i = 1; i <= T; i++)
    {
        ll n = qs[i];
        ll ans = ei2[n] + 1;
        cout << inv[ans] << " ";
    }


    return 0;
}