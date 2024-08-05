#pragma region "Template"

#ifdef DEBUG
#include "template.hpp"
#else
#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#include <gmpxx.h>
using namespace atcoder;

// clang-format off

#ifndef DEBUG
#ifdef __x86_64__
#pragma GCC target("avx")
#endif
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
#endif

#define USE_MODINT

/* templates */
#define TPL_T template <typename T>
#define TPL_TS template <typename T, typename S>
#define TPL_TSU template <typename T, typename S, typename U>
#define TPL_TSUV template <typename T, typename S, typename U, typename V>
#define TPL_TSUVW template <typename T, typename S, typename U, typename V, typename W>

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
TPL_T using v = vector<T>;
TPL_T using vv = v<v<T>>;
TPL_T using vvv = v<vv<T>>;
using vi = v<int>;
using vll = v<ll>;
using vd = v<double>;
using vb = v<bool>;
using vc = v<char>;
using vs = v<string>;
using vpii = v<pii>;
using vpll = v<pll>;
using vvi = v<vi>;
using vvll = v<vll>;
using vvb = v<vb>;
using vvpii = v<vpii>;
using vvpll = v<vpll>;
// unordered set
using usi = us<int>;
using usll = us<ll>;
using uss = us<string>;
// unordered map
using umi = um<int, int>;
using umll = um<ll, ll>;

/* mint */
#ifdef USE_MODINT
#define DEFINE_MOD(m)               \
    using mint = static_modint<m>;  \
    using vm = v<mint>;             \
    using vvm = v<vm>;              \
    using pmm = pair<mint, mint>;   \
    inline vm in_vm(int length) { vm res; rep(i, length) res.pb(in_ll()); return res; } \
    inline vvm in_vvm(int height, int width) { vvm res; rep(i, height) res.pb(in_vm(width)); return res; }
#else
#define DEFINE_MOD(...)
#endif

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
#define popcnt __builtin_popcount
#define popcntll __builtin_popcountll

/* set variables */
#define VAR(type, ...) type __VA_ARGS__; IN(__VA_ARGS__)
#define INT(...) VAR(int, __VA_ARGS__)
#define LL(...) VAR(ll, __VA_ARGS__)
#define DBL(...) VAR(double, __VA_ARGS__)
#define CHR(...) VAR(char, __VA_ARGS__)
#define STR(...) VAR(string, __VA_ARGS__)
#define PII(...) VAR(pii, __VA_ARGS__)
#define PLL(...) VAR(pll, __VA_ARGS__)
#define VI(a, b) auto a = in_vi(b)
#define VLL(a, b) auto a = in_vll(b)
#define VM(a, b) auto a = in_vm(b)
#define VD(a, b) auto a = in_vd(b)
#define VC(a, b) auto a = in_vc(b)
#define VS(a, b) auto a = in_vs(b)
#define VPII(a, b) auto a = in_vpii(b)
#define VPLL(a, b) auto a = in_vpll(b)
#define VVI(a, h, w) auto a = in_vvi(h, w)
#define VVLL(a, h, w) auto a = in_vvll(h, w)
#define VVM(a, h, w) auto a = in_vvm(h, w)

/* REP macro */
#define REP2(i, a, n) for (ll i = (ll)(a); i < (ll)(n); i++)
#define REP1(i, n) REP2(i, 0, n)
#define RREP2(i, a, n) for (ll i = (ll)(a); i <= (ll)(n); i++)
#define RREP1(i, n) RREP2(i, 1, n)
#define REPD2(i, a, n) for (ll i = (ll)(n) - 1; i >= (ll)(a); i--)
#define REPD1(i, n) REPD2(i, 0, n)
#define RREPD2(i, a, n) for (ll i = (ll)(n); i >= (ll)(a); i--)
#define RREPD1(i, n) RREPD2(i, 1, n)
#define REPI1(a, v) for (auto&& a : (v))
#define REPI2(a, b, v) for (auto&& [a, b] : (v))
#define rep(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define rrep(...) OVERLOAD3(__VA_ARGS__, RREP2, RREP1)(__VA_ARGS__)
#define repd(...) OVERLOAD3(__VA_ARGS__, REPD2, REPD1)(__VA_ARGS__)
#define rrepd(...) OVERLOAD3(__VA_ARGS__, RREPD2, RREPD1)(__VA_ARGS__)
#define repi(...) OVERLOAD3(__VA_ARGS__, REPI2, REPI1)(__VA_ARGS__)

