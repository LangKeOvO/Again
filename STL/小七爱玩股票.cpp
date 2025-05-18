#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, x, y;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> y;
    ll sum = x + y;

    vector<array<ll, 2>> a(n + 1);
    unordered_map<ll, vector<ll>> mp;
    mp.reserve(n * 2);

    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i][0];
        mp[a[i][0]].push_back(i);
        ll ttt = x / a[i][0];
        if(ttt == 0)
        {
            a[i][1] =  0;
            continue;
        }
        if(y % ttt != 0)
        {
            a[i][1] = 0;
            continue;
        }
        ll sss = ttt * a[i][0];
        //cout << ttt << " " << sss << endl;//测试
        a[i][1] = (sss + y) / ttt;
        
    }

    //测试
    // for(ll i = 1; i <= n; i++)
    // {
    //     cout << a[i][0] << " " << a[i][1] << endl;
    // }
    
    //测试map
    // for(auto it = mp.begin(); it != mp.end(); it++)
    // {
    //     cout << it->first << " : ";
    //     for(auto i : it->second)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    for(ll i = 1; i <= n; i++)
    {
        //cout << mp[a[i][1]].size() << " ";
        if(mp[a[i][1]].size() >= 1)
        {
            sort(mp[a[i][1]].begin(), mp[a[i][1]].end());
            for(auto j : mp[a[i][1]])
            {
                if(j > i)
                {
                    cout << i << " "  << j << " ";
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;


    return 0;
}