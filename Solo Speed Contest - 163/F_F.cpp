#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define f1(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define dbg(var) cout << #var << "=" << var << " "
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define all(v) sort(v.begin(), v.end())          // sort
#define mx_e(v) *max_element(v.begin(), v.end()) // find max element in vector
#define mn_e(v) *min_element(v.begin(), v.end()) // find min element in vector
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
#define bin(x, y) bitset<y>(x)
using namespace std;
int MOD = 1e9 + 7; // Hardcoded, directly change from here for functions!

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }
// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
// ===================================END Of the input module ==========================================

void solve()
{
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    string s1 = s[0];
    for (int i = 1; i < n; ++i)
    {
        if (s[i].size() < s1.size())
        {
            s1 = s[i];
        }
    }

    string str;
    int ss = s1.size();
    for (int i = 0; i < ss; ++i)
    {
        for (int j = i + 1; j <= ss; ++j)
        {
            string str1 = s1.substr(i, j - i);
            bool flag = true;
            for (const string &word : s)
            {
                if (word.find(str1) == string::npos)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                if (str1.size() > str.size() ||
                    (str1.size() == str.size() && str1 < str))
                {
                    str = str1;
                }
            }
        }
    }

    cout << str << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
