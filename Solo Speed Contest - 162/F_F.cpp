#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 400010;
const int MOD = 1e9 + 7;

ll bigMod(ll a, ll e)
{
    if (e == -1)
        e = MOD - 2;
    ll ret = 1;
    while (e)
    {
        if (e & 1)
            ret = ret * a % MOD;
        a = a * a % MOD, e >>= 1;
    }
    return ret;
}

int t, n;
char a[N], b[N];
long long fac[N], inv[N];

int main()
{
    fac[0] = 1;
    for (int i = 1; i < N; ++i)
        fac[i] = i * fac[i - 1] % MOD;
    inv[N - 1] = bigMod(fac[N - 1], -1);
    for (int i = N - 1; i; --i)
        inv[i - 1] = i * inv[i] % MOD;
    cin >> t;
    while (t--)
    {
        scanf("%d %s %s", &n, a + 1, b + 1);
        int match = 0;
        for (int i = 1; i <= n; ++i)
            match += (a[i] == b[i]);
        int miss = n - match;
        if (miss & 1)
        {
            puts("0");
            continue;
        }
        long long ans = 1;
        while (match--)
            ans = ans * 2 % MOD;
        ans = ans * fac[miss] % MOD * inv[miss / 2] % MOD * inv[miss / 2] % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
