//https://ac.nowcoder.com/acm/contest/110273/A
//NTT+快速幂卷积+多项式相乘
#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;  // 质数模数
const int g = 3;            // 原根

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1LL * res * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return res;
}

// NTT 核心
void ntt(vector<int>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = power(g, (mod - 1) / len);
        if (invert) wlen = power(wlen, mod - 2);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j], v = 1LL * a[i + j + len / 2] * w % mod;
                a[i + j] = (u + v) % mod;
                a[i + j + len / 2] = (u - v + mod) % mod;
                w = 1LL * w * wlen % mod;
            }
        }
    }
    if (invert) {
        int inv_n = power(n, mod - 2);
        for (int &x : a) x = 1LL * x * inv_n % mod;
    }
}

// 多项式乘法
vector<int> multiply(vector<int> a, vector<int> b) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    a.resize(n); b.resize(n);
    ntt(a, false); ntt(b, false);
    for (int i = 0; i < n; ++i)
        a[i] = 1LL * a[i] * b[i] % mod;
    ntt(a, true);
    return a;
}

// 多项式快速幂
vector<int> poly_power(vector<int> base, int exp, int limit) {
    vector<int> res = {1};
    while (exp) {
        if (exp & 1) {
            res = multiply(res, base);
            if ((int)res.size() > limit + 1) res.resize(limit + 1);
        }
        base = multiply(base, base);
        if ((int)base.size() > limit + 1) base.resize(limit + 1);
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    vector<int> f(m + 1, 0);
    for (int v : b)
        if (v <= m)
            f[v] = 1;

    auto res = poly_power(f, n, m);
    cout << ((m < res.size() && res[m] > 0) ? "YES" : "NO") << '\n';
    return 0;
}
