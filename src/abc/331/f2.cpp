#pragma region "Template"

#ifdef DEBUG
#include "template.hpp"
#else
#define TEMPLATE_H
#include <atcoder/all>
#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;
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

/* alias */
// type
#define us unordered_set
#define um unordered_map
using ull = unsigned long long;
using ll = long long;
using mll = mpz_class;
using md = mpf_class;
// pair
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// vector
using vi = vector<int>;
using vll = vector<ll>;
using vmll = vector<mll>;
using vd = vector<double>;
using vmd = vector<md>;
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
    using pmm = pair<mint, mint>;   \
    inline vm in_vm(int length) { vm res; rep(i, length) res.pb(in_ll()); return res; } \
    inline vvm in_vvm(int height, int width) { vvm res; rep(i, height) res.pb(in_vm(width)); return res; }

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
#define MLL(...) VAR(mll, __VA_ARGS__)
#define CHR(...) VAR(char, __VA_ARGS__)
#define STR(...) VAR(string, __VA_ARGS__)
#define DBL(...) VAR(double, __VA_ARGS__)
#define VI(a, b) auto a = in_vi(b)
#define VLL(a, b) auto a = in_vll(b)
#define VMLL(a, b) auto a = in_vmll(b)
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

/* func */
// input
inline int in_int() { int x; cin >> x; return x; }
inline ll in_ll() { ll x; cin >> x; return x; }
inline mll in_mll() { mll x; cin >> x; return x; }
inline double in_double() { double x; cin >> x; return x; }
inline pii in_pii() { pii x; cin >> x.first >> x.second; return x; }
inline pll in_pll() { pll x; cin >> x.first >> x.second; return x; }
inline char in_char() { char c; cin >> c; return c; }
inline string in_str() { string x; cin >> x; return x; }
inline vi in_vi(int length) { vi res; rep(i, length) res.pb(in_int()); return res; }
inline vll in_vll(int length) { vll res; rep(i, length) res.pb(in_ll()); return res; }
inline vmll in_vmll(int length) { vmll res; rep(i, length) res.pb(in_mll()); return res; }
inline vd in_vd(int length) { vd res; rep(i, length) res.pb(in_double()); return res; }
inline vc in_vc(int length) { vc res; rep(i, length) res.pb(in_char()); return res; }
inline vs in_vs(int height) { vs res; rep(i, height) res.pb(in_str()); return res; }
inline vpii in_vpii(int height) { vpii res; rep(i, height) res.pb(in_pii()); return res; }
inline vpll in_vpll(int height) { vpll res; rep(i, height) res.pb(in_pll()); return res; }
inline vvi in_vvi(int height, int width) { vvi res; rep(i, height) res.pb(in_vi(width)); return res; }
inline vvll in_vvll(int height, int width) { vvll res; rep(i, height) res.pb(in_vll(width)); return res; }
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

// conversion
inline mll to_mll(ll v) { return mll(to_string(v)); }

// change min/max
template <typename T, typename S> inline bool chmin(T &a, const S &b) { return a > b && (a = b, true); }
template <typename T, typename S> inline bool chmax(T &a, const S &b) { return a < b && (a = b, true); }

// math
inline ll powll(ll a, ll b) { ll ans = 1; rep(i, b) ans *= a; return ans; }
inline ll llceil(ll a, ll b) { return a % b == 0 ? a / b : (a >= 0 ? (a / b) + 1 : -((-a) / b)); }
inline ll llfloor(ll a, ll b) { return a % b == 0 ? a / b : (a >= 0 ? (a / b) : -((-a) / b) - 1); }

// hash
template <typename T> struct Hasher { ull operator()(const T &v) const { return hash<T>()(v); } };
template <> struct Hasher<pii> { ull operator()(const pii &v) const { return (ull)v.first << 32 | (ull)v.second; } };
template <> struct Hasher<pll> { ull operator()(const pll &v) const { return (ull)v.first << 32 | (ull)v.second; } };
template <typename S> using ush = us<S, Hasher<S>>;
template <typename S, typename T> using umh = um<S, T, Hasher<S>>;

// ostream
#define OSTREAM(class, ...) \
    void __inner_print(ostream& os) const { print_all(os, __VA_ARGS__); } \
    friend ostream& operator<<(ostream& os, const class& v) { v.__inner_print(os); return os; }
template <int V> ostream &operator<<(ostream &os, const static_modint<V> &v) { os << v.val(); return os; }
ostream &operator<<(ostream &os, const modint &v) { os << v.val(); return os; }
template <typename T, typename S> ostream &operator<<(ostream &os, const pair<T, S> &v)
    { os << v.first << " " << v.second; return os; }

// print
template <typename T> inline void print(const T &v, string end = "\n") { cout << v << end; }
template <typename T, typename S> inline void print(const vector<pair<T, S>> &v) { repi(i, v) print(i); }
template <typename T, typename S> inline void print(const map<T, S> &v) { repi(i, v) print(i); }
template <typename T> inline typename enable_if<is_base_of<forward_iterator_tag,
    typename iterator_traits<T>::iterator_category>::value>::type print(const T &begin, const T &end, string sep = " ")
    { for (auto i = begin; i != end; i++) print(*i, i != prev(end) ? sep : ""); cout << '\n'; }
