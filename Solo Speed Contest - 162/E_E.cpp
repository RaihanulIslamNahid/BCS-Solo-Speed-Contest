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
void dfs(int node, const vvi &adj, vector<bool> &vis, vector<int> &com)
{
    vis[node] = true;
    com.push_back(node);
    for (int neighbor : adj[node])
    {
        if (!vis[neighbor])
        {
            dfs(neighbor, adj, vis, com);
        }
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vi colors(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> colors[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int li, ri;
        cin >> li >> ri;
        adj[li].push_back(ri);
        adj[ri].push_back(li);
    }

    vector<bool> vis(n + 1, false);
    int total = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            vector<int> com;
            dfs(i, adj, vis, com);

            unordered_map<int, int> color_count;
            for (int sock : com)
            {
                color_count[colors[sock]]++;
            }

            int temp = 0;
            for (auto &entry : color_count)
            {
                temp = max(temp, entry.second);
            }
            total += (com.size() - temp);
        }
    }

    cout << total << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    // cin >> T;
    // while (T--)
    {
        solve();
    }
    return 0;
}
