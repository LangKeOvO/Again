//二分
//牛客http://ac.nowcoder.com/acm/contest/107500/D

#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

const ll N = 2e5 + 5;
ll n, k, ans, maxx;
string str;

struct solve
{
    ll cnt2, cnt5, id, cnt25;
}a[N];

bool check(ll mid)
{
    ll now = 1, cn2 = 0, cn25 = 0;
    for(ll i = 1; i <= n; i++)
    {
        cn25 += cn2 * a[i].cnt5 + a[i].cnt25;
        cn2 += a[i].cnt2;
        if(cn25 > mid)
        {
            now++;
            cn2 = a[i].cnt2;
            cn25 = a[i].cnt25;
        }
    }
    return now <= k;
}

int main()
{
    cin >> n >> k;
    for(ll i = 1; i <= n; i++)
    {
        cin >> str;
        a[i].id = i;
        for(ll j = 0; j < str.size(); j++)
        {
            if(str[j] == '2') a[i].cnt2++;
            else if(str[j] == '5')
            {
                a[i].cnt25 += a[i].cnt2;
                a[i].cnt5++;
            }
        }
        maxx = max(maxx, a[i].cnt25);
    }
    
    ll l = maxx, r = 1e15;
    while(l <= r)
    {
        ll mid = (l + r) >> 1;
        if(check(mid)) 
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    cout << ans;
    return 0;
}