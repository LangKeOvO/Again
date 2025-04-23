//模拟
#include <iostream>

using namespace std;

typedef long long ll;

ll t, n, res[1000005], te;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        te = n;
        ll i = 1, j = n;
        res[j--] = n--;
        bool tt = true;
        while(n)
        {
            if(tt)
            {
                if(i < j) res[i++] = n--;
                else break;
                if(i < j) res[i++] = n--;
                else break;
                tt = false;
            }
            else
            {
                if(j > i) res[j--] = n--;
                else break;
                if(j > i) res[j--] = n--;
                else break;
                tt = true;
            }
        }
        if(i == j) res[i] = 1;

        for(ll k = 1; k <= te; k++)
        {
            cout << res[k] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}