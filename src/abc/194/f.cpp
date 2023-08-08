#pragma region "Template"

#define TEMPLATE_H
#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

// clang-format off

#ifndef DEBUG
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
#endif

/* alias */
// type
#define us unordered_set
#define um unordered_map
using ull = unsigned long long;
using ll = long long;
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
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvb = vector<vb>;
using vvpii = vector<vpii>;
using vvpll = vector<vpll>;
// unordered set
using usi = us<int>;
using usll = us<ll>;
using uss = us<string>;
// unordered map
using umi = um<int, int>;
using umll = um<ll, ll>;

/* mint */
#define DEFINE_MOD(v)               \
    using mint = static_modint<v>;  \
    using vm = vector<mint>;        \
    using vvm = vector<vm>;         \
    using pmm = pair<mint, mint>

/* extract params */
#define HEAD_NAME(x, ...) #x
#define OVERLOAD3(_1, _2, _3, x, ...) x

/* define short */
#define CSI constexpr static int
#define CSLL constexpr static ll
#define CSD constexpr static double
#define pb push_back
#define eb emplace_back
#define all(obj) (obj).begin(), (obj).end()
#define pcnt __builtin_popcount
#define pcntll __builtin_popcountll

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
#define REP2(i, a, n) for (ll i = (ll)(a); i < (ll)(n); i++)
#define REP1(i, n) REP2(i, 0, n)
#define RREP2(i, a, n) for (ll i = (ll)(a); i <= (ll)(n); i++)
#define RREP1(i, n) RREP2(i, 1, n)
#define REPD2(i, a, n) for (ll i = (ll)(n) - 1; i >= (ll)(a); i--)
#define REPD1(i, n) REPD2(i, 0, n)
#define RREPD2(i, a, n) for (ll i = (ll)(n); i >= (ll)(a); i--)
#define RREPD1(i, n) RREPD2(i, 1, n)
#define rep(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define rrep(...) OVERLOAD3(__VA_ARGS__, RREP2, RREP1)(__VA_ARGS__)
#define repd(...) OVERLOAD3(__VA_ARGS__, REPD2, REPD1)(__VA_ARGS__)
#define rrepd(...) OVERLOAD3(__VA_ARGS__, RREPD2, RREPD1)(__VA_ARGS__)
#define repi(a, v) for (auto&& a : (v))

/* control */
#define EXIT(...) ({ __VA_ARGS__; exit(0); })
#define BREAK(...) ({ __VA_ARGS__; break; })
#define CONTINUE(...) ({ __VA_ARGS__; continue; })

/* func */
// input
inline int in_int() { int x; cin >> x; return x; }
inline ll in_ll() { ll x; cin >> x; return x; }
inline double in_double() { double x; cin >> x; return x; }
inline pii in_pii() { pii x; cin >> x.first >> x.second; return x; }
inline pll in_pll() { pll x; cin >> x.first >> x.second; return x; }
inline char in_char() { char c; cin >> c; return c; }
inline string in_str() { string x; cin >> x; return x; }
inline vi in_vi(int length) { vi res; rep(i, length) res.pb(in_int()); return res; }
inline vll in_vll(int length) { vll res; rep(i, length) res.pb(in_ll()); return res; }
inline vd in_vd(int length) { vd res; rep(i, length) res.pb(in_double()); return res; }
inline vc in_vc(int length) { vc res; rep(i, length) res.pb(in_char()); return res; }
inline vs in_vs(int height) { vs res; rep(i, height) res.pb(in_str()); return res; }
inline vpii in_vpii(int height)
    { vpii res; rep(i, height) { pii tmp; tmp.first = in_int(); tmp.second = in_int(); res.pb(tmp); } return res; }
inline vpll in_vpll(int height)
    { vpll res; rep(i, height) { pll tmp; tmp.first = in_ll(); tmp.second = in_ll(); res.pb(tmp); } return res; }
inline vvi in_vvi(int height, int width)
    { vvi res; rep(i, height) { vi tmp; rep(j, width) tmp.pb(in_int()); res.pb(tmp); } return res; }
inline vvll in_vvll(int height, int width)
    { vvll res; rep(i, height) { vll tmp; rep(j, width) tmp.pb(in_ll()); res.pb(tmp); } return res; }
