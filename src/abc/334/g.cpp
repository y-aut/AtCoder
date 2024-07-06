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
template <bool bidir> inline vvll in_edges(int N, int height)
    { vvll res(N, vll()); rep(i, height) { ll a = in_ll() - 1; ll b = in_ll() - 1;
    res[a].pb(b); if (bidir) res[b].pb(a); } return res; }
template <bool bidir> inline v<usll> in_edges_us(int N, int height)
    { v<usll> res(N, usll()); rep(i, height) { ll a = in_ll() - 1; ll b = in_ll() - 1;
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

DEFINE_MOD(MOD2);

template <typename T>
class dynamic_connectivity {
    class euler_tour_tree {
    public:
        struct node;
        using np = node *;
        using lint = long long;
        struct node {
            np ch[2] = {nullptr, nullptr};
            np p = nullptr;
            int l, r, sz;
            T val = et, sum = et;
            bool exact;
            bool child_exact;
            bool edge_connected = 0;
            bool child_edge_connected = 0;
            node() {}
            node(int l, int r) : l(l), r(r), sz(l == r), exact(l < r), child_exact(l < r) {}
            bool is_root() {
                return !p;
            }
        };
        vector<unordered_map<int, np>> ptr;
        np get_node(int l, int r) {
            if (ptr[l].find(r) == ptr[l].end()) ptr[l][r] = new node(l, r);
            return ptr[l][r];
        }
        np root(np t) {
            if (!t) return t;
            while (t->p) t = t->p;
            return t;
        }
        bool same(np s, np t) {
            if (s) splay(s);
            if (t) splay(t);
            return root(s) == root(t);
        }
        np reroot(np t) {
            auto s = split(t);
            return merge(s.second, s.first);
        }
        pair<np, np> split(np s) {
            splay(s);
            np t = s->ch[0];
            if (t) t->p = nullptr;
            s->ch[0] = nullptr;
            return {t, update(s)};
        }
        pair<np, np> split2(np s) {
            splay(s);
            np t = s->ch[0];
            np u = s->ch[1];
            if (t) t->p = nullptr;
            s->ch[0] = nullptr;
            if (u) u->p = nullptr;
            s->ch[1] = nullptr;
            return {t, u};
        }
        tuple<np, np, np> split(np s, np t) {
            auto u = split2(s);
            if (same(u.first, t)) {
                auto r = split2(t);
                return make_tuple(r.first, r.second, u.second);
            } else {
                auto r = split2(t);
                return make_tuple(u.first, r.first, r.second);
            }
        }
        template <typename First, typename... Rest>
        np merge(First s, Rest... t) {
            return merge(s, merge(t...));
        }
        np merge(np s, np t) {
            if (!s) return t;
            if (!t) return s;
            while (s->ch[1]) s = s->ch[1];
            splay(s);
            s->ch[1] = t;
            if (t) t->p = s;
            return update(s);
        }
        int size(np t) { return t ? t->sz : 0; }
        np update(np t) {
            t->sum = et;
            if (t->ch[0]) t->sum = fn(t->sum, t->ch[0]->sum);
            if (t->l == t->r) t->sum = fn(t->sum, t->val);
            if (t->ch[1]) t->sum = fn(t->sum, t->ch[1]->sum);
            t->sz = size(t->ch[0]) + (t->l == t->r) + size(t->ch[1]);
            t->child_edge_connected = (t->ch[0] ? t->ch[0]->child_edge_connected : 0) | (t->edge_connected) | (t->ch[1] ? t->ch[1]->child_edge_connected : 0);
            t->child_exact = (t->ch[0] ? t->ch[0]->child_exact : 0) | (t->exact) | (t->ch[1] ? t->ch[1]->child_exact : 0);
            return t;
        }
        void push(np t) {
            // 遅延評価予定
        }
        void rot(np t, bool b) {
            np x = t->p, y = x->p;
            if ((x->ch[1 - b] = t->ch[b])) t->ch[b]->p = x;
            t->ch[b] = x, x->p = t;
            update(x);
            update(t);
            if ((t->p = y)) {
                if (y->ch[0] == x) y->ch[0] = t;
                if (y->ch[1] == x) y->ch[1] = t;
                update(y);
            }
        }
        void splay(np t) {
            push(t);
            while (!t->is_root()) {
                np q = t->p;
                if (q->is_root()) {
                    push(q), push(t);
                    rot(t, q->ch[0] == t);
                } else {
                    np r = q->p;
                    push(r), push(q), push(t);
                    bool b = r->ch[0] == q;
                    if (q->ch[1 - b] == t) rot(q, b), rot(t, b);
                    else rot(t, 1 - b), rot(t, b);
                }
            }
        }

    public:
        euler_tour_tree() {}
        euler_tour_tree(int sz) {
            ptr.resize(sz);
            for (int i = 0; i < sz; i++) ptr[i][i] = new node(i, i);
        }
        int size(int s) {
            np t = get_node(s, s);
            splay(t);
            return t->sz;
        }
        bool same(int s, int t) {
            return same(get_node(s, s), get_node(t, t));
        }
        void set_size(int sz) {
            ptr.resize(sz);
            for (int i = 0; i < sz; i++) ptr[i][i] = new node(i, i);
        }
        void update(int s, T x) {
            np t = get_node(s, s);
            splay(t);
            t->val = fn(t->val, x);
            update(t);
        }
        void edge_update(int s, auto g) {
            np t = get_node(s, s);
            splay(t);
            function<void(np)> dfs = [&](np t) {
                assert(t);
                if (t->l < t->r && t->exact) {
                    splay(t);
                    t->exact = 0;
                    update(t);
                    g(t->l, t->r);
                    return;
                }
                if (t->ch[0] && t->ch[0]->child_exact) dfs(t->ch[0]);
                else dfs(t->ch[1]);
            };
            while (t && t->child_exact) {
                dfs(t);
                splay(t);
            }
        }
        bool try_reconnect(int s, auto f) {
            np t = get_node(s, s);
            splay(t);
            function<bool(np)> dfs = [&](np t) -> bool {
                assert(t);
                if (t->edge_connected) {
                    splay(t);
                    return f(t->l);
                }
                if (t->ch[0] && t->ch[0]->child_edge_connected) return dfs(t->ch[0]);
                else return dfs(t->ch[1]);
            };
            while (t->child_edge_connected) {
                if (dfs(t)) return 1;
                splay(t);
            }
            return 0;
        }
        void edge_connected_update(int s, bool b) {
            np t = get_node(s, s);
            splay(t);
            t->edge_connected = b;
            update(t);
        }
        bool link(int l, int r) {
            if (same(l, r)) return 0;
            merge(reroot(get_node(l, l)), get_node(l, r), reroot(get_node(r, r)), get_node(r, l));
            return 1;
        }
        bool cut(int l, int r) {
            if (ptr[l].find(r) == ptr[l].end()) return 0;
            np s, t, u;
            tie(s, t, u) = split(get_node(l, r), get_node(r, l));
            merge(s, u);
            np p = ptr[l][r];
            np q = ptr[r][l];
            ptr[l].erase(r);
            ptr[r].erase(l);
            delete p;
            delete q;
            return 1;
        }
        T get_sum(int p, int v) {
            cut(p, v);
            np t = get_node(v, v);
            splay(t);
            T res = t->sum;
            link(p, v);
            return res;
        }
        T get_sum(int s) {
            np t = get_node(s, s);
            splay(t);
            return t->sum;
        }
    };
    int dep = 1;
    vector<euler_tour_tree> ett;
    vector<vector<unordered_set<int>>> edges;
    int sz;

public:
    dynamic_connectivity(int sz) : sz(sz) {
        ett.emplace_back(sz);
        edges.emplace_back(sz);
    }
    bool link(int s, int t) {
        if (s == t) return 0;
        if (ett[0].link(s, t)) return 1;
        edges[0][s].insert(t);
        edges[0][t].insert(s);
        if (edges[0][s].size() == 1) ett[0].edge_connected_update(s, 1);
        if (edges[0][t].size() == 1) ett[0].edge_connected_update(t, 1);
        return 0;
    }
    bool same(int s, int t) {
        return ett[0].same(s, t);
    }
    int size(int s) {
        return ett[0].size(s);
    }
    vector<int> get_vertex(int s) {
        return ett[0].vertex_list(s);
    }
    void update(int s, T x) {
        ett[0].update(s, x);
    }
    T get_sum(int s) {
        return ett[0].get_sum(s);
    }
    bool cut(int s, int t) {
        if (s == t) return 0;
        for (int i = 0; i < dep; i++) {
            edges[i][s].erase(t);
            edges[i][t].erase(s);
            if (edges[i][s].size() == 0) ett[i].edge_connected_update(s, 0);
            if (edges[i][t].size() == 0) ett[i].edge_connected_update(t, 0);
        }
        for (int i = dep - 1; i >= 0; i--) {
            if (ett[i].cut(s, t)) {
                if (dep - 1 == i) {
                    dep++;
                    ett.emplace_back(sz);
                    edges.emplace_back(sz);
                }
                return !try_reconnect(s, t, i);
            }
        }
        return 0;
    }
    bool try_reconnect(int s, int t, int k) {
        for (int i = 0; i < k; i++) {
            ett[i].cut(s, t);
        }
        for (int i = k; i >= 0; i--) {
            if (ett[i].size(s) > ett[i].size(t)) swap(s, t);
            auto g = [&](int s, int t) { ett[i + 1].link(s, t); };
            ett[i].edge_update(s, g);
            auto f = [&](int x) -> bool {
                for (auto itr = edges[i][x].begin(); itr != edges[i][x].end();) {
                    auto y = *itr;
                    itr = edges[i][x].erase(itr);
                    edges[i][y].erase(x);
                    if (edges[i][x].size() == 0) ett[i].edge_connected_update(x, 0);
                    if (edges[i][y].size() == 0) ett[i].edge_connected_update(y, 0);
                    if (ett[i].same(x, y)) {
                        edges[i + 1][x].insert(y);
                        edges[i + 1][y].insert(x);
                        if (edges[i + 1][x].size() == 1) ett[i + 1].edge_connected_update(x, 1);
                        if (edges[i + 1][y].size() == 1) ett[i + 1].edge_connected_update(y, 1);
                    } else {
                        for (int j = 0; j <= i; j++) {
                            ett[j].link(x, y);
                        }
                        return 1;
                    }
                }
                return 0;
            };
            if (ett[i].try_reconnect(s, f)) return 1;
        }
        return 0;
    }
    constexpr static T et = T();
    constexpr static T fn(T s, T t) {
        return s + t;
    }
};

void solve() {
    LL(H, W);
    VS(S, H);
    vvll ind(H, vll(W));
    ll cur = 0;
    rep(i, H) rep(j, W) {
        if (S[i][j] == '#') ind[i][j] = cur++;
    }
    mint ans = 0, cnt = 0;
    dynamic_connectivity<ll> uf(cur);
    dsu uf2(cur);
    rep(i, H) rep(j, W - 1) {
        if (S[i][j] == '#' && S[i][j + 1] == '#') uf.link(ind[i][j], ind[i][j + 1]), uf2.merge(ind[i][j], ind[i][j + 1]);
    }
    rep(i, H - 1) rep(j, W) {
        if (S[i][j] == '#' && S[i + 1][j] == '#') uf.link(ind[i][j], ind[i + 1][j]), uf2.merge(ind[i][j], ind[i + 1][j]);
    }
    ll ini = uf2.groups().size();
    rep(i, H) rep(j, W) {
        if (S[i][j] == '#') {
            cnt++;
            vll s;
            rep(k, 4) {
                ll ni = i + DY[k], nj = j + DX[k];
                if (!(0 <= ni && ni < H && 0 <= nj && nj < W)) continue;
                if (S[ni][nj] == '.') continue;
                uf.cut(ind[i][j], ind[ni][nj]);
                s.pb(ind[ni][nj]);
            }
            vll leader(s.size());
            rep(k, s.size()) leader[k] = k;
            rep(k, s.size()) rep(l, k + 1, s.size()) {
                if (uf.same(s[k], s[l])) leader[l] = leader[k];
            }
            usll ls;
            repi(k, leader) ls.insert(k);
            ans += ini + ls.size() - 1;
            repi(k, s) uf.link(ind[i][j], k);
        }
    }
    print(ans / cnt);
}
