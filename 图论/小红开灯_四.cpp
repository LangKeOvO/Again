//https://ac.nowcoder.com/acm/contest/107000/E
//bfs建生成树，dfs后序遍历
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;
typedef long long ll;

ll n, m, zero_cnt;
vector<bool> state;
vector<ll> parent_node;
vector<vector<ll>> child_node;
vector<array<ll, 4>> ops;

inline pii id2pos(int u) {
    return {u / m, u % m};
}

void dfs(ll u)
{
    for(auto v : child_node[u])
    {
        dfs(v);
        if(!state[v])
        {
            auto [x, y] = id2pos(v);
            auto [px, py] = id2pos(u);
            ops.push_back({x + 1, y + 1, px + 1, py + 1});
            state[v] = true;
            state[u] = !state[u];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    state.assign(n * m, false);
    for(ll i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for(ll j = 0; j < m; j++)
        {
            bool on = (row[j] == '1');
            state[i * m + j] = on;
            if(!on) zero_cnt++;
        }
    }

    if(zero_cnt & 1)
    {
        cout << "-1\n";
        return 0;
    }

    parent_node.assign(n * m, -1);
    child_node.assign(n * m, vector<ll>());
    vector<char> vis(n * m, 0);
    queue<ll> q;
    ll root = 0;
    q.push(root);
    vis[root] = 1;
    ll dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

    while(!q.empty())
    {
        ll te = q.front(); q.pop();
        ll x = te / m, y = te % m;
        for(ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            ll nt = nx * m + ny;
            if(!vis[nt])
            {
                vis[nt] = 1;
                parent_node[nt] = te;
                child_node[te].push_back(nt);
                q.push(nt);
            }
        }
    }

    dfs(root);

    cout << ops.size() << "\n";
    for (auto &t : ops) {
        cout << t[0] << " " << t[1] << " "
             << t[2] << " " << t[3] << "\n";
    }

    return 0;
}