#pragma region "Template"

#ifdef DEBUG
#include "template.hpp"
#else
#ifndef TEMPLATE_H
#define TEMPLATE_H
#ifndef DEBUG
#define NDEBUG
#endif
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
#define TPL_N template <int N>
#define TPL_TN template <typename T, int N>

/* alias */
// type
#define us unordered_set
#define um unordered_map
using ull = unsigned long long;
using ll = long long;
// pair
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// array
TPL_N using ari = array<int, N>;
TPL_N using arll = array<ll, N>;
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
// priority_queue
TPL_T using pq = priority_queue<T>;
TPL_T using pqg = priority_queue<T, v<T>, greater<T>>;

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
#define OVERLOAD5(_1, _2, _3, _4, _5, x, ...) x
#define OVERLOAD6(_1, _2, _3, _4, _5, _6, x, ...) x

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
#define VARI(a, n, h) auto a = in_vari<n>(h)
#define VARLL(a, n, h) auto a = in_varll<n>(h)
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
#define REPI3(a, b, c, v) for (auto&& [a, b, c] : (v))
#define REPI4(a, b, c, d, v) for (auto&& [a, b, c, d] : (v))
#define rep(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define rrep(...) OVERLOAD3(__VA_ARGS__, RREP2, RREP1)(__VA_ARGS__)
#define repd(...) OVERLOAD3(__VA_ARGS__, REPD2, REPD1)(__VA_ARGS__)
#define rrepd(...) OVERLOAD3(__VA_ARGS__, RREPD2, RREPD1)(__VA_ARGS__)
#define repi(...) OVERLOAD5(__VA_ARGS__, REPI4, REPI3, REPI2, REPI1)(__VA_ARGS__)

/* control */
#define EXIT(...) ({ __VA_ARGS__; exit(0); })
#define BREAK(...) ({ __VA_ARGS__; break; })
#define CONTINUE(...) ({ __VA_ARGS__; continue; })

/* others */
#define BTW1(x, l, r) ((l) <= (x) && (x) < (r))
#define BTW2(x1, l1, r1, x2, l2, r2) (BTW1(x1, l1, r1) && BTW1(x2, l2, r2))
#define BTW(...) OVERLOAD6(__VA_ARGS__, BTW2, , , BTW1)(__VA_ARGS__)

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
TPL_TN inline array<T, N> in_array() { array<T, N> x; rep(i, N) { T t; cin >> t; x[i] = t; } return x; }
TPL_N inline ari<N> in_ari() { ari<N> x; rep(i, N) x[i] = in_int(); return x; }
TPL_N inline arll<N> in_arll() { arll<N> x; rep(i, N) x[i] = in_int(); return x; }
inline vi in_vi(int length) { vi res; rep(i, length) res.pb(in_int()); return res; }
inline vll in_vll(int length) { vll res; rep(i, length) res.pb(in_ll()); return res; }
inline vd in_vd(int length) { vd res; rep(i, length) res.pb(in_double()); return res; }
inline vc in_vc(int length) { vc res; rep(i, length) res.pb(in_char()); return res; }
inline vs in_vs(int height) { vs res; rep(i, height) res.pb(in_str()); return res; }
inline vpii in_vpii(int height) { vpii res; rep(i, height) res.pb(in_pii()); return res; }
inline vpll in_vpll(int height) { vpll res; rep(i, height) res.pb(in_pll()); return res; }
TPL_TN inline v<array<T, N>> in_varray(int height) { v<array<T, N>> res; rep(i, height) res.pb(in_array<T, N>()); return res; }
TPL_N inline v<ari<N>> in_vari(int height) { v<ari<N>> res; rep(i, height) res.pb(in_ari<N>()); return res; }
TPL_N inline v<arll<N>> in_varll(int height) { v<arll<N>> res; rep(i, height) res.pb(in_arll<N>()); return res; }
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
TPL_T inline T powint(T a, T b) { T ans = T(1); rep(i, b) ans *= a; return ans; }
inline ll powll(ll a, ll b) { return powint<ll>(a, b); }
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
TPL_TSU inline void printex(const T &x, const S &ex, const U &val) { if (x == ex) print(val); else print(x); }

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

#pragma region "ei1333/math/rational/rational.hpp"

/**
 * @brief Rational (有理数型)
 */
template <typename T>
struct Rational {
private:
    T num, den;

    static T gcd(T a, T b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        return std::gcd(a, b);
    }

    void normalize() {
        if (num == 0) {
            den = 1;
        } else {
            T g = gcd(num, den);
            num /= g;
            den /= g;
            if (den < 0) {
                num = -num;
                den = -den;
            }
        }
    }

public:
    Rational() : num(0), den(1) {}

