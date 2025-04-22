#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;
#define PII pair<ll, ll>

const ll N = 1005;
ll n, m, k, xf, yf, of, xq, yq, xz, yz, sum;
char a[N][N], tt;

void solve()
{
    queue<PII> q;

    q.push({xq, yq});
    while(!q.empty())
    {
        PII tem = q.front();
        


    }
}

int main()
{
    cin >> n>> m >> k;
    sum = k;

    for(ll i = 1; i = n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            cin >> tt;
            if(tt = '.') a[i][j] = 0;
            else if(tt = '#') a[i][j] = -1;
            else if(tt = 'S') xq = i, yq = j, a[i][j] = 0;
            else if(tt = 'E') xz = i, yz = j, a[i][j] = 0;
        }
    }

    for(ll i = 1; i <= k; i++)
    {
        cin >> xf >> yf >> of;
        a[xf][yf] = -2;
        if(of == 1) for(ll i = 1; i < xf; i++) a[i][yf]++;
        else if(of == 2) for(ll j = 1; j < yf; j++) a[xf][j]++;
        else if(of == 3) for(ll i = n; i > xf; i--) a[i][yf]++;
        else if(of == 4) for(ll j = m; j > yf; j--) a[xf][j]++;
    }

    solve();

    return 0;
}