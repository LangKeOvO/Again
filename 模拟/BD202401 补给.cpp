//https://www.matiji.net/exam/brushquestion/1/4498/F16DA07A4D99E21DFFEF46BD18FF68AD?from=1
//贪心+排序
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N, B;

struct solve
{
    ll pi, si, sum, ans;
}a[1005];

bool cmp1(solve a, solve b)
{
    return a.ans < b.ans;
}

bool cmp2(solve a, solve b)
{
    return a.sum < b.sum;
}

int main()
{
    cin >> N >> B;
    for(int i = 1; i <= N; i++)
    {
        cin >> a[i].pi >> a[i].si;
        a[i].sum = a[i].pi / 2 + a[i].si;
        a[i].ans = a[i].pi + a[i].si;
    }
    sort(a + 1, a + N + 1, cmp1);
    ll idx = 0;
    for(int i = 1; i <= N; i++)
    {
        if(B >= a[i].ans)
        {
            B -= a[i].ans;
        }
        else
        {
            idx = i;
            break;
        }
    }
    sort(a + idx, a + N + 1, cmp2);
    for(int i = idx; i <= N; i++)
    {
        if(B >= a[i].sum)
        {
            B -= a[i].sum;
        }
        else
        {
            cout << i - 1 << endl;
            break;
        }
    }
    return 0;
}