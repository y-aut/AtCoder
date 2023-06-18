#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

// clang-format off
/* accelration */
// 高速バイナリ生成
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// cin cout の結びつけ解除, stdioと同期しない(入出力非同期化)
// cとstdの入出力を混在させるとバグるので注意
struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;

/* alias */
// type
using ull = unsigned long long;
using ll = long long;
using ld = long double;
// pair
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// vector
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvb = vector<vb>;
using vpii = vector<pii>;
using vpll = vector<pll>;
// unordered set
using usi = unordered_set<int>;
using usll = unordered_set<ll>;
using uss = unordered_set<string>;

/* define short */
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<'\n';}else{cout<<"NO"<<'\n';}
#define yesno(bool) if(bool){cout<<"yes"<<'\n';}else{cout<<"no"<<'\n';}
#define YesNo(bool) if(bool){cout<<"Yes"<<'\n';}else{cout<<"No"<<'\n';}
#define CSI constexpr static int
#define CSLL constexpr static ll
#define CSLD constexpr static ld

/* set variables */
#define VAR(type, ...) type __VA_ARGS__; IN(__VA_ARGS__)
#define INT(...) VAR(int, __VA_ARGS__)
#define LL(...) VAR(ll, __VA_ARGS__)
#define CHR(...) VAR(char, __VA_ARGS__)
#define STR(...) VAR(string, __VA_ARGS__)
#define DBL(...) VAR(double, __VA_ARGS__)
#define VI(a, b) auto a = in_vi(b)
#define VLL(a, b) auto a = in_vll(b)
#define VD(a, b) auto a = in_vd(b)
#define VC(a, b) auto a = in_vc(b)
#define VS(a, b) auto a = in_vs(b)
#define VPII(a, b) auto a = in_vpii(b)
#define VPLL(a, b) auto a = in_vpll(b)
#define VVI(a, h, w) auto a = in_vvi(h, w)
#define VVLL(a, h, w) auto a = in_vvll(h, w)

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); i++)
#define rreps(i, a, n) for (ll i = (a); i <= (ll)(n); i++)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) rreps(i, 1, n)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define rrepd(i, n) for (ll i = n; i >= 1; i--)
#define repi(a, v) for (auto&& a : (v))

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << '\n';

/* func */
inline int in_int() {int x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline double in_double() {double x; cin >> x; return x;}
inline pii in_pii() {pii x; cin >> x.first >> x.second; return x;}
inline pll in_pll() {pll x; cin >> x.first >> x.second; return x;}
inline char in_char() {char c; cin >> c; return c;}
inline string in_str() {string x; cin >> x; return x;}
inline vi in_vi(int length) {vi res; rep(i, length) res.pb(in_int()); return res;}
inline vll in_vll(int length) {vll res; rep(i, length) res.pb(in_ll()); return res;}
inline vd in_vd(int length) {vd res; rep(i, length) res.pb(in_double()); return res;}
inline vc in_vc(int length) {vc res; rep(i, length) res.pb(in_char()); return res;}
inline vs in_vs(int height) {vs res; rep(i, height) res.pb(in_str()); return res;}
inline vpii in_vpii(int height)
    {vpii res; rep(i, height) {pii tmp; tmp.first = in_int(); tmp.second = in_int(); res.pb(tmp);} return res;}
inline vpll in_vpll(int height)
    {vpll res; rep(i, height) {pll tmp; tmp.first = in_ll(); tmp.second = in_ll(); res.pb(tmp);} return res;}
inline vvi in_vvi(int height, int width)
    {vvi res; rep(i, height) {vi tmp; rep(j, width) tmp.pb(in_int()); res.pb(tmp);} return res;}
inline vvll in_vvll(int height, int width)
    {vvll res; rep(i, height) {vll tmp; rep(j, width) tmp.pb(in_ll()); res.pb(tmp);} return res;}
template <bool bidir> inline vvll in_edges(int N, int height)
    {vvll res(N, vll());
    rep(i, height) {ll a = in_ll()-1; ll b = in_ll()-1; res[a].pb(b); if (bidir) res[b].pb(a);} return res;}
template <bool bidir> inline vector<usll> in_edges_us(int N, int height)
    {vector<usll> res(N, usll());
    rep(i, height) {ll a = in_ll()-1; ll b = in_ll()-1; res[a].insert(b); if (bidir) res[b].insert(a);} return res;}
inline void IN() {}
template <typename First, typename... Rest> inline void IN(First& first, Rest&... rest) {cin >> first; IN(rest...);}
inline int ctoi(char c) {return c - '0';}
template <typename T> inline void print(const vector<T>& v, string s = " ")
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : ""); cout << '\n';}
template <typename T, typename S> inline void print(const pair<T, S>& p)
    {cout << p.first << " " << p.second << '\n';}
