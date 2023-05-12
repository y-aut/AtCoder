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
struct Fast {Fast() {cin.tie(0); ios::sync_with_stdio(false);}} fast;

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

// 追加する直線の傾きが単調である場合の ConvexHullTrick
template <typename T>
class ConvexHullTrick {
    // 直線群
    vector<pair<T, T>> lines;
    // 最小値(最大値)を求める x が単調であるか
    bool is_monotonic_x;
    // 最小/最大を判断する関数
    function<bool(T l, T r)> comp;
    // 単調クエリにおける探索位置
    int head = 0;

    // 直線 l1, l2, l3 のうち l2 が不必要であるかどうか
    bool check(pair<T, T> l1, const pair<T, T> &l2, pair<T, T> l3) const {
        if (l1 < l3) swap(l1, l3);
        return (l3.second - l2.second) * (l2.first - l1.first) >= (l2.second - l1.second) * (l3.first - l2.first);
    }

    // i番目の直線f_i(x)に対するxの時の値を返す
    T f(const int i, const T x) const {
        return lines[i].first * x + lines[i].second;
    }

public:
    ConvexHullTrick(
        const bool _is_monotonic_x = false,
        const function<bool(T l, T r)> _comp = [](T l, T r) { return l >= r; })
        : is_monotonic_x(_is_monotonic_x), comp(_comp) {
        lines.emplace_back(0, 0);
    };

    // 直線 y = ax + b を追加する
    void add(const T &a, const T &b) {
        pair<T, T> line(a, b);
        while (lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line))
            lines.pop_back();
        lines.emplace_back(line);
    }

    // 直線群の中で x の時に最小(最大)となる値を返す
    T get(const T &x) {
        // 最小値(最大値)クエリにおける x が単調
        if (is_monotonic_x) {
            while (lines.size() - head >= 2 && comp(f(head, x), f(head + 1, x)))
                ++head;
            return f(head, x);
        } else {
            int low = -1, high = lines.size() - 1;
            while (high - low > 1) {
                int mid = (high + low) / 2;
                (comp(f(mid, x), f(mid + 1, x)) ? low : high) = mid;
            }
            return f(high, x);
        }
    }
};

int main() {
    INLL(N, C);
    auto h = in_vll(N);

    vll dp(N, 0);
    ConvexHullTrick<ll> cv(true);

    reps(i, 1, N) {
        cv.add(-2 * h[i - 1], dp[i - 1] + h[i - 1] * h[i - 1]);
        dp[i] = cv.get(h[i]) + h[i] * h[i] + C;
    }

    print(dp[N - 1]);

    return 0;
}