template <typename T> inline void print(const vector<T> &v, string sep = " ") { print(all(v), sep); }
template <typename T> inline void print(const set<T> &v, string sep = " ") { print(all(v), sep); }
template <typename T> inline void print(const vector<vector<T>> &v) { repi(i, v) print(i); }
void print_all_inner(ostream&) {}
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
#define debug(...) (void)0
#endif

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = 1152921500000000000LL;
CSI INF = 1000000006;
CSD EPS = 1e-11;
CSD PI = 3.141592653589793;
CSD PHI = 1.6180339887498948;
CSLL DX[] = {1, 0, -1, 0};
CSLL DY[] = {0, 1, 0, -1};
#endif

// clang-format on

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

#pragma region "ローリングハッシュ"

CSLL MOD_SIZE = 6;
const ull HASH_BASE[] = {889293976, 1872217329, 1787722576, 1005514673, 981914693, 1375179334};
const ull HASH_MOD[] = {1944897763, 1925898167, 1912776091, 1935497281, 1939942439, 1902550399};
vector<ull> HASH_BASE_POW[] = {{1}, {1}, {1}, {1}, {1}, {1}};

ull get_hash_base_pow(ll index, ull n) {
    assert(0 <= index && index < MOD_SIZE);
    while (HASH_BASE_POW[index].size() <= n) {
        HASH_BASE_POW[index].pb(HASH_BASE_POW[index].back() * HASH_BASE[index] % HASH_MOD[index]);
    }
    return HASH_BASE_POW[index][n];
}

template <int mod_num = 4>
struct RollingHash {
    ll size;
    array<ull, mod_num> hash = {};

    RollingHash() : size(0) {}
    template <typename T>
    RollingHash(T first, T last) : size(distance(first, last)) {
        ll i = 0;
        for (T itr = first; itr != last; itr++, i++) {
            rep(j, mod_num) {
                hash[j] += get_hash_base_pow(j, size - i - 1) * (*itr);
                hash[j] %= HASH_MOD[j];
            }
        }
    }
    RollingHash(const string &s) : RollingHash(all(s)) {}
    RollingHash(const vll &v) : RollingHash(all(v)) {}
    RollingHash(ll v) : size(1) { rep(i, mod_num) hash[i] = v; }
    RollingHash(const RollingHash &src) : size(src.size), hash(src.hash) {}
    RollingHash(RollingHash &&src) : size(src.size), hash(move(src.hash)) {}

    void pop_front(char c) {
        rep(i, mod_num) {
            hash[i] += HASH_MOD[i] - get_hash_base_pow(i, size - 1) * c % HASH_MOD[i];
            hash[i] %= HASH_MOD[i];
        }
        size--;
    }

    void push_back(char c) {
        rep(i, mod_num) {
            hash[i] *= HASH_BASE[i];
            hash[i] += c;
            hash[i] %= HASH_MOD[i];
        }
        size++;
    }

    RollingHash &operator=(const RollingHash &v) & {
        size = v.size;
        hash = v.hash;
        return *this;
    }
    RollingHash &operator=(RollingHash &&v) & noexcept {
        if (this != &v) {
            size = v.size;
            hash = move(v.hash);
        }
        return *this;
    }
    RollingHash &operator+=(const RollingHash &v) {
        rep(i, mod_num) {
            hash[i] *= get_hash_base_pow(i, v.size);
            hash[i] += v.hash[i];
            hash[i] %= HASH_MOD[i];
        }
        size += v.size;
        return *this;
    }
    friend ostream &operator<<(ostream &os, const RollingHash &v) {
        os << "{ size=" << v.size << ", hash=[";
        rep(i, mod_num) {
            os << v.hash[i] << (i == mod_num - 1 ? "] }" : ", ");
        }
        return os;
    }
};

template <int n>
bool operator==(const RollingHash<n> &a, const RollingHash<n> &b) {
    rep(i, n) if (a.hash[i] != b.hash[i]) return false;
    return a.size == b.size;
}
template <int n>
bool operator!=(const RollingHash<n> &a, const RollingHash<n> &b) { return !(a == b); }
template <int n>
RollingHash<n> operator+(const RollingHash<n> &a, const RollingHash<n> &b) {
    return RollingHash(a) += b;
}

#pragma endregion

using RHash = RollingHash<2>;

struct dat {
    RHash v;
    RHash rev;
    bool same() { return v == rev; }
};
dat op(dat a, const dat &b) {
    a.v += b.v;
    a.rev = b.rev + a.rev;
    return a;
}
dat e() { return {RHash(), RHash()}; }

void solve() {
    LL(N, Q);
    STR(S);
    vector<dat> init;
    repi(c, S) init.eb(RHash(c), RHash(c));
    segtree<dat, op, e> tree(init);
    rep(q, Q) {
        LL(op, a);
        a--;
        if (op == 1) {
            CHR(c);
            tree.set(a, {RHash(c), RHash(c)});
        } else {
            LL(b);
            YesNo(tree.prod(a, b).same());
        }
    }
}
