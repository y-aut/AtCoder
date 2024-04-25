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
#define MLL(...) VAR(mll, __VA_ARGS__)
#define CHR(...) VAR(char, __VA_ARGS__)
#define STR(...) VAR(string, __VA_ARGS__)
#define DBL(...) VAR(double, __VA_ARGS__)
#define VI(a, b) auto a = in_vi(b)
#define VLL(a, b) auto a = in_vll(b)
#define VMLL(a, b) auto a = in_vmll(b)
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

// conversion
inline mll to_mll(ll v) { return mll(to_string(v)); }

// change min/max
template <typename T, typename S> inline bool chmin(T &a, const S &b) { return a > b && (a = b, true); }
template <typename T, typename S> inline bool chmax(T &a, const S &b) { return a < b && (a = b, true); }

// math
inline ll powll(ll a, ll b) { ll ans = 1; rep(i, b) ans *= a; return ans; }
inline ll llceil(ll a, ll b) { return a % b == 0 ? a / b : (a >= 0 ? (a / b) + 1 : -((-a) / b)); }
inline ll llfloor(ll a, ll b) { return a % b == 0 ? a / b : (a >= 0 ? (a / b) : -((-a) / b) - 1); }

// print
template <typename T> inline void print(const T &v, string end = "\n") { cout << v << end; }
template <int V> inline void print(const static_modint<V> &v, string end = "\n") { print(v.val(), end); }
inline void print(const modint &v, string end = "\n") { print(v.val(), end); }
template <typename T, typename S> inline void print(const pair<T, S> &v, string end = "\n")
    { cout << v.first << " " << v.second << end; }
template <typename T, typename S> inline void print(const vector<pair<T, S>> &v) { repi(i, v) print(i); }
template <typename T, typename S> inline void print(const map<T, S> &v) { repi(i, v) print(i); }
template <typename T> inline void print(const vector<T> &v, string sep = " ")
    { rep(i, v.size()) print(v[i], i != (ll)v.size() - 1 ? sep : ""); cout << '\n'; }
template <typename T> inline void print(const set<T> &v, string sep = " ")
    { repi(i, v) print(i, i != *prev(v.end()) ? sep : ""); cout << '\n'; }
template <typename T> inline void print(const vector<vector<T>> &v) { repi(i, v) print(i); }

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

DEFINE_MOD(MOD);

/**
 * @brief Link Cut Tree
 *
 */
template <typename T, typename F, typename S>
struct LinkCutTree {

private:
    F f;
    S s;

    struct Node {
        Node *l, *r, *p;
        T key, sum;
        bool rev;
        size_t sz;

        explicit Node(const T &v) : key(v), sum(v), sz(1), rev(false),
                                    l(nullptr), r(nullptr), p(nullptr) {}

        bool is_root() const {
            return not p or (p->l != this and p->r != this);
        }
    };

public:
    using NP = Node *;

private:
    NP update(NP t) {
        t->sz = 1;
        t->sum = t->key;
        if (t->l) t->sz += t->l->sz, t->sum = f(t->l->sum, t->sum);
        if (t->r) t->sz += t->r->sz, t->sum = f(t->sum, t->r->sum);
        return t;
    }

    void rotr(NP t) {
        NP x = t->p, y = x->p;
        if ((x->l = t->r)) t->r->p = x;
        t->r = x, x->p = t;
        update(x), update(t);
        if ((t->p = y)) {
            if (y->l == x) y->l = t;
            if (y->r == x) y->r = t;
            update(y);
        }
    }

    void rotl(NP t) {
        NP x = t->p, y = x->p;
        if ((x->r = t->l)) t->l->p = x;
        t->l = x, x->p = t;
        update(x), update(t);
        if ((t->p = y)) {
            if (y->l == x) y->l = t;
            if (y->r == x) y->r = t;
            update(y);
        }
    }

    void toggle(NP t) {
        swap(t->l, t->r);
        t->sum = s(t->sum);
        t->rev ^= true;
    }

    void push(NP t) {
        if (t->rev) {
            if (t->l) toggle(t->l);
            if (t->r) toggle(t->r);
            t->rev = false;
        }
    }

