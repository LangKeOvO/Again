#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

ll t, n, a, b, kk, jj, ans;
string str;

int main()
{
    cin >> t;
    while(t--)
    {
        kk = 0, jj = 0, ans = 0;
        bool gun = false;
        cin >> n >> a >> b >> str;
        for(ll i = 0; i < n; i++)
        {
            if(str[i] == 'K') kk++;
            else jj++;
        }
        ll ans1 = 0, ans2 = 0;
        if(jj) ans1 = 2 * b * (jj - 1);
        if(str[n - 1] == 'K' && jj) ans2 = (kk - 1) * a + b;
        else ans2 = kk * a;
        ans = max(a * n, ans1 + ans2);//关键步骤：贪心都要注意
        cout << ans << endl;
    }

    return 0;
}