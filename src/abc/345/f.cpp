#pragma region "Template"

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

// clang-format on

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

DEFINE_MOD(MOD);

#pragma region "Tree"

class Tree {
protected:
    const ll size;
    const vvll &edges;
    const ll root;
    vll depth;
    ll height; // max(depth) + 1
    vll parents;
    vvll children;
    vll partial_size; // 部分木のノード数

private:
    void set_depth() {
        set_depth_impl(0, 0);
        height = *max_element(all(depth)) + 1;
    }

    void set_depth_impl(ll v, ll d) {
        depth[v] = d;
        repi(i, edges[v]) {
            if (depth[i] == -1)
                set_depth_impl(i, d + 1);
        }
    }

    void set_parents_and_children() {
        parents[root] = root;
        rep(i, size) repi(j, edges[i]) {
            if (depth[i] < depth[j]) {
                parents[j] = i;
            } else {
                // children[j].pb(i);
            }
        }
    }

    void get_preorder_impl(vll &order, ll v) const {
        order.pb(v);
        repi(i, children[v]) {
            get_preorder_impl(order, i);
        }
    }

    void get_postorder_impl(vll &order, ll v) const {
        repi(i, children[v]) {
            get_postorder_impl(order, i);
        }
        order.pb(v);
    }

    void get_euler_tour_impl(vll &order, ll v) const {
        order.pb(v);
        repi(i, children[v]) {
            get_euler_tour_impl(order, i);
            order.pb(v);
        }
    }

    void set_partial_size() {
        set_partial_size_impl(root);
    }

    void set_partial_size_impl(ll v) {
        partial_size[v] = 1;
        repi(c, children[v]) {
            set_partial_size_impl(c);
            partial_size[v] += partial_size[c];
        }
    }

public:
    Tree(const vvll &_edges, ll _root = 0) : size(_edges.size()), edges(_edges), root(_root), depth(size, -1),
                                             parents(size, -1), children(size, vll()), partial_size(size, 0) {
        if (size == 0) {
            throw "The tree size is 0.";
        }
        set_depth();
        set_parents_and_children();
        // set_partial_size();
    }

    ll get_size() const { return size; }
    ll get_root() const { return root; }
    const vll &get_depth() const { return depth; }
    ll get_depth(ll v) const { return depth[v]; }
    ll get_height() const { return height; }
    const vvll &get_edges() const { return edges; }
    const vll &get_edges(ll v) const { return edges[v]; }
    const vll &get_parent() const { return parents; }
    ll get_parent(ll v) const { return parents[v]; }
    const vvll &get_children() const { return children; }
    const vll &get_children(ll v) const { return children[v]; }
    const vll &get_partial_size() const { return partial_size; }
    ll get_partial_size(ll v) const { return partial_size[v]; }

    // 行きがけ順に頂点を取得する
    vll get_preorder() const {
        auto ans = vll();
        get_preorder_impl(ans, root);
        return ans;
    }

    // 帰りがけ順に頂点を取得する
    vll get_postorder() const {
        auto ans = vll();
        get_postorder_impl(ans, root);
        return ans;
    }

    // オイラーツアーを取得する
    vll get_euler_tour() const {
        auto ans = vll();
        get_euler_tour_impl(ans, root);
        return ans;
    }
};

#pragma endregion

vpll f(ll N, ll K, const vpll &edges) {
    if (K == 0) return vpll();
    dsu uf(N);
    vvll edges2(N);
    repi(i, edges) {
        if (!uf.same(i.first, i.second)) {
            edges2[i.first].pb(i.second);
            edges2[i.second].pb(i.first);
            uf.merge(i.first, i.second);
        }
    }
    Tree tree(edges2);
    vpll depth;
    rep(i, N) depth.eb(tree.get_depth(i), i);
    sort(all(depth), [](const pll &a, const pll &b) {
        return a.first == b.first ? a.second > b.second : a.first > b.first;
    });
    vpll ans;
    vb color(N);
    ll color_cnt = 0;
    repi(i, depth) {
        if (!color[i.second]) {
            color[i.second] = true;
            ans.eb(i.second, tree.get_parent(i.second));
            if (color[tree.get_parent(i.second)] = !color[tree.get_parent(i.second)]) {
                color_cnt += 2;
            }
        }
        if (color_cnt == K) return ans;
    }
    return ans;
}

void solve() {
    LL(N, M, K);
    VPLL(uv, M);
    repi(i, uv) {
        i.first--;
        i.second--;
    }

    if (K % 2 != 0) {
        No;
        return;
    }

    dsu uf(N);
    repi(i, uv) uf.merge(i.first, i.second);

    auto groups = uf.groups();
    ll total = 0;
    repi(i, groups) total += (i.size() / 2) * 2;
    if (total < K) {
        No;
        return;
    }

    ll cur = 0;
    vll ans;
    repi(i, groups) {
        if (i.size() == 1) continue;
        ll goal = min(K - cur, ((ll)i.size() / 2) * 2);
        umll idx;
        rep(j, i.size()) idx[i[j]] = j;
        vpll edges;
        umll edge_num;
        rep(j, M) {
            if (idx.count(uv[j].first)) {
                edges.eb(idx[uv[j].first], idx[uv[j].second]);
                edge_num[idx[uv[j].first] * N + idx[uv[j].second]] =
                    edge_num[idx[uv[j].second] * N + idx[uv[j].first]] = j + 1;
            }
        }
        auto res = f(i.size(), goal, edges);
        repi(j, res) ans.pb(edge_num[j.first * N + j.second]);
        cur += goal;
        if (cur == K) break;
    }
    Yes;
    print(ans.size());
    print(ans);
}
