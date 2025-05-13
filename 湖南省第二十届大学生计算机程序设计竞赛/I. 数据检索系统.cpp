#include <bits/stdc++.h>

using namespace std;

int n, k, m, q;
map<long long, int> mp;

int main()
{
    cin >> n >> k >> m >> q;
    for(int i = 1; i <= m; i++)
    {
        long long x, y;
        cin >> x;
        y = x;
        for(int j = 1; j <= k; j++)
        {
            y %= n;
            mp[y] = 1;
            y *= x;
        }
    }

    for(int i = 1; i <= q; i++)
    {
        long long x, y;
        cin >> x;
        y = x;
        bool flag = true;
        for(int j = 1; j <= k; j++)
        {
            y %= n;
            if(mp[y] == 0)
            {
                flag = false;
                break;
            }
            y *= x;
        }

        if(flag)
            cout << "1 ";
        else
            cout << "0 ";
    }

    return 0;
}