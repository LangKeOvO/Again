//利用快速幂+逆元求组合数

#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll n, k, fa[10005], ga[10005];
string str;

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

ll ans(ll aa, ll m)
{
    return fa[aa] * ga[m] % mod * ga[aa - m] % mod;
}//组合数计算公式

void solve()
{
    cin >> n >> k >> str;
    str = '#' + str;

    fa[0] = ga[0] = 1;
    for(ll i = 1; i <= n; i++)
    {
        fa[i] = fa[i - 1] * i % mod;
        ga[i] = ga[i - 1] * fastpow(i, mod - 2) % mod;
    }//fa数组为阶乘， ga表示逆元。

    ll suma = 0, sumb = 0;
    for(ll i = 1; i <= n; i++)
    {
        if(str[i] == 'a')
        {
            suma++;
        }
    }

    if(suma >= k)
    {
        //cout << 1 << endl;
        //cout << suma << " " << k << endl;
        cout << ans(suma, k);
    }
    else
    {
        ll idx = 0;
        k -= suma;
        for(ll i = n; i >= 1; i--)
        {
            if(i != 1 && str[i] == 'b')
            {
                sumb++;
            }
            else
            {
                if(i == 1 && str[i] == 'b') sumb++;
                if(k <= sumb)
                {
                    //cout << 2 << endl;
                    cout << ans(sumb, k);
                    return;
                }
                k -= sumb;
                sumb = 0;
            }
        }
    }

}

int main()
{
    int T = 1;
    while(T--)
    {
        solve();
    }

    return 0;
}