/* control */
#define EXIT(...) ({ __VA_ARGS__; exit(0); })
#define BREAK(...) ({ __VA_ARGS__; break; })
#define CONTINUE(...) ({ __VA_ARGS__; continue; })

// istream
TPL_TS istream &operator>>(istream &is, pair<T, S> &v) { is >> v.first >> v.second; return is; }

/* func */
// input
inline int in_int() { int x; cin >> x; return x; }
inline ll in_ll() { ll x; cin >> x; return x; }
inline double in_double() { double x; cin >> x; return x; }
inline char in_char() { char c; cin >> c; return c; }
inline string in_str() { string x; cin >> x; return x; }
inline pii in_pii() { pii x; cin >> x; return x; }
inline pll in_pll() { pll x; cin >> x; return x; }
inline vi in_vi(int length) { vi res; rep(i, length) res.pb(in_int()); return res; }
inline vll in_vll(int length) { vll res; rep(i, length) res.pb(in_ll()); return res; }
inline vd in_vd(int length) { vd res; rep(i, length) res.pb(in_double()); return res; }
inline vc in_vc(int length) { vc res; rep(i, length) res.pb(in_char()); return res; }
inline vs in_vs(int height) { vs res; rep(i, height) res.pb(in_str()); return res; }
inline vpii in_vpii(int height) { vpii res; rep(i, height) res.pb(in_pii()); return res; }
inline vpll in_vpll(int height) { vpll res; rep(i, height) res.pb(in_pll()); return res; }
inline vvi in_vvi(int height, int width) { vvi res; rep(i, height) res.pb(in_vi(width)); return res; }
inline vvll in_vvll(int height, int width) { vvll res; rep(i, height) res.pb(in_vll(width)); return res; }
template <bool bidir> inline vvll in_edges(int N, int height, ll base = 1)
    { vvll res(N, vll()); rep(i, height) { ll a = in_ll() - base; ll b = in_ll() - base;
    res[a].pb(b); if (bidir) res[b].pb(a); } return res; }
template <bool bidir> inline v<usll> in_edges_us(int N, int height, ll base = 1)
    { v<usll> res(N, usll()); rep(i, height) { ll a = in_ll() - base; ll b = in_ll() - base;
    res[a].insert(b); if (bidir) res[b].insert(a); } return res; }
template <bool bidir> inline vvpll in_wedges(int N, int height, ll base = 1)
    { vvpll res(N, vpll()); rep(i, height) { ll a = in_ll() - base; ll b = in_ll() - base; ll w = in_ll();
    res[a].eb(b, w); if (bidir) res[b].eb(a, w); } return res; }
inline void IN() {}
template <typename First, typename... Rest> inline void IN(First &first, Rest &...rest) { cin >> first; IN(rest...); }

// gmp
using mll = mpz_class;
using md = mpf_class;
using vmll = v<mll>;
using vmd = v<md>;
#define MLL(...) VAR(mll, __VA_ARGS__)
#define VMLL(a, b) auto a = in_vmll(b)
inline mll in_mll() { mll x; cin >> x; return x; }
inline vmll in_vmll(int length) { vmll res; rep(i, length) res.pb(in_mll()); return res; }
inline mll to_mll(ll v) { return mll(to_string(v)); }
inline md to_md(ll v) { return md(to_string(v)); }

// change min/max
template <typename T, typename S> inline bool chmin(T &a, const S &b) { return a > b && (a = b, true); }
template <typename T, typename S> inline bool chmax(T &a, const S &b) { return a < b && (a = b, true); }

