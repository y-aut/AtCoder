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
#define INVAR(type, ...) type __VA_ARGS__; set_vars(__VA_ARGS__)
#define ININT(...) INVAR(int, __VA_ARGS__)
#define INLL(...) INVAR(ll, __VA_ARGS__)

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); i++)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
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
inline vvi in_vvi(int width, int height)
    {vvi res; rep(i, height) {vi tmp; rep(j, width) tmp.pb(in_int()); res.pb(tmp);} return res;}
inline vvll in_vvll(int width, int height)
    {vvll res; rep(i, height) {vll tmp; rep(j, width) tmp.pb(in_ll()); res.pb(tmp);} return res;}
inline vpii in_vpii(int height)
    {vpii res; rep(i, height) {pii tmp; tmp.first = in_int(); tmp.second = in_int(); res.pb(tmp);} return res;}
inline vpll in_vpll(int height)
    {vpll res; rep(i, height) {pll tmp; tmp.first = in_ll(); tmp.second = in_ll(); res.pb(tmp);} return res;}
template <bool bidir> inline vvll in_edges(int N, int height)
    {vvll res(N, vll());
    rep(i, height) {ll a = in_ll()-1; ll b = in_ll()-1; res[a].pb(b); if (bidir) res[b].pb(a);} return res;}
template <bool bidir> inline vector<usll> in_edges_us(int N, int height)
    {vector<usll> res(N, usll());
    rep(i, height) {ll a = in_ll()-1; ll b = in_ll()-1; res[a].insert(b); if (bidir) res[b].insert(a);} return res;}
inline void set_vars() {}
template <typename First, typename... Rest> inline void set_vars(First& first, Rest&... rest)
    {cin >> first; set_vars(rest...);}
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

pll operator-(const pll &a, const pll &b) {
    return {a.first - b.first, a.second - b.second};
}

struct Edge {
    const pll &from;
    const pll &to;

    Edge(const pll &_from, const pll &_to) : from(_from), to(_to) {}
};

// > 0: b は a の左側
inline ll cross(const pll &a, const pll &b) {
    return a.first * b.second - a.second * b.first;
}

int main() {
    INLL(N);
    auto A = in_vpll(N);
    INLL(Q);
    auto queries = in_vpll(Q);

    ll min_x = LINF;
    ll max_x = -LINF;
    ll min_x_top = 0, min_x_bottom = 0;
    ll max_x_top = 0, max_x_bottom = 0;
    rep(i, N) {
        if (A[i].first < min_x) {
            min_x = A[i].first;
            min_x_top = min_x_bottom = i;
        } else if (A[i].first == min_x) {
            if (A[min_x_top].second < A[i].second) {
                min_x_top = i;
            }
            if (A[min_x_bottom].second > A[i].second) {
                min_x_bottom = i;
            }
        }
        if (A[i].first > max_x) {
            max_x = A[i].first;
            max_x_top = max_x_bottom = i;
        } else if (A[i].first == max_x) {
            if (A[max_x_top].second < A[i].second) {
                max_x_top = i;
            }
            if (A[max_x_bottom].second > A[i].second) {
                max_x_bottom = i;
            }
        }
    }

    vector<Edge> uedges, ledges;
    for (ll i = min_x_top; i != max_x_top; i = (i + N - 1) % N) {
        uedges.emplace_back(A[i], A[(i + N - 1) % N]);
    }
    for (ll i = min_x_bottom; i != max_x_bottom; i = (i + 1) % N) {
        ledges.emplace_back(A[i], A[(i + 1) % N]);
    }

    auto q2 = queries;
    sort(all(q2), [](pll &a, pll &b) { return a.first == b.first ? a.second < b.second : a.first < b.first; });
    q2.erase(unique(all(q2)), q2.end());

    // result[x][y]: (x, y) の結果 (0: IN, 1: OUT, 2: ON)
    um<ll, um<ll, int>> result;

    int q_start = 0, q_end = 0;
    rep(i, q2.size()) {
        if (q2[i].first < min_x) {
            result[q2[i].first][q2[i].second] = 1;
            q_start = i + 1;
        } else if (q2[i].first == min_x) {
            if (A[min_x_bottom].second <= q2[i].second && q2[i].second <= A[min_x_top].second) {
                result[q2[i].first][q2[i].second] = 2;
            } else {
                result[q2[i].first][q2[i].second] = 1;
            }
            q_start = i + 1;
        }
        if (q2[i].first > max_x) {
            result[q2[i].first][q2[i].second] = 1;
        } else if (q2[i].first == max_x) {
            if (A[max_x_bottom].second <= q2[i].second && q2[i].second <= A[max_x_top].second) {
                result[q2[i].first][q2[i].second] = 2;
            } else {
                result[q2[i].first][q2[i].second] = 1;
            }
        } else {
            q_end = i + 1;
        }
    }

    int lower = 0, upper = 0;
    reps(i, q_start, q_end) {
        // from <= q2[i] < to
        while (q2[i].first >= ledges[lower].to.first) lower++;
        while (q2[i].first >= uedges[upper].to.first) upper++;

        auto l_cross = cross(ledges[lower].to - ledges[lower].from, q2[i] - ledges[lower].from);
        auto u_cross = cross(uedges[upper].to - uedges[upper].from, q2[i] - uedges[upper].from);
        if (l_cross < 0) {
            result[q2[i].first][q2[i].second] = 1;
        } else if (l_cross == 0) {
            result[q2[i].first][q2[i].second] = 2;
        } else {
            if (u_cross < 0) {
                result[q2[i].first][q2[i].second] = 0;
            } else if (u_cross == 0) {
                result[q2[i].first][q2[i].second] = 2;
            } else {
                result[q2[i].first][q2[i].second] = 1;
            }
        }
    }

    repi(q, queries) {
        auto val = result[q.first][q.second];
        if (val == 0) {
            print("IN");
        } else if (val == 1) {
            print("OUT");
        } else {
            print("ON");
        }
    }

    return 0;
}