template <typename T> inline void print(const T& x) {cout << x << '\n';}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v)
    {for (auto&& p : v) print(p);}
template <typename T, typename S> inline void print(const map<T, S>& m)
    {for (auto&& p : m) print(p);}
template <int V> inline void print(const static_modint<V> v) {print(v.val());}
inline void print(const modint v) {print(v.val());}
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare; if ((compare = a > b)) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare; if ((compare = a < b)) a = b; return compare;}
// デバッグ用関数
template <typename T> void dprint(const vector<T> &v) {
    rep(i, v.size()) {cout << "[" << i << "]: "; print(v[i]); cout << flush;}
}
template <typename T> void dprint(const vector<vector<T>> &v) {
    rep(i, v.size()) rep(j, v[i].size()) {cout << "[" << i << "][" << j << "]: "; print(v[i][j]); cout << flush;}
}
template<typename T> void dprint(const T v[], const int size) {
    rep(i, size) {cout << "[" << i << "]: "; print(v[i]); cout << flush;}
}
template <typename T> void dprint(const T v[], const int W, const int H) {
    rep(i, W) rep(j, H) {cout << "[" << i << "][" << j << "]: "; print(v[i][j]); cout << flush;}
}

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = (1LL << 60);
CSI INF = 1000000006;
CSLD EPS = 1e-10;
CSLD PHI = 1.6180339887498948;

using mint = int;
using vm = vector<mint>;
using vvm = vector<vm>;

// clang-format on

// s:0 g:1 o:2-
ll cost[20][20];

void q_push(queue<pll> &q, vvll &res, ll H, ll W, vs &A, pll s) {
    // s の周辺を push
    if (s.first != 0 && A[s.first - 1][s.second] != '#' && res[s.first - 1][s.second] == -1) {
        res[s.first - 1][s.second] = res[s.first][s.second] + 1;
        q.push({s.first - 1, s.second});
    }
    if (s.first != H - 1 && A[s.first + 1][s.second] != '#' && res[s.first + 1][s.second] == -1) {
        res[s.first + 1][s.second] = res[s.first][s.second] + 1;
        q.push({s.first + 1, s.second});
    }
    if (s.second != 0 && A[s.first][s.second - 1] != '#' && res[s.first][s.second - 1] == -1) {
        res[s.first][s.second - 1] = res[s.first][s.second] + 1;
        q.push({s.first, s.second - 1});
    }
    if (s.second != W - 1 && A[s.first][s.second + 1] != '#' && res[s.first][s.second + 1] == -1) {
        res[s.first][s.second + 1] = res[s.first][s.second] + 1;
        q.push({s.first, s.second + 1});
    }
}

void bfs(ll H, ll W, vs &A, vpll &sq, ll start) {
    vvll res(H, vll(W, -1));
    queue<pll> q;
    auto s = sq[start];
    res[s.first][s.second] = 0;
    q_push(q, res, H, W, A, s);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        q_push(q, res, H, W, A, v);
    }
    rep(i, sq.size()) {
        cost[start][i] = res[sq[i].first][sq[i].second];
    }
}

ll dp[1 << 18][20] = {};

int main() {
    LL(H, W, T);
    VS(A, H);

    vpll sq(2);
    rep(i, H) rep(j, W) {
        if (A[i][j] == 'S') {
            sq[0] = {i, j};
        } else if (A[i][j] == 'G') {
            sq[1] = {i, j};
        } else if (A[i][j] == 'o') {
            sq.pb({i, j});
        }
    }

    rep(i, 20) rep(j, 20) cost[i][j] = -1;

    rep(i, sq.size()) {
        bfs(H, W, A, sq, i);
    }

    if (cost[0][1] > T || cost[0][1] == -1) {
        print(-1);
        return 0;
    }

    vvll masks(sq.size() - 1, vll());
    rep(i, 1 << (sq.size() - 2)) {
        masks[__builtin_popcount((int)i)].pb(i);
    }

    rep(i, 1 << 18) rep(j, 20) dp[i][j] = LINF;
    dp[0][0] = 0;

    rep(i, sq.size() - 1) {
        repi(j, masks[i]) {
            rep(s, sq.size()) {
                if (dp[j][s] == LINF) continue;
                if (cost[s][0] != -1)
                    chmin(dp[j][0], dp[j][s] + cost[s][0]);
                if (cost[s][1] != -1)
                    chmin(dp[j][1], dp[j][s] + cost[s][1]);
                for (ll k = 2, mask = 1; k < sq.size(); k++, mask <<= 1) {
                    if (cost[s][k] != -1)
                        chmin(dp[j | mask][k], dp[j][s] + cost[s][k]);
                }
            }
        }
    }

    ll ans = 0;
    rep(i, sq.size() - 1) {
        repi(j, masks[i]) {
            if (dp[j][1] <= T) {
                ans = i;
                break;
            }
        }
    }

    print(ans);

    return 0;
}
