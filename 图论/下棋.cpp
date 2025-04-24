//BFS加树的存储


#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> arr(n + 1);
    vector<ll> qrr(n + 1);
    
    for(ll i = 2; i <= n; i++)
    {
        ll x; cin >> x;
        arr[x].push_back(i);
    }
    
    for(ll i = 1; i <= n; i++) cin >> qrr[i];
    
    queue<pair<ll,ll>> q;
    q.push({1, 1});
    while(!q.empty())
    {
        pair<ll,ll> tt = q.front(); q.pop();
        ll maxx = 0, cnt = 200005;
        if(tt.second & 1)
        {
            maxx = INT_MIN;
            for(ll x : arr[tt.first])
            {
                if(qrr[x] > maxx)
                {
                    maxx = qrr[x];
                    cnt = x;
                }
                else if(qrr[x] == maxx) cnt = min(cnt, x);
            }
        }
        else
        {
            maxx = INT_MAX;
            for(ll x : arr[tt.first])
            {
                if(qrr[x] < maxx)
                {
                    maxx = qrr[x];
                    cnt = x;
                }
                else if(qrr[x] == maxx) cnt = min(cnt, x);
            }
        }
        if(cnt != 200005)
        {
            q.push({cnt, tt.second + 1});
            k += maxx;
            //cout << k << endl;
        }
    }
    cout << k << endl;
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