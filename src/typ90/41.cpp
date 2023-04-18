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
using vb = vector<bool>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvb = vector<vb>;
using vs = vector<string>;
using vpii = vector<pii>;
using vpll = vector<pll>;
// unordered set
using usi = unordered_set<int>;
using usll = unordered_set<ll>;
using uss = unordered_set<string>;

/* define short */
#define pb push_back
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define CSI constexpr static int
#define CSLL constexpr static ll
#define CSLD constexpr static ld

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); i++)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define rrepd(i, n) for (ll i = n; i >= 1; i--)
#define repi(a, v) for (auto a : (v))

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << endl;

/* func */
inline int in_int() {int x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline double in_double() {double x; cin >> x; return x;}
inline char in_char() {char c; cin >> c; return c;}
inline string in_str() {string x; cin >> x; return x;}
inline vi in_vi(int length) {vi res = vi(); rep(i, length) res.pb(in_int()); return res;}
inline vll in_vll(int length) {vll res = vll(); rep(i, length) res.pb(in_ll()); return res;}
inline vvi in_vvi(int width, int height)
    {vvi res = vvi(); rep(i, height) {vi tmp = vi(); rep(j, width) tmp.pb(in_int()); res.pb(tmp);} return res;}
inline vvll in_vvll(int width, int height)
    {vvll res = vvll(); rep(i, height) {vll tmp = vll(); rep(j, width) tmp.pb(in_ll()); res.pb(tmp);} return res;}
inline int ctoi(char c) {return c - '0';}
template <typename T> inline void print(const vector<T>& v, string s = " ")
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : ""); cout << endl;}
template <typename T, typename S> inline void print(const pair<T, S>& p)
    {cout << p.first << " " << p.second << endl;}
template <typename T> inline void print(const T& x) {cout << x << endl;}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v)
    {for (auto&& p : v) print(p);}
template <typename T, typename S> inline void print(const map<T, S>& m)
    {for (auto&& p : m) print(p);}
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare; if (compare = a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare; if (compare = a < b) a = b; return compare;}

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = (1LL << 60);
CSI INF = 1000000006;
CSLD EPS = 1e-10;

// clang-format on

inline bool is_anti_clockwise(vll &p1, vll &p2, vll &p3) {
    return (p2[0] - p1[0]) * (p3[1] - p2[1]) > (p2[1] - p1[1]) * (p3[0] - p2[0]);
}

// 線分 a, b 上の格子点の数を求める
inline ll get_count(vll &a, vll &b) {
    auto cx = abs(a[0] - b[0]);
    auto cy = abs(a[1] - b[1]);
    if (cx == 0 || cy == 0)
        return cx + cy + 1;
    return gcd(cx, cy) + 1;
}

// 3 点 a, b, c の内部にある格子点の数を求める
inline ll get_count(vll &a, vll &b, vll &c, ll ab, ll bc, ll ca) {
    auto cx = b[0] - a[0];
    auto cy = b[1] - a[1];
    auto dx = c[0] - a[0];
    auto dy = c[1] - a[1];
    ll S_times_2 = abs(cx * dy - cy * dx);
    return (S_times_2 + 2 - (ab + bc + ca - 3)) / 2;
}

int main() {
    auto N = in_ll();
    auto XY = in_vvll(2, N);

    sort(all(XY), [](vll &a, vll &b) { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });
    auto s_upper = stack<vll>();
    auto s_lower = stack<vll>();

    repi(xy, XY) {
        while (s_upper.size() >= 2) {
            auto top = s_upper.top();
            s_upper.pop();
            auto second = s_upper.top();
            if (!is_anti_clockwise(second, top, xy)) {
                s_upper.push(top);
                break;
            }
        }
        s_upper.push(xy);
    }
    repi(xy, XY) {
        while (s_lower.size() >= 2) {
            auto top = s_lower.top();
            s_lower.pop();
            auto second = s_lower.top();
            if (is_anti_clockwise(second, top, xy)) {
                s_lower.push(top);
                break;
            }
        }
        s_lower.push(xy);
    }

    auto s_cir = deque<vll>();
    while (!s_upper.empty()) {
        s_cir.push_back(s_upper.top());
        s_upper.pop();
    }
    s_lower.pop();
    while (s_lower.size() > 1) {
        s_cir.push_front(s_lower.top());
        s_lower.pop();
    }

    ll ans = 0;
    ll bc = 0;
    while (s_cir.size() >= 3) {
        auto a = s_cir.front();
        s_cir.pop_front();
        auto b = s_cir.front();
        auto c = s_cir.back();
        auto ab = get_count(a, b);
        bc = get_count(b, c);
        auto ca = get_count(c, a);
        ans += get_count(a, b, c, ab, bc, ca) + ab + ca - 3;
    }
    ans += bc;

    print(ans - N);

    return 0;
}