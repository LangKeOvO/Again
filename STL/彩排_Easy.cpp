//优先队列排序

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
#define PII pair<ll, ll>

const ll N = 2e5 + 5;
ll n;

struct solve
{
    ll val, en, ex, ans, idx;
}arr[N];

bool cmp1(solve aa, solve bb)
{
    return aa.en < bb.en;
}

bool cmp2(solve aa, solve bb)
{
    return aa.idx < bb.idx;
}

int main()
{
    cin >> n;
    
    for(ll i = 1; i <= n; i++)
    {
        cin >> arr[i].val >> arr[i].en >> arr[i].ex;
        arr[i].idx = i;
    }

    sort(arr + 1, arr + 1 + n, cmp1);

    priority_queue<PII, vector<PII>, greater<PII>> q;
    for(ll i = 1; i <= n; i++)
    {
        while(!q.empty())
        {
            auto [c, r] = q.top();
            if(r <= arr[i].en)
            {
                q.pop();
                continue;
            }
            if(arr[i].val > c)
            {
                arr[i].ans = arr[i].val - c;
            }
            break;
        }
        q.push({arr[i].val, arr[i].ex});
    }

    sort(arr + 1, arr + 1 + n, cmp2);
    for(ll i = 1; i <= n; i++) cout << arr[i].ans << " ";
    return 0;
}