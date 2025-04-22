#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll n, q, u, v;
vector<vector<ll>> lin;
vector<ll> dep, fa, a, w;
vector<pair<ll, ll>> f;

void LCA(ll x, ll y)
{
	if(dep[x] < dep[y]) swap(x, y);
	
}

int main()
{
	cin >> n;

	lin.assign(n + 1, vector<ll>());
	dep.assign(n + 1, 0);
	fa.assign(n + 1, 0);
	a.assign(n + 1, 0);
	w.assign(n + 1, 0);
	f.assign(n + 1, pair<ll, ll>());

	for(ll i = 1; i <= n; i++)
	{
		cin >> u >> v;
		lin[u].push_back(v);
		lin[v].push_back(u);
	}



	return 0;
}