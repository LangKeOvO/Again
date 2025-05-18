#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll te, gcdd, cnt = 0;
    map<ll, ll > mp;
    while(n--)
    {
        ll ju = 0;
        cin >> te;
        cnt++;
        mp[te]++;
        if(cnt == 1) 
        {
            gcdd = te;
        }
        
        gcdd = __gcd(gcdd, te);
        if(cnt >= 14)
        {
            ll ans1 = mp[gcdd] / 8;
            ll ans2 = mp[2 * gcdd] / 3;
            ll ans3 = mp[3 * gcdd] / 2;
            ll ans5 = mp[5 * gcdd] / 1;
            ju = min(ans1, min(ans2, min(ans3, ans5)));
        }
        cout << ju << " ";
    }

    return 0;
}