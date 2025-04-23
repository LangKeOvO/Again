#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
ll n, ans;
int main()
{
    cin >> n;
    vector<ll> val(n + 1);
    for(ll i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    vector<ll> dep(n + 1);
    for(ll i = 1; i <= n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        dep[x]++;
        dep[y]++;
    }

    if(n == 1)
    {
        cout << 2 * val[1];
        return 0;
    }

    ll cnt = 0, mixx = inf;
    for(ll i = 1; i <= n; i++)
    {
        if(dep[i] == 1)
        {
            cnt++;
            ans += val[i];
        }
        mixx = min(mixx, val[i]);
    }

    if(cnt & 1)
    {
        ans += 2 * mixx;
    }

    cout << ans;
    return 0;
}