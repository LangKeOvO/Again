//树上BFS
//https://ac.nowcoder.com/acm/contest/107458/B
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

ll n, m;

int main()
{
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<ll> V_nodes(m + 1);
    vector<ll> parent(n + 1, 0), vis(n + 1,0);

    for(ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[y].push_back(x);
        adj[x].push_back(y);
    }

    for(ll i = 0; i < m; i++)
    {
        cin >> V_nodes[i];
    }

    ll root = V_nodes[0];
    
    queue<ll> q;
    q.push(root);
    vis[root] = 1;
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        for(ll v : adj[u])
        {
            if(!vis[v])
            {
                vis[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    cout << m - 1 << endl;
    for(ll i = 1; i < m; i++)
    {
        ll s = V_nodes[i];
        cout << s << " " << parent[s] << endl;
    }

    return 0;
}