    Rational(const T &n) : num(n), den(1) {}

    Rational(const T &n, const T &d) : num(n), den(d) { normalize(); }

    Rational &operator=(const T &n) { return assign(n, 1); }

    Rational &assign(const T &n, const T &d) {
        num = n;
        den = d;
        normalize();
        return *this;
    }

    T numerator() const { return num; }

    T denominator() const { return den; }

    Rational &operator+=(const Rational &r) {
        T r_num = r.num, r_den = r.den;
        T g = gcd(den, r_den);
        den /= g;
        num = num * (r_den / g) + r_num * den;
        g = gcd(num, g);
        num /= g;
        den *= r_den / g;
        return *this;
    }

    Rational &operator-=(const Rational &r) {
        T r_num = r.num, r_den = r.den;
        T g = gcd(den, r_den);
        den /= g;
        num = num * (r_den / g) - r_num * den;
        g = gcd(num, g);
        num /= g;
        den *= r_den / g;
        return *this;
    }

    Rational &operator*=(const Rational &r) {
        T r_num = r.num, r_den = r.den;
        T g1 = gcd(num, r_den);
        T g2 = gcd(den, r_num);
        num = (num / g1) * (r_num / g2);
        den = (den / g2) * (r_den / g1);
        return *this;
    }

    Rational &operator/=(const Rational &r) {
        T r_num = r.num, r_den = r.den;
        T g1 = gcd(num, r_num);
        T g2 = gcd(den, r_den);
        num = (num / g1) * (r_den / g2);
        den = (den / g2) * (r_num / g1);
        if (den < 0) {
            num = -num;
            den = -den;
        }
        return *this;
    }

    Rational &operator+=(const T &i) { return (*this) += Rational{i}; }

    Rational &operator-=(const T &i) { return (*this) -= Rational{i}; }

    Rational &operator*=(const T &i) { return (*this) *= Rational{i}; }

    Rational &operator/=(const T &i) { return (*this) /= Rational{i}; }

    Rational operator+(const Rational &r) const { return Rational(*this) += r; }

    Rational operator-(const Rational &r) const { return Rational(*this) -= r; }

    Rational operator*(const Rational &r) const { return Rational(*this) *= r; }

    Rational operator/(const Rational &r) const { return Rational(*this) /= r; }

    Rational operator+(const T &i) const { return Rational(*this) += i; }

    Rational operator-(const T &i) const { return Rational(*this) -= i; }

    Rational operator*(const T &i) const { return Rational(*this) *= i; }

    Rational operator/(const T &i) const { return Rational(*this) /= i; }

    Rational operator-() const { return Rational{-num, den}; }

    Rational &operator++() {
        num += den;
        return *this;
    }

    Rational &operator--() {
        num -= den;
        return *this;
    }

#define define_cmp(op)                          \
    bool operator op(const Rational &r) const { \
        return num * r.den op r.num * den;      \
    }

    bool operator==(const Rational &r) const {
        return num == r.num && den == r.den;
    }

    bool operator!=(const Rational &r) const {
        return !(*this == r);
    }

    define_cmp(<)

        define_cmp(>)

            define_cmp(<=)

                define_cmp(>=)
#undef define_cmp

                    template <typename Real = double>
                    Real to_double() const {
        return static_cast<Real>(numerator()) / denominator();
    }

    Rational abs() const { return Rational{num < 0 ? -num : num, den}; }

    friend ostream &operator<<(ostream &os, const Rational &r) {
        return os << r.numerator() << "/" << r.denominator();
    }
};

#pragma endregion "ei1333/math/rational/rational.hpp"

#pragma region "ei1333/structure/convex-hull-trick/convex-hull-trick-add-monotone.hpp"

template <typename T, bool isMin>
struct ConvexHullTrickAddMonotone {
#define F first
#define S second
    using P = pair<T, T>;
    deque<P> H;

    ConvexHullTrickAddMonotone() = default;

    bool empty() const { return H.empty(); }

    void clear() { H.clear(); }

