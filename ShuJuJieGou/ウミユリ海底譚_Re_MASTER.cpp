//二分找值 海拔线
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll maxn = 1e9 + 1;

ll t, n, p;
vector<ll> a;
vector<ll> b;

ll erfen(ll xx) {
    ll sum = 0, zui = 0;
    for (ll i = 0; i < n; i++)
    {
        if (b[i] > xx)
        {
            zui = max(zui, sum);
            sum = 0;
        }
        else
        {
            if (a[i] >= 0)
            {
                sum += a[i];
            }
            else
            {
                zui = max(zui, sum); // 记录之前的sum
                if (sum + a[i] >= 0)
                {
                    sum += a[i];
                }
                else
                {
                    sum = 0;
                }
            }
        }
        zui = max(zui, sum); // 每次循环后更新最大值
    }
    return zui;
}

void solve() {
    cin >> n >> p;
    a.clear();
    b.clear();
    for (ll i = 0; i < n; i++) {
        ll tt, pp;
        cin >> tt >> pp;
        a.push_back(tt);
        b.push_back(pp);
    }

    ll left = 0, right = maxn;
    ll ans = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll val = erfen(mid);
        if (val >= p) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}