// operator
TPL_TS pair<T, S> operator-(const pair<T, S> &v) { return { -v.first, -v.second }; }
TPL_TS pair<T, S> &operator+=(pair<T, S> &a, const pair<T, S> &b) { a.first += b.first; a.second += b.second; return a; }
TPL_TS pair<T, S> &operator-=(pair<T, S> &a, const pair<T, S> &b) { return a += -b; }
TPL_TSU pair<T, S> &operator*=(pair<T, S> &a, const U &b) { a.first *= b; a.second *= b; return a; }
TPL_TSU pair<T, S> &operator/=(pair<T, S> &a, const U &b) { a.first /= b; a.second /= b; return a; }
TPL_TS pair<T, S> &operator+=(pair<T, S> &&a, const pair<T, S> &b) { return a += b; }
TPL_TS pair<T, S> &operator-=(pair<T, S> &&a, const pair<T, S> &b) { return a -= b; }
TPL_TSU pair<T, S> &operator*=(pair<T, S> &&a, const U &b) { return a *= b; }
TPL_TSU pair<T, S> &operator/=(pair<T, S> &&a, const U &b) { return a /= b; }
TPL_TS pair<T, S> operator+(const pair<T, S> &a, const pair<T, S> &b) { return pair<T, S>(a) += b; }
TPL_TS pair<T, S> operator-(const pair<T, S> &a, const pair<T, S> &b) { return pair<T, S>(a) -= b; }
TPL_TSU pair<T, S> operator*(const pair<T, S> &a, const U &b) { return pair<T, S>(a) *= b; }
TPL_TSU pair<T, S> operator/(const pair<T, S> &a, const U &b) { return pair<T, S>(a) /= b; }

// math
inline ll powll(ll a, ll b) { ll ans = 1; rep(i, b) ans *= a; return ans; }
inline ll llceil(ll a, ll b) { return a % b == 0 ? a / b : (a >= 0 ? (a / b) + 1 : -((-a) / b)); }
inline ll llfloor(ll a, ll b) { return a % b == 0 ? a / b : (a >= 0 ? (a / b) : -((-a) / b) - 1); }
TPL_T T abs2(const pair<T, T> &p) { return p.first * p.first + p.second * p.second; }
inline double abs(const pll &p) { return sqrt(abs2(p)); }

// hash
TPL_T struct Hasher { ull operator()(const T &v) const { return hash<T>()(v); } };
template <> struct Hasher<pii> { ull operator()(const pii &v) const { return (ull)v.first << 32 | (ull)v.second; } };
template <> struct Hasher<pll> { ull operator()(const pll &v) const { return (ull)v.first << 32 | (ull)v.second; } };
TPL_T using ush = us<T, Hasher<T>>;
TPL_TS using umh = um<T, S, Hasher<T>>;

// ostream
#define OSTREAM(class, ...) \
    void __inner_print(ostream& os) const { print_all(os, __VA_ARGS__); } \
    friend ostream& operator<<(ostream& os, const class& v) { v.__inner_print(os); return os; }
TPL_TS ostream &operator<<(ostream &os, const pair<T, S> &v) { os << v.first << " " << v.second; return os; }
#ifdef USE_MODINT
template <int V> ostream &operator<<(ostream &os, const static_modint<V> &v) { os << v.val(); return os; }
ostream &operator<<(ostream &os, const modint &v) { os << v.val(); return os; }
#endif

// print
TPL_T inline void print(const T &v, string end = "\n") { cout << v << end; }
TPL_TS inline void print(const v<pair<T, S>> &v) { repi(i, v) print(i); }
TPL_TS inline void print(const map<T, S> &v) { repi(i, v) print(i); }
TPL_T inline typename enable_if<is_base_of<forward_iterator_tag,
    typename iterator_traits<T>::iterator_category>::value>::type print(const T &begin, const T &end, string sep = " ")
    { for (auto i = begin; i != end; i++) print(*i, i != prev(end) ? sep : ""); cout << '\n'; }
TPL_T inline void print(const v<T> &v, string sep = " ") { print(all(v), sep); }
TPL_T inline void print(const set<T> &v, string sep = " ") { print(all(v), sep); }
TPL_T inline void print(const vv<T> &v) { repi(i, v) print(i); }
inline void print_all_inner(ostream&) {}
template <typename First, typename... Rest> void print_all_inner(ostream& os, const First &f, const Rest &...r)
    { os << ' ' << f; print_all_inner(os, r...); }
template <typename First, typename... Rest> void print_all(ostream& os, const First &f, const Rest &...r)
    { os << f; print_all_inner(os, r...); }

#define YES print("YES")
#define NO print("NO")
#define Yes print("Yes")
#define No print("No")
#define YESNO(bool) if (bool) YES; else NO
#define YesNo(bool) if (bool) Yes; else No

#ifdef DEBUG
#include "debug.hpp"
#else
#define dsep (void)0
#define debug(...) (void)0
#define debugs(...) (void)0
#define debugif(...) (void)0
#define debuga(...) (void)0
#endif

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = (ll)4.1e18;
CSI INF = 1000000006;
CSD EPS = 1e-11;
CSD PI = 3.141592653589793;
CSD PHI = 1.6180339887498948;
CSLL DX[] = {1, 0, -1, 0};
CSLL DY[] = {0, 1, 0, -1};
#endif
#endif