    static constexpr int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }

    static constexpr T floor_div(T n, T d) {
        return n / d - ((n ^ d) < 0 and n % d != 0);
    }

    static constexpr bool check(const P &a, const P &b, const P &c) {
        if (b.S == a.S || c.S == b.S)
            return sgn(b.F - a.F) * sgn(c.S - b.S) >= sgn(c.F - b.F) * sgn(b.S - a.S);
        if constexpr (is_integral<T>::value) {
            return floor_div(b.S - a.S, a.F - b.F) >= floor_div(c.S - b.S, b.F - c.F);
        } else {
            return (b.F - a.F) * sgn(c.S - b.S) / abs(b.S - a.S) >=
                   (c.F - b.F) * sgn(b.S - a.S) / abs(c.S - b.S);
        }
    }

    void add(T a, T b) {
        if (!isMin) a *= -1, b *= -1;
        P line(a, b);
        if (empty()) {
            H.emplace_front(line);
            return;
        }
        if (H.front().F <= a) {
            if (H.front().F == a) {
                if (H.front().S <= b) return;
                H.pop_front();
            }
            while (H.size() >= 2 && check(line, H.front(), H[1])) H.pop_front();
            H.emplace_front(line);
        } else {
            assert(a <= H.back().F);
            if (H.back().F == a) {
                if (H.back().S <= b) return;
                H.pop_back();
            }
            while (H.size() >= 2 && check(H[H.size() - 2], H.back(), line))
                H.pop_back();
            H.emplace_back(line);
        }
    }

    static constexpr T get_y(const P &a, const T &x) { return a.F * x + a.S; }

    T query(T x) const {
        assert(!empty());
        int l = -1, r = H.size() - 1;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            if (get_y(H[m], x) >= get_y(H[m + 1], x))
                l = m;
            else
                r = m;
        }
        if (isMin) return get_y(H[r], x);
        return -get_y(H[r], x);
    }

    T query_monotone_inc(T x) {
        assert(!empty());
        while (H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x))
            H.pop_front();
        if (isMin) return get_y(H.front(), x);
        return -get_y(H.front(), x);
    }

    T query_monotone_dec(T x) {
        assert(!empty());
        while (H.size() >= 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x))
            H.pop_back();
        if (isMin) return get_y(H.back(), x);
        return -get_y(H.back(), x);
    }

#undef F
#undef S
};

#pragma endregion "ei1333/structure/convex-hull-trick/convex-hull-trick-add-monotone.hpp"

template <typename T>
T floor(T a, T b) {
    return a / b - (a % b && (a ^ b) < 0);
}

template <typename T>
T ceil(T x, T y) {
    return floor(x + y - 1, y);
}

template <typename T>
pair<T, T> divmod(T x, T y) {
    T q = floor(x, y);
    return {q, x - q * y};
}

// sum_{x in [L,R)} floor(ax + b, mod)
// I は範囲内で ax+b がオーバーフローしない程度
template <typename O, typename I>
O floor_sum_of_linear(I L, I R, I a, I b, I mod) {
    assert(L <= R);
    O res = 0;
    b += L * a;
    I N = R - L;

    if (b < 0) {
        I k = ceil(-b, mod);
        b += k * mod;
        res -= O(N) * O(k);
    }

    while (N) {
        I q;
        tie(q, a) = divmod(a, mod);
        res += (N & 1 ? O(N) * O((N - 1) / 2) * O(q) : O(N / 2) * O(N - 1) * O(q));
        if (b >= mod) {
            tie(q, b) = divmod(b, mod);
            res += O(N) * q;
        }
        tie(N, b) = divmod(a * N + b, mod);
        tie(a, mod) = make_pair(mod, a);
    }
    return res;
}

using R = Rational<__int128_t>;

R abs(R x) { return x < R(0) ? -x : x; }

void solve() {
    LL(T);
    while (T--) {
        LL(N);
        VARLL(ABC, 3, N);
        v<pair<R, R>> pq;
        repi(a, b, c, ABC) {
            pq.eb(R(-a) / b, R(c) / b);
        }
        sort(all(pq));
        ConvexHullTrickAddMonotone<R, true> cht;
        repi(p, q, pq) {
            cht.add(p, q);
        }
        ll ans = 0;
        ll now = 1;
        rep(i, cht.H.size()) {
            auto &&line = cht.H[i];
            if (cht.get_y(line, now) <= 0) break;
            R x, y;
            if (i == cht.H.size() - 1) {
                x = -line.second / line.first;
                y = 0;
            } else {
                auto &&line2 = cht.H[i + 1];
                x = (line2.second - line.second) / (line.first - line2.first);
                y = cht.get_y(line, x);
                if (y < 0) {
                    x = -line.second / line.first;
                    y = 0;
                }
            }
            if (x < 1) continue;
            ll nxt = (x.numerator() + x.denominator() - 1) / x.denominator();
            __int128_t p = line.first.denominator(), q = line.first.numerator(),
                       r = line.second.denominator(), s = line.second.numerator();
            ans += floor_sum_of_linear<__int128_t, __int128_t>(now, nxt, q * r, p * s - 1, p * r);
            now = nxt;
            if (y == 0) break;
        }
        print(ans);
    }
}