    void splay(NP t) {
        push(t);
        while (not t->is_root()) {
            NP q = t->p;
            if (q->is_root()) {
                push(q), push(t);
                if (q->l == t) rotr(t);
                else rotl(t);
            } else {
                NP r = q->p;
                push(r), push(q), push(t);
                if (r->l == q) {
                    if (q->l == t) rotr(q), rotr(t);
                    else rotl(t), rotr(t);
                } else {
                    if (q->r == t) rotl(q), rotl(t);
                    else rotr(t), rotl(t);
                }
            }
        }
    }

public:
    LinkCutTree(const F &f, const S &s) : f(f), s(s) {}

    NP alloc(const T &v = T()) {
        return new Node(v);
    }

    vector<NP> build(vector<T> &vs) {
        vector<NP> nodes(vs.size());
        for (int i = 0; i < (int)vs.size(); i++) {
            nodes[i] = alloc(vs[i]);
        }
        return nodes;
    }

    NP expose(NP t) {
        NP rp = nullptr;
        for (NP cur = t; cur; cur = cur->p) {
            splay(cur);
            cur->r = rp;
            update(cur);
            rp = cur;
        }
        splay(t);
        return rp;
    }

    void evert(NP t) {
        expose(t);
        toggle(t);
        push(t);
    }

    void link(NP child, NP parent) {
        if (is_connected(child, parent)) {
            throw runtime_error("child and parent must be different connected components");
        }
        if (child->l) {
            throw runtime_error("child must be root");
        }
        child->p = parent;
        parent->r = child;
        update(parent);
    }

    void cut(NP child) {
        expose(child);
        NP parent = child->l;
        if (not parent) {
            throw runtime_error("child must not be root");
        }
        child->l = nullptr;
        parent->p = nullptr;
        update(child);
    }

    bool is_connected(NP u, NP v) {
        expose(u), expose(v);
        return u == v or u->p;
    }

    NP lca(NP u, NP v) {
        if (not is_connected(u, v)) return nullptr;
        expose(u);
        return expose(v);
    }

    NP get_kth(NP x, int k) {
        expose(x);
        while (x) {
            push(x);
            if (x->r && x->r->sz > k) {
                x = x->r;
            } else {
                if (x->r) k -= x->r->sz;
                if (k == 0) {
                    splay(x);
                    return x;
                }
                k -= 1;
                x = x->l;
            }
        }
        return nullptr;
    }

    const T &query(NP u) {
        expose(u);
        return u->sum;
    }

    const T &query(NP u, NP v) {
        evert(u);
        return query(v);
    }

    void set_key(NP t, T v) {
        expose(t);
        t->key = v;
        update(t);
    }
};

template <typename T, typename F, typename S>
LinkCutTree<T, F, S> get_link_cut_tree(const F &f, const S &s) {
    return {f, s};
}

void solve() {
    LL(N, Q);

    ll X = 0;

    auto f = [](ll a, ll b) { return a + b; };
    auto s = [](ll v) { return v; };

    auto lct = get_link_cut_tree<ll>(f, s);
    vll nums(N);
    rep(i, N) nums[i] = i;
    auto nodes = lct.build(nums);

    rep(q, Q) {
        LL(a, b, c);
        ll A = ((a * (1 + X)) % MOD2) % 2;
        ll u = ((b * (1 + X)) % MOD2) % N;
        ll v = ((c * (1 + X)) % MOD2) % N;
        if (A == 0) {
            lct.evert(nodes[u]);
            lct.link(nodes[u], nodes[v]);
        } else {
            ll ans = -1;
            if (lct.is_connected(nodes[u], nodes[v])) {
                auto up = lct.get_kth(nodes[u], 1);
                auto vp = lct.get_kth(nodes[v], 1);
                auto upp = lct.get_kth(nodes[u], 2);
                auto vpp = lct.get_kth(nodes[v], 2);
                if (up == vp) ans = up->key;
                else if (up != nullptr && upp == nodes[v]) ans = up->key;
                else if (vp != nullptr && vpp == nodes[u]) ans = vp->key;
            }
            ans++;
            print(ans);
            X = ans;
        }
    }
}
