//https://ac.nowcoder.com/acm/contest/108038/E
//模拟
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<ll> r(n), c(m);
    ll c1 = 0;
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
        for(ll j = 0; j < m; j++)
        {
            if(a[i][j] == '1')
            {
                r[i]++;//每行1的个数
                c[j]++;//每列1的个数
                c1++;//1的个数
            }
        }
    }

    ll cr = 0;
    for(ll i = 0; i < n; i++) cr += (r[i] == m);//整行都是1的行数
    ll cc = 0;
    for(ll j = 0; j < m; j++) cc += (c[j] == n);//整列都是1的列数

    ll f = 0;
    for(ll i = 0; i < n; i++)
    {
        if(c1 != n + m - 2) break;
        for(ll j = 0; j < m; j++)
        {
            if(a[i][j] == '1') continue;
            if(r[i] == m - 1 && c[j] == n - 1)
            {
                f++;
                break;
            }
        }
        if(f) break;
    }

    if(c1 == 0 || (cr == 2 && c1 == m * 2) || (cc == 2 && c1 == n* 2) || f == 1) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    while(T--)
    {
        solve();
    }

    return 0;
}