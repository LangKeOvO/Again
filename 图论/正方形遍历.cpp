//欧拉回路
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 100010;

ll n, idx;

vector<vector<pair<ll, ll>>> edge(N);
vector<bool> vis(N);
vector<ll> ans;

void add(ll u, ll v)
{
	edge[u].push_back({v, idx});
	edge[v].push_back({u, idx++});
}

// void dfs(ll u)
// {
// 	for(auto [v, vi] : edge[u])
// 	{
// 		if(vis[vi]) continue;
// 		vis[vi] = true;
		
// 		dfs(v);
// 	}
// 	ans.push_back(u);
// }

void dfs(ll u)
{
    while (!edge[u].empty())
    {
        auto [v, vi] = edge[u].back();
        edge[u].pop_back(); // 移除已访问的边
        if (vis[vi]) continue;
        vis[vi] = true;
        dfs(v);
    }
    ans.push_back(u); // 回溯时加入结果
}

int main()
{
	cin >> n;
	n = n + 1;

	for(ll i = 1; i < n * n; i++)
	{
		if(i % n == 0) continue;
		add(i, i + 1);
	}
	for(ll i = 1; i < n * n; i++)
	{
		if(i > n * (n - 1)) continue;
		add(i, i + n);
	}

	for(ll i = 1; i <= n * n; i++)
	{
		if(((i - 1) % n == 0) || (i > n * (n - 1))) continue;
		if(i == n || ((i + i / n) % n == 0)) continue;
		add(i, i + n - 1);
	}
	
// 	for(ll i = 1; i <= n * n; i++)
// 	{
// 		for(auto [v, vi] : edge[i])
// 		{
// 			cout << v << " ";
// 		}
// 		cout << endl;
// 	}

	dfs(1);

	cout << "Yes" << endl;
	for(auto v : ans)
	{
		cout << v << " ";
	}
	
	return 0;
}