template <bool bidir> inline vvll in_edges(int N, int height)
    { vvll res(N, vll()); rep(i, height) { ll a = in_ll() - 1; ll b = in_ll() - 1;
    res[a].pb(b); if (bidir) res[b].pb(a); } return res; }
template <bool bidir> inline vector<usll> in_edges_us(int N, int height)
    { vector<usll> res(N, usll()); rep(i, height) { ll a = in_ll() - 1; ll b = in_ll() - 1;
    res[a].insert(b); if (bidir) res[b].insert(a); } return res; }
template <bool bidir> inline vvpll in_wedges(int N, int height)
    { vvpll res(N, vpll()); rep(i, height) { ll a = in_ll() - 1; ll b = in_ll() - 1; ll w = in_ll();
    res[a].eb(b, w); if (bidir) res[b].eb(a, w); } return res; }
inline void IN() {}
template <typename First, typename... Rest> inline void IN(First &first, Rest &...rest) { cin >> first; IN(rest...); }

// change min/max
template <typename T> inline bool chmin(T &a, const T &b) { bool flg = a > b; if (flg) a = b; return flg; }
template <typename T> inline bool chmax(T &a, const T &b) { bool flg = a < b; if (flg) a = b; return flg; }

// print
template <typename T> inline void print(const T &v) { cout << v << '\n'; }
template <typename T> inline void print(const vector<T> &v, string sep = " ")
    { rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? sep : ""); cout << '\n'; }
template <typename T> inline void print(const set<T> &v, string sep = " ")
    { repi(i, v) cout << i << (i != *v.end() ? sep : ""); cout << '\n'; }
template <typename T, typename S> inline void print(const pair<T, S> &v)
    { cout << v.first << " " << v.second << '\n'; }
template <typename T, typename S> inline void print(const vector<pair<T, S>> &v) { repi(i, v) print(i); }
template <typename T, typename S> inline void print(const map<T, S> &v) { repi(i, v) print(i); }
template <int V> inline void print(const static_modint<V> &v) { print(v.val()); }
inline void print(const modint &v) { print(v.val()); }

#define YES print("YES")
#define NO print("NO")
#define Yes print("Yes")
#define No print("No")
#define YESNO(bool) if (bool) YES; else NO
#define YesNo(bool) if (bool) Yes; else No

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...) (void)0
#endif

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = (1LL << 60);
CSI INF = 1000000006;
CSD EPS = 1e-10;
CSD PI = 3.141592653589793;
CSD PHI = 1.6180339887498948;

#pragma endregion

DEFINE_MOD(MOD);

// clang-format on

vvm memo;
vm memo2;

mint calc(ll n, ll m, ll K) {
    // 16^n のうち，K 種類，m 種類使用済み
    if (m > K) return 0;
    if (memo[n][m] != -1) return memo[n][m];
    if (n == 1) {
        if (K == m) return memo[n][m] = K;
        else if (K == m + 1) return memo[n][m] = 16 - m;
        else return memo[n][m] = 0;
    }
    return memo[n][m] = m * calc(n - 1, m, K) + (16 - m) * calc(n - 1, m + 1, K);
}

mint calc2(ll n, ll K) {
    // 先頭の 0 なし
    if (memo2[n] != -1) return memo2[n];
    if (n == 0) return memo2[n] = 0;
    if (n == 1) {
        if (K == 1) return memo2[n] = 15;
        else return memo2[n] = 0;
    }
    return memo2[n] = calc2(n - 1, K) + calc(n - 1, 1, K) * 15;
}

inline ll ctoi(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    else return c - 'A' + 10;
}

int main() {
    STR(N);
    LL(K);

    memo = vvm(N.size() + 1, vm(K + 1, -1));
    memo2 = vm(N.size() + 1, -1);

    mint ans = calc2(N.size() - 1, K);
    usll used;

    rep(i, N.size()) {
        auto c = ctoi(N[i]);
        if (i == N.size() - 1) {
            ll cnt = 0;
            rrep(j, i == 0 ? 1 : 0, c) {
                if (used.count(j)) cnt++;
            }
            if (used.size() == K) ans += cnt;
            else if (used.size() == K - 1) ans += c - cnt + (i == 0 ? 0 : 1);
            continue;
        }
        rep(j, i == 0 ? 1 : 0, c) {
            ans += calc(N.size() - i - 1, used.size() + (used.count(j) ? 0 : 1), K);
        }
        used.insert(c);
    }

    print(ans);

    return 0;
}