// clang-format on

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

DEFINE_MOD(MOD2);

#pragma region "Segment Tree Beats"

class SegTreeBeats {
    ll n, n0;
    vll max_v, smax_v, max_c;
    vll min_v, smin_v, min_c;
    vll sum;
    vll len, ladd, lval;

    void update_node_max(ll k, ll x) {
        sum[k] += (x - max_v[k]) * max_c[k];

        if (max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } else if (max_v[k] == smin_v[k]) {
            max_v[k] = smin_v[k] = x;
        } else {
            max_v[k] = x;
        }

        if (lval[k] != LINF && x < lval[k]) {
            lval[k] = x;
        }
    }
    void update_node_min(ll k, ll x) {
        sum[k] += (x - min_v[k]) * min_c[k];

        if (max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } else if (smax_v[k] == min_v[k]) {
            min_v[k] = smax_v[k] = x;
        } else {
            min_v[k] = x;
        }

        if (lval[k] != LINF && lval[k] < x) {
            lval[k] = x;
        }
    }

    void push(ll k) {
        if (n0 - 1 <= k) return;

        if (lval[k] != LINF) {
            updateall(2 * k + 1, lval[k]);
            updateall(2 * k + 2, lval[k]);
            lval[k] = LINF;
            return;
        }

        if (ladd[k] != 0) {
            addall(2 * k + 1, ladd[k]);
            addall(2 * k + 2, ladd[k]);
            ladd[k] = 0;
        }

        if (max_v[k] < max_v[2 * k + 1]) {
            update_node_max(2 * k + 1, max_v[k]);
        }
        if (min_v[2 * k + 1] < min_v[k]) {
            update_node_min(2 * k + 1, min_v[k]);
        }

        if (max_v[k] < max_v[2 * k + 2]) {
            update_node_max(2 * k + 2, max_v[k]);
        }
        if (min_v[2 * k + 2] < min_v[k]) {
            update_node_min(2 * k + 2, min_v[k]);
        }
    }

