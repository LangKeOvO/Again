//https://ac.nowcoder.com/acm/contest/107500/F
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll n;
int main()
{
    cin >> n;
    vector<ll> a(n + 1);

    ll d = 2;
    while((d << 1) <= n)
    {
        d <<= 1;
    }

    ll l = n;
    while(d && l)
    {
        while(d > l)
        {
            d >>= 1;
        }

        ll i = 0;
        while(d + i <= l)
        {
            a[d + i] = d - i - 1;
            a[d - i - 1] = d + i;
            i++;
        }
        l = d - i - 1;
        d >>= 1;
    }

    for(ll i = 1; i <= n; i++)
    {
        ll ans;
        cin >> ans;
        cout << a[ans] << " ";
    }

    return 0;
}