#pragma region "Template"

#ifdef DEBUG
#include "template.hpp"
#else
#ifndef TEMPLATE_H
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
using mll = mpz_class;
using md = mpf_class;
// pair
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// vector
TPL_T using v = vector<T>;
TPL_T using vv = v<v<T>>;
TPL_T using vvv = v<vv<T>>;
using vi = v<int>;
using vll = v<ll>;
using vmll = v<mll>;
using vd = v<double>;
using vmd = v<md>;
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
#define DEFINE_MOD(m)               \
    using mint = static_modint<m>;  \
    using vm = v<mint>;             \
    using vvm = v<vm>;              \
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
#define DBL(...) VAR(double, __VA_ARGS__)
#define CHR(...) VAR(char, __VA_ARGS__)
#define STR(...) VAR(string, __VA_ARGS__)
#define PII(...) VAR(pii, __VA_ARGS__)
#define PLL(...) VAR(pll, __VA_ARGS__)
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

// istream
TPL_TS istream &operator>>(istream &is, pair<T, S> &v) { is >> v.first >> v.second; return is; }

/* func */
// input
inline int in_int() { int x; cin >> x; return x; }
inline ll in_ll() { ll x; cin >> x; return x; }
inline mll in_mll() { mll x; cin >> x; return x; }
inline double in_double() { double x; cin >> x; return x; }
inline char in_char() { char c; cin >> c; return c; }
inline string in_str() { string x; cin >> x; return x; }
inline pii in_pii() { pii x; cin >> x; return x; }
inline pll in_pll() { pll x; cin >> x; return x; }
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

// conversion
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
double abs(const pll &p) { return sqrt(abs2(p)); }

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
template <int V> ostream &operator<<(ostream &os, const static_modint<V> &v) { os << v.val(); return os; }
ostream &operator<<(ostream &os, const modint &v) { os << v.val(); return os; }
TPL_TS ostream &operator<<(ostream &os, const pair<T, S> &v) { os << v.first << " " << v.second; return os; }

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
#define debugs(...) (void)0
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

/**
 * @brief Succinct Indexable Dictionary(完備辞書)
 */
struct SuccinctIndexableDictionary {
    size_t length;
    size_t blocks;
    vector<unsigned> bit, sum;

    SuccinctIndexableDictionary() = default;

    SuccinctIndexableDictionary(size_t length) : length(length), blocks((length + 31) >> 5) {
        bit.assign(blocks, 0U);
        sum.assign(blocks, 0U);
    }

    void set(int k) {
        bit[k >> 5] |= 1U << (k & 31);
    }

    void build() {
        sum[0] = 0U;
        for (int i = 1; i < blocks; i++) {
            sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);
        }
    }

    bool operator[](int k) {
        return (bool((bit[k >> 5] >> (k & 31)) & 1));
    }

    int rank(int k) {
        return (sum[k >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));
    }

    int rank(bool val, int k) {
        return (val ? rank(k) : k - rank(k));
    }
};

/*
 * @brief Wavelet Matrix(ウェーブレット行列)
 *
 */
template <typename T, int MAXLOG>
struct WaveletMatrix {
    size_t length;
    SuccinctIndexableDictionary matrix[MAXLOG];
    int mid[MAXLOG];

    WaveletMatrix() = default;

    WaveletMatrix(vector<T> v) : length(v.size()) {
        vector<T> l(length), r(length);
        for (int level = MAXLOG - 1; level >= 0; level--) {
            matrix[level] = SuccinctIndexableDictionary(length + 1);
            int left = 0, right = 0;
            for (int i = 0; i < length; i++) {
                if (((v[i] >> level) & 1)) {
                    matrix[level].set(i);
                    r[right++] = v[i];
                } else {
                    l[left++] = v[i];
                }
            }
            mid[level] = left;
            matrix[level].build();
            v.swap(l);
            for (int i = 0; i < right; i++) {
                v[left + i] = r[i];
            }
        }
    }

    pair<int, int> succ(bool f, int l, int r, int level) {
        return {matrix[level].rank(f, l) + mid[level] * f, matrix[level].rank(f, r) + mid[level] * f};
    }

    // v[k]
    T access(int k) {
        T ret = 0;
        for (int level = MAXLOG - 1; level >= 0; level--) {
            bool f = matrix[level][k];
            if (f) ret |= T(1) << level;
            k = matrix[level].rank(f, k) + mid[level] * f;
        }
        return ret;
    }

    T operator[](const int &k) {
        return access(k);
    }

    // count i s.t. (0 <= i < r) && v[i] == x
    int rank(const T &x, int r) {
        int l = 0;
        for (int level = MAXLOG - 1; level >= 0; level--) {
            tie(l, r) = succ((x >> level) & 1, l, r, level);
        }
        return r - l;
    }

