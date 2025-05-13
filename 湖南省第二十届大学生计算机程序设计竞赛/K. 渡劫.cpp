#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

// 边：(目标节点, 权重)
using Edge = pair<int,int>;

// Dijkstra 里用到的状态：(累计距离, 编号)
// 我们把节点 1..n 的“未用法宝”状态编号为 1..n，
// 节点 1..n 的“已用法宝”状态编号为 n+1..2n。
using State = pair<ll,int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 反向建图，用于多源 Dijkstra
    // 总共 2n 个状态
    vector<vector<Edge>> adj(2*n + 1);

    // 读隧道边，双向。正向图是
    //   (u,0)->(v,0) w；(u,0)->(v,1) 0；(u,1)->(v,1) w
    // 反向建完就对应：
    //   (v,0)->(u,0) w; (v,1)->(u,0) 0; (v,1)->(u,1) w
    // 以及同样对 (u<->v) 交换的那一条
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        // 反向：从 (v,0) 到 (u,0)
        adj[v].emplace_back(u, w);
        // 从 (v,1) 到 (u,1)
        adj[v+n].emplace_back(u+n, w);
        // 免费法宝逆用：从 (v,1) 回到 (u,0) 费用 0
        adj[v+n].emplace_back(u, 0);

        // 同理另一方向 u->v
        adj[u].emplace_back(v, w);
        adj[u+n].emplace_back(v+n, w);
        adj[u+n].emplace_back(v, 0);
    }

    // 读每个岛的渡劫消耗 a[i]
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // 距离数组，初始化 INF
    vector<ll> dist(2*n + 1, INF);
    priority_queue<State, vector<State>, greater<State>> pq;

    // 多源：每个岛的两种状态都可以“结束”于这里，代价 a[i]
    for(int i = 1; i <= n; i++){
        dist[i]   = a[i];      // 未用法宝
        dist[i+n] = a[i];      // 已用法宝（用不使用都行）
        pq.emplace(dist[i],   i);
        pq.emplace(dist[i+n], i+n);
    }

    // 标准 Dijkstra
    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        for(auto &e : adj[u]){
            int v = e.first;
            ll w = e.second;
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    // 最终答案： worst-case 初始位置 i 落在“未用法宝”状态，
    // 所需能量 = dist[i]，取最大
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dist[i]);
    }

    cout << ans << "\n";
    return 0;
}
