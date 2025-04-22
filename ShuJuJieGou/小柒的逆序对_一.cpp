#include <iostream>

using namespace std;

typedef long long ll;

const ll N = 1e5 + 5;
ll n, m, q, id1, id2, c[N], sum;

struct solve
{
    ll val, ans;
}a[N];

ll ask(ll x)
{
    ll ans = 0;
    for(; x; x -= x & -x) ans += c[x];
    return ans;
}

void add(ll x, ll y)
{
    for(; x <= n; x += x & -x) c[x] += y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i].val;
    }

    for(ll i = n; i; i--)
    {
        sum += ask(a[i].val - 1);
        add(a[i].val, 1);
    }

    //for(ll i = 1; i <= n; i++) cout << a[i].ans << " ";

    while(q--)
    {
        cin >> id1 >> id2;
        ll te1, te2, te3, te4;
        if(id1 > id2) swap(id1, id2);

        for(ll i = id2; i >= id1; i--)
        {
            te1 += ask(a[i].val - 1);
            
        }

        swap(a[id1], a[id2]);
        



        // if(m & 1) cout << "odd";
        // else cout << "even";
        // cout << '\n';
    }

    return 0;
}