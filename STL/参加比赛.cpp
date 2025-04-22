#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

ll n, q, a[200005];
map<ll, ll> mp;

int main()
{
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for(ll i = n; i >= 1; i--)
    {
        if(mp[a[i] + 1]) mp[a[i]] = mp[a[i] + 1] + 1;
        else mp[a[i]] = max(1ll, mp[a[i]]);
        //if(mp[a[i] - 1] == 0) mp[a[i] - 1] = mp[a[i]] + 1;
    }

    ll tt;
    cin >> q;
    while(q--)
    {
        cin >> tt;
        cout << mp[tt] << endl;
    }
//     for(ll i = 1; i <= n; i++)
//     {
//         cout << mp[i] << " ";
//     }
    return 0;
}