    // k-th(0-indexed) smallest number in v[l,r)
    T kth_smallest(int l, int r, int k) {
        assert(0 <= k && k < r - l);
        T ret = 0;
        for (int level = MAXLOG - 1; level >= 0; level--) {
            int cnt = matrix[level].rank(false, r) - matrix[level].rank(false, l);
            bool f = cnt <= k;
            if (f) {
                ret |= T(1) << level;
                k -= cnt;
            }
            tie(l, r) = succ(f, l, r, level);
        }
        return ret;
    }

    // k-th(0-indexed) largest number in v[l,r)
    T kth_largest(int l, int r, int k) {
        return kth_smallest(l, r, r - l - k - 1);
    }

    // count i s.t. (l <= i < r) && (v[i] < upper)
    int range_freq(int l, int r, T upper) {
        int ret = 0;
        for (int level = MAXLOG - 1; level >= 0; level--) {
            bool f = ((upper >> level) & 1);
            if (f) ret += matrix[level].rank(false, r) - matrix[level].rank(false, l);
            tie(l, r) = succ(f, l, r, level);
        }
        return ret;
    }

    // count i s.t. (l <= i < r) && (lower <= v[i] < upper)
    int range_freq(int l, int r, T lower, T upper) {
        return range_freq(l, r, upper) - range_freq(l, r, lower);
    }

    // max v[i] s.t. (l <= i < r) && (v[i] < upper)
    T prev_value(int l, int r, T upper) {
        int cnt = range_freq(l, r, upper);
        return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);
    }

    // min v[i] s.t. (l <= i < r) && (lower <= v[i])
    T next_value(int l, int r, T lower) {
        int cnt = range_freq(l, r, lower);
        return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);
    }
};

template <typename T, int MAXLOG>
struct CompressedWaveletMatrix {
    WaveletMatrix<int, MAXLOG> mat;
    vector<T> ys;

    CompressedWaveletMatrix(const vector<T> &v) : ys(v) {
        sort(begin(ys), end(ys));
        ys.erase(unique(begin(ys), end(ys)), end(ys));
        vector<int> t(v.size());
        for (int i = 0; i < v.size(); i++) t[i] = get(v[i]);
        mat = WaveletMatrix<int, MAXLOG>(t);
    }

    inline int get(const T &x) {
        return lower_bound(begin(ys), end(ys), x) - begin(ys);
    }

    T access(int k) {
        return ys[mat.access(k)];
    }

    T operator[](const int &k) {
        return access(k);
    }

    int rank(const T &x, int r) {
        auto pos = get(x);
        if (pos == ys.size() || ys[pos] != x) return 0;
        return mat.rank(pos, r);
    }

    T kth_smallest(int l, int r, int k) {
        return ys[mat.kth_smallest(l, r, k)];
    }

    T kth_largest(int l, int r, int k) {
        return ys[mat.kth_largest(l, r, k)];
    }

    int range_freq(int l, int r, T upper) {
        return mat.range_freq(l, r, get(upper));
    }

    int range_freq(int l, int r, T lower, T upper) {
        return mat.range_freq(l, r, get(lower), get(upper));
    }

    T prev_value(int l, int r, T upper) {
        auto ret = mat.prev_value(l, r, get(upper));
        return ret == -1 ? T(-1) : ys[ret];
    }

    T next_value(int l, int r, T lower) {
        auto ret = mat.next_value(l, r, get(lower));
        return ret == -1 ? T(-1) : ys[ret];
    }
};

void solve() {
    INT(N);
    VI(A, N);

    vi inv(N + 1);
    rep(i, N) inv[A[i]] = i;

    WaveletMatrix<int, 20> mat(A), invmat(inv);

    auto cnt_more_less = [&](ll l, ll r, ll lower, ll upper) -> ll {
        if (l >= r || lower >= upper) return 0;
        return mat.range_freq(l, r, upper) - mat.range_freq(l, r, lower);
    };

    vvi arr{{0, N, 1, N + 1}};
    INT(Q);
    rep(q, Q) {
        INT(t, s, x);
        if (t == 1) {
            int c = cnt_more_less(0, arr[s][0], arr[s][2], arr[s][3]);
            if (c + x >= arr[s][3] - arr[s][2]) {
                arr.pb({0, 0, 0, 0});
            } else {
                int p = invmat.kth_smallest(arr[s][2], arr[s][3], c + x);
                if (p >= arr[s][1]) {
                    arr.pb({0, 0, 0, 0});
                } else {
                    arr.pb({p, arr[s][1], arr[s][2], arr[s][3]});
                    arr[s][1] = p;
                }
            }
        } else {
            arr.pb({arr[s][0], arr[s][1], max(x + 1, arr[s][2]), arr[s][3]});
            chmin(arr[s][3], x + 1);
        }
        print(cnt_more_less(arr.back()[0], arr.back()[1], arr.back()[2], arr.back()[3]));
    }
}
