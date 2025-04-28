//https://ac.nowcoder.com/acm/contest/107458/C
//快速幂+组合数（帕斯卡三角）+记忆化数组+位运算拆分
#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 998244353;
const ll K = 5e3 + 10;
ll n, m, k, x, c[K][K];


void psk()
{
    for(ll i = 0; i < K; i++)
    {
        c[i][0] = 1;
        for(ll j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
        }
    }
}

ll qsm(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    cin >> n >> x >> m >> k;

    psk();
    ll ffz = qsm(qsm(2, k), mod - 2);

    ll p = 1;
    while(p <= m) p <<= 1;

    static ll b[1 << 13];
    static bool vis[1 << 13];

    ll ans = 0;
    for(ll i = 1; i <= n; i++)
    {
        ll v0;
        cin >> v0;
        ll y0 = v0 % p;
        ll z = v0 - y0;
        if(vis[y0]) ans = (ans + z + b[y0]) % mod;
        else
        {
            ll sum = y0;
            ll y = y0;
            for(ll j = 1; j <= k; j++)
            {
                y = y + (y & m) + x;
                sum = (sum + y * c[k][j] % mod) % mod;
            }
            sum = sum * ffz % mod;

            b[y0] = sum;
            vis[y0] = true;
            ans = (ans + z + sum) % mod;
        }
    }
    cout << ans << endl;
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