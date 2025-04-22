#include <iostream>

using namespace std;

unsigned long long n, cnt, ans;
char m[100];

int main()
{
    cin >> n;
    while(n)
    {
        ans = n % 26;
        if(ans == 0) {
            m[cnt++] = 'z';
            n = (n - 1) / 26; // 关键修正：处理余数为0时调整n的值
        } else {
            m[cnt++] = (char)('a' + ans - 1);
            n /= 26;
        }
    }
    for(int i = cnt - 1; i >= 0; i--) {
        cout << m[i];
    }
    return 0;
}