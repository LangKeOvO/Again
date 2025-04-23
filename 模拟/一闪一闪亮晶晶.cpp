//模拟
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll t, n, ans, a[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        ans = 1;
        cin >> n;
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        
        sort(a + 1, a + 1 + n);
        for(ll i = 1; i < n; i++)
        {
            if(a[i] != a[i + 1]) ans++;
        }
        cout << ans << endl;
    }
    
    return 0;
}