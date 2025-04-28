#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

const ll maxn = 200005;

ll t, x, y;
vector<ll> a, b;


vector<ll> primer(ll n)//质因数分解，（使用试除法）
{
    vector<ll> p;

    for(ll i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            p.push_back(i);
        }
        while(n % i == 0) n /= i;
    }

    if(n > 1) p.push_back(n);

    return p;
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        if(x == 1 || y == 1)
        {
            cout << -1 << endl;
            continue;
        }

        a = primer(x);
        b = primer(y);

        ll ans1 = 0, ans2 = -1;
        ans1 = (ll)a[0] * b[0];

        ll cnt1 = 0, cnt2 = 0;
        while(cnt1 < a.size() && cnt2 < b.size())
        {
            if(a[cnt1] == b[cnt2])
            {
                ans2 = a[cnt1];
                break;
            }
            else if(a[cnt1] < b[cnt2])
            {
                cnt1++;
            }
            else cnt2++;
        }
        if(ans2 == -1) cout << ans1 << endl;
        else cout << min(ans1, ans2) << endl;
    }

    return 0;
}