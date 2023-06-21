#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

// clang-format off

#ifndef DEBUG
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;
#endif

/* alias */
// type
#define us unordered_set
#define um unordered_map
using ull = unsigned long long;
using ll = long long;
// pair
using pi = pair<int, int>;
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
using vpi = vector<pi>;
using vpll = vector<pll>;
// unordered set
using usi = us<int>;
using usll = us<ll>;
using uss = us<string>;
// unordered map
using umi = um<int, int>;
using umll = um<ll, ll>;

/* define short */
#define CSI constexpr static int
#define CSLL constexpr static ll
#define CSD constexpr static double
#define pb push_back
#define eb emplace_back
#define all(obj) (obj).begin(), (obj).end()

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

/* func */
inline int in_int() {int x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline double in_double() {double x; cin >> x; return x;}
inline pi in_pi() {pi x; cin >> x.first >> x.second; return x;}
inline pll in_pll() {pll x; cin >> x.first >> x.second; return x;}
inline char in_char() {char c; cin >> c; return c;}
inline string in_str() {string x; cin >> x; return x;}
inline vi in_vi(int length) {vi res; rep(i, length) res.pb(in_int()); return res;}
inline vll in_vll(int length) {vll res; rep(i, length) res.pb(in_ll()); return res;}
inline vd in_vd(int length) {vd res; rep(i, length) res.pb(in_double()); return res;}
inline vc in_vc(int length) {vc res; rep(i, length) res.pb(in_char()); return res;}
inline vs in_vs(int height) {vs res; rep(i, height) res.pb(in_str()); return res;}
inline vpi in_vpi(int height)
    {vpi res; rep(i, height) {pi tmp; tmp.first = in_int(); tmp.second = in_int(); res.pb(tmp);} return res;}
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
template <typename T> inline void print(const vector<T>& v, string sep = " ")
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? sep : ""); cout << '\n';}
template <typename T> inline void print(const set<T>& s, string sep = " ")
    {repi(i, s) cout << i << (i != *s.end() ? sep : ""); cout << '\n';}
template <typename T, typename S> inline void print(const pair<T, S>& p)
    {cout << p.first << " " << p.second << '\n';}
template <typename T> inline void print(const T& x) {cout << x << '\n';}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v)
    {for (auto&& p : v) print(p);}
template <typename T, typename S> inline void print(const map<T, S>& m)
    {for (auto&& p : m) print(p);}
template <int V> inline void print(const static_modint<V> v) {print(v.val());}
inline void print(const modint v) {print(v.val());}
template <typename T> inline bool chmin(T& a, const T& b) {bool compare; if ((compare = a > b)) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare; if ((compare = a < b)) a = b; return compare;}

// Print
#define YES print("YES")
#define NO print("NO")
#define Yes print("Yes")
#define No print("No")
#define YESNO(bool) if (bool) YES; else NO
#define YesNo(bool) if (bool) Yes; else No

// Debug Print
#ifdef DEBUG
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << '\n'
template <typename T> void dprint(const vector<T> &v)
    {rep(i, v.size()) {cout << "[" << i << "]: "; print(v[i]); cout << flush;}}
template <typename T> void dprint(const vector<vector<T>> &v)
    {rep(i, v.size()) rep(j, v[i].size()) {cout << "[" << i << "][" << j << "]: "; print(v[i][j]); cout << flush;}}
template<typename T> void dprint(const T v[], const int size)
    {rep(i, size) {cout << "[" << i << "]: "; print(v[i]); cout << flush;}}
template <typename T> void dprint(const T v[], const int W, const int H)
    {rep(i, W) rep(j, H) {cout << "[" << i << "][" << j << "]: "; print(v[i][j]); cout << flush;}}
#else
#define debug(x) (void)0
template <typename T> void dprint(const vector<T> &v) {}
template <typename T> void dprint(const vector<vector<T>> &v) {}
template<typename T> void dprint(const T v[], const int size) {}
template <typename T> void dprint(const T v[], const int W, const int H) {}
#endif

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = (1LL << 60);
CSI INF = 1000000006;
CSD EPS = 1e-10;
CSD PI = 3.141592653589793;
CSD PHI = 1.6180339887498948;

using mint = int;
using vm = vector<mint>;
using vvm = vector<vm>;
using pmm = pair<mint, mint>;

// clang-format on

ll solve(vll &A) {
    // 転倒数を求める
    fenwick_tree<ll> ft(A.size());

    ll ans = 0;
    repd(i, A.size()) {
        ans += ft.sum(0, A[i]);
        ft.add(A[i], 1);
    }

    return ans;
}

void mov(vll &A, ll i, ll j, vpll &ans) {
    ans.eb(i + 1, j);
    auto a = A[i], b = A[i + 1];
    rep(k, 2) A.erase(A.begin() + i);
    A.insert(A.begin() + j, b);
    A.insert(A.begin() + j, a);
}

void impl(vll &A, ll now, vpll &ans) {
    if (now == A.size()) return;
    if (A[now] != now) {
        reps(i, now + 1, A.size()) {
            if (A[i] == now) {
                if (i == A.size() - 1) {
                    mov(A, i - 1, now, ans);
                    impl(A, now, ans);
                    return;
                } else {
                    mov(A, i, now, ans);
                    break;
                }
            }
        }
    }
    impl(A, now + 1, ans);
}

int main() {
    LL(N);
    VLL(P, N);
    rep(i, N) P[i]--;

    if (solve(P) % 2) {
        No;
        return 0;
    }

    Yes;
    vpll ans;
    impl(P, 0, ans);

    print(ans.size());
    print(ans);

    return 0;
}