    void update(ll k) {
        sum[k] = sum[2 * k + 1] + sum[2 * k + 2];

        if (max_v[2 * k + 1] < max_v[2 * k + 2]) {
            max_v[k] = max_v[2 * k + 2];
            max_c[k] = max_c[2 * k + 2];
            smax_v[k] = max(max_v[2 * k + 1], smax_v[2 * k + 2]);
        } else if (max_v[2 * k + 1] > max_v[2 * k + 2]) {
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1];
            smax_v[k] = max(smax_v[2 * k + 1], max_v[2 * k + 2]);
        } else {
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1] + max_c[2 * k + 2];
            smax_v[k] = max(smax_v[2 * k + 1], smax_v[2 * k + 2]);
        }

        if (min_v[2 * k + 1] < min_v[2 * k + 2]) {
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1];
            smin_v[k] = min(smin_v[2 * k + 1], min_v[2 * k + 2]);
        } else if (min_v[2 * k + 1] > min_v[2 * k + 2]) {
            min_v[k] = min_v[2 * k + 2];
            min_c[k] = min_c[2 * k + 2];
            smin_v[k] = min(min_v[2 * k + 1], smin_v[2 * k + 2]);
        } else {
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];
            smin_v[k] = min(smin_v[2 * k + 1], smin_v[2 * k + 2]);
        }
    }

    void _update_min(ll x, ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a || max_v[k] <= x) {
            return;
        }
        if (a <= l && r <= b && smax_v[k] < x) {
            update_node_max(k, x);
            return;
        }

        push(k);
        _update_min(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_min(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _update_max(ll x, ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a || x <= min_v[k]) {
            return;
        }
        if (a <= l && r <= b && x < smin_v[k]) {
            update_node_min(k, x);
            return;
        }

        push(k);
        _update_max(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_max(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void addall(ll k, ll x) {
        max_v[k] += x;
        if (smax_v[k] != -LINF) smax_v[k] += x;
        min_v[k] += x;
        if (smin_v[k] != LINF) smin_v[k] += x;

        sum[k] += len[k] * x;
        if (lval[k] != LINF) {
            lval[k] += x;
        } else {
            ladd[k] += x;
        }
    }

    void updateall(ll k, ll x) {
        max_v[k] = x;
        smax_v[k] = -LINF;
        min_v[k] = x;
        smin_v[k] = LINF;
        max_c[k] = min_c[k] = len[k];

        sum[k] = x * len[k];
        lval[k] = x;
        ladd[k] = 0;
    }

    void _add_val(ll x, ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            addall(k, x);
            return;
        }

        push(k);
        _add_val(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _add_val(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _update_val(ll x, ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            updateall(k, x);
            return;
        }

        push(k);
        _update_val(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_val(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    ll _query_max(ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a) {
            return -LINF;
        }
        if (a <= l && r <= b) {
            return max_v[k];
        }
        push(k);
        ll lv = _query_max(a, b, 2 * k + 1, l, (l + r) / 2);
        ll rv = _query_max(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(lv, rv);
    }

    ll _query_min(ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a) {
            return LINF;
        }
        if (a <= l && r <= b) {
            return min_v[k];
        }
        push(k);
        ll lv = _query_min(a, b, 2 * k + 1, l, (l + r) / 2);
        ll rv = _query_min(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(lv, rv);
    }

    ll _query_sum(ll a, ll b, ll k, ll l, ll r) {
        if (b <= l || r <= a) {
            return 0;
        }
        if (a <= l && r <= b) {
            return sum[k];
        }
        push(k);
        ll lv = _query_sum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll rv = _query_sum(a, b, 2 * k + 2, (l + r) / 2, r);
        return lv + rv;
    }

public:
    SegTreeBeats(ll _n) : SegTreeBeats(_n, nullptr) {}
    SegTreeBeats(const vll &a) : SegTreeBeats(a.size(), a.data()) {}

    SegTreeBeats(ll _n, const ll *a) : n(_n),
                                       max_v(_n * 4), smax_v(_n * 4), max_c(_n * 4),
                                       min_v(_n * 4), smin_v(_n * 4), min_c(_n * 4),
                                       sum(_n * 4), len(_n * 4), ladd(_n * 4), lval(_n * 4) {
        n0 = 1;
        while (n0 < n) n0 <<= 1;

        for (ll i = 0; i < 2 * n0; ++i) ladd[i] = 0, lval[i] = LINF;
        len[0] = n0;
        for (ll i = 0; i < n0 - 1; ++i) len[2 * i + 1] = len[2 * i + 2] = (len[i] >> 1);

        for (ll i = 0; i < n; ++i) {
            max_v[n0 - 1 + i] = min_v[n0 - 1 + i] = sum[n0 - 1 + i] = (a != nullptr ? a[i] : 0);
            smax_v[n0 - 1 + i] = -LINF;
            smin_v[n0 - 1 + i] = LINF;
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 1;
        }

        for (ll i = n; i < n0; ++i) {
            max_v[n0 - 1 + i] = smax_v[n0 - 1 + i] = -LINF;
            min_v[n0 - 1 + i] = smin_v[n0 - 1 + i] = LINF;
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;
        }
        for (ll i = n0 - 2; i >= 0; i--) {
            update(i);
        }
    }

    // range minimize query
    void update_min(ll a, ll b, ll x) {
        _update_min(x, a, b, 0, 0, n0);
    }

    // range maximize query
    void update_max(ll a, ll b, ll x) {
        _update_max(x, a, b, 0, 0, n0);
    }

    // range add query
    void add_val(ll a, ll b, ll x) {
        _add_val(x, a, b, 0, 0, n0);
    }

    // range update query
    void update_val(ll a, ll b, ll x) {
        _update_val(x, a, b, 0, 0, n0);
    }

    // range minimum query
    ll query_max(ll a, ll b) {
        return _query_max(a, b, 0, 0, n0);
    }

    // range maximum query
    ll query_min(ll a, ll b) {
        return _query_min(a, b, 0, 0, n0);
    }

    // range sum query
    ll query_sum(ll a, ll b) {
        return _query_sum(a, b, 0, 0, n0);
    }
};

#pragma endregion

void solve() {
    LL(N);
    VLL(P, N);
    LL(M);
    VLL(A, M);
    repi(i, P) i--;
    fenwick_tree<ll> ft(N);
    vll inv(N);
    rep(i, N) {
        inv[i] = ft.sum(P[i], N);
        ft.add(P[i], 1);
    }
    SegTreeBeats tree(inv);
    repi(r, A) {
        tree.add_val(0, r, -1);
        tree.update_max(0, r, 0);
        print(tree.query_sum(0, N));
    }
}
