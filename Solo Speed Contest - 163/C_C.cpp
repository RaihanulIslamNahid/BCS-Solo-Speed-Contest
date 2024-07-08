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
    int H, W;
    cin >> H >> W;
    vector<string> G(H);

    for (int i = 0; i < H; ++i)
    {
        cin >> G[i];
    }

    int ans = 0;
    vector<int> dir_x = {1, -1, 0, 0};
    vector<int> dir_y = {0, 0, 1, -1};

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (G[i][j] == '.')
            {
                vector<vector<int>> D(H, vector<int>(W, -1));
                queue<pair<int, int>> q;
                q.push({i, j});
                D[i][j] = 0;

                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int i = 0; i < 4; ++i)
                    {
                        int nx = x + dir_x[i];
                        int ny = y + dir_y[i];

                        if (nx >= 0 && nx < H && ny >= 0 && ny < W && G[nx][ny] == '.' && D[nx][ny] == -1)
                        {
                            D[nx][ny] = D[x][y] + 1;
                            q.push({nx, ny});
                        }
                    }
                }

                for (int x = 0; x < H; ++x)
                {
                    for (int y = 0; y < W; ++y)
                    {
                        if (G[x][y] == '.' && D[x][y] != -1)
                        {
                            ans = max(ans, D[x][y]);
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int T = 1;
    // cin >> T;
    // while (T--)
    {
        solve();
    }
    return 0;
}
