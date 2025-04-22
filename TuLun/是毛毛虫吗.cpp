#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const ll maxn = 200005;

ll t, n, u, v, deg[maxn];
vector<ll> gg[maxn];

bool Judge()
{
    vector<ll> core;//把核心全部存起来
    vector<bool> iscore(n + 1, false);//标注每一个点是否是核心
    for(ll i = 1; i <= n; i++)
    {
        if(deg[i] >= 2)
        {
            core.push_back(i);
            iscore[i] = true;
        }
    }

    if(core.empty() || core.size() == 1) return true;//如果没有核心或者核心只有一个就必然存在

    vector<vector<ll>> inc(n + 1);
    //找一个核心V，找到它的邻接点U，如果U也是核心，就把U放进inc[v]中,也就是说inc[v]统计的是所有直接与v相连的核心；
    for(ll v : core)
        for(ll u : gg[v])
            if(iscore[u]) inc[v].push_back(u);

    vector<bool> vis(n + 1, false);
    queue<ll> qu;
    ll start = core[0];
    vis[start] = true;
    qu.push(start);
    ll cnt = 0;
    while(!qu.empty())
    {
        ll v = qu.front(); qu.pop();
        cnt++;
        for(ll u : inc[v])
        {
            if(!vis[u])
            {
                vis[u] = true;
                qu.push(u);
            }
        }
    }

    if(cnt != (ll)core.size()) return false;

    ll cnt1 = 0, cnt2 = 0;
    for (ll v : core)
    {
        ll d = inc[v].size();
        if (d == 1) cnt1++;
        else if (d == 2) cnt2++;
        else return false;
    }
 
    return (cnt1 == 2 && cnt2 == (ll)core.size() - 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;

        for(ll i = 1; i <= n; i++)
        {
            gg[i].clear();
            deg[i] = 0;
        }

        for(ll i = 1; i < n; i++)
        {
            cin >> u >> v;
            deg[u]++, deg[v]++;
            gg[u].push_back(v);
            gg[v].push_back(u);
        }
        cout << (Judge() ? "YES":"NO") << endl;
    }
    return 0;
}