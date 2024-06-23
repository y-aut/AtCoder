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

/* templates */
#define TPL_T template <typename T>
#define TPL_TS template <typename T, typename S>
#define TPL_TSU template <typename T, typename S, typename U>
#define TPL_TSUV template <typename T, typename S, typename U, typename V>
#define TPL_TSUVW template <typename T, typename S, typename U, typename V, typename W>

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
TPL_TS inline void print(const vector<pair<T, S>> &v) { repi(i, v) print(i); }
TPL_TS inline void print(const map<T, S> &v) { repi(i, v) print(i); }
TPL_T inline typename enable_if<is_base_of<forward_iterator_tag,
    typename iterator_traits<T>::iterator_category>::value>::type print(const T &begin, const T &end, string sep = " ")
    { for (auto i = begin; i != end; i++) print(*i, i != prev(end) ? sep : ""); cout << '\n'; }
TPL_T inline void print(const vector<T> &v, string sep = " ") { print(all(v), sep); }
TPL_T inline void print(const set<T> &v, string sep = " ") { print(all(v), sep); }
TPL_T inline void print(const vector<vector<T>> &v) { repi(i, v) print(i); }
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
                children[j].pb(i);
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
        set_partial_size();
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

    // 重心の一つを取得する
    ll get_centroid() const {
        ll v = get_root();
        while (true) {
            ll max_size = 0, max_c = 0;
            repi(c, get_children(v)) {
                if (chmax(max_size, get_partial_size(c))) max_c = c;
            }
            if (max_size <= get_size() / 2) return v;
            v = max_c;
        }
    }
};

#pragma endregion

#pragma region "LCADoubling"

// 木の LCA をダブリングを用いて計算する
class LCADoubling : public Tree {
    // doubling[i][j]: j から 2^i 個頂点を遡った祖先
    vvll doubling;

    // 最上位ビットの下から数えた位置を取得
    static int msb_pos(const ull x) {
        return x == 0 ? -1 : (sizeof(ull)) * 8 - __builtin_clzll(x) - 1;
    }

    void set_doubling() {
        int d_size = msb_pos(height) + 1;
        rep(i, d_size) doubling.pb(vll(size));
        rep(i, size) doubling[0][i] = parents[i];
        rep(i, d_size - 1) {
            rep(j, size) {
                doubling[i + 1][j] = doubling[i][doubling[i][j]];
            }
        }
    }

public:
    LCADoubling(const vvll &_edges, ll _root = 0) : Tree(_edges, _root) {
        set_doubling();
    }

    // v の d 個上の祖先を取得する
    ll level_ancestor(ll v, ll d) const {
        repd(i, doubling.size()) {
            if (1 << i <= d) {
                d -= 1 << i;
                v = doubling[i][v];
            }
        }
        return v;
    }

    ll get_lca(ll v1, ll v2) const {
        // v1, v2 の深さを揃える
        if (depth[v1] > depth[v2]) {
            v1 = level_ancestor(v1, depth[v1] - depth[v2]);
        } else if (depth[v1] < depth[v2]) {
            v2 = level_ancestor(v2, depth[v2] - depth[v1]);
        }

        if (v1 == v2)
            return v1;
        repd(i, doubling.size()) {
            if (doubling[i][v1] != doubling[i][v2]) {
                v1 = doubling[i][v1];
                v2 = doubling[i][v2];
            }
        }
        return parents[v1];
    }

    ll get_dist(ll v1, ll v2) const {
        auto l = get_lca(v1, v2);
        return depth[v1] + depth[v2] - 2 * depth[l];
    }
};

#pragma endregion

#pragma region "Auxiliary Tree"

class AuxiliaryTree : public LCADoubling {
private:
    // 各節点に対して，行きがけ順での番号を格納したもの
    vll preorder_map;
    // 各節点に対して，Euler Tour における最初の出現位置，最後の出現位置のペア
    vpll et_map;

    void set_maps() {
        auto preorder = get_preorder();
        preorder_map.resize(size);
        rep(i, preorder.size()) preorder_map[preorder[i]] = i;
        auto et = get_euler_tour();
        et_map.resize(size, {-1, -1});
        rep(i, et.size()) {
            if (et_map[et[i]].first == -1) et_map[et[i]].first = i;
            et_map[et[i]].second = i;
        }
    }

public:
    AuxiliaryTree(const vvll &_edges, ll _root = 0) : LCADoubling(_edges, _root) {
        set_maps();
    }

    /// @brief Auxiliary Tree を取得する
    /// @param nodes 頂点集合．Auxiliary Tree に登場する頂点を行きがけ順に並べたものに更新される
    /// @return Auxiliary Tree の各頂点の親
    umll get_auxiliary_tree(vll &nodes) const {
        sort(all(nodes), [&](ll a, ll b) { return preorder_map.at(a) < preorder_map.at(b); });
        ll m = nodes.size();
        rep(i, m - 1) nodes.pb(get_lca(nodes[i], nodes[i + 1]));
        sort(all(nodes), [&](ll a, ll b) { return preorder_map.at(a) < preorder_map.at(b); });
        nodes.erase(unique(all(nodes)), nodes.end());
        umll ans;
        stack<ll> s;
        s.push(nodes[0]);
        rep(i, 1, nodes.size()) {
            while (et_map[s.top()].second < et_map[nodes[i]].first) s.pop();
            ans[nodes[i]] = s.top();
            s.push(nodes[i]);
        }
        return ans;
    }
};

#pragma endregion

void solve() {
    LL(N);
    auto edges = in_edges<true>(N, N - 1);
    AuxiliaryTree tree(edges);
    VLL(A, N);
    um<ll, vll> cnodes;
    rep(i, N) cnodes[A[i]].pb(i);
    ll ans = 0;
    auto f = [&](auto rc, ll c, ll ccnt, ll v, um<ll, vll> &children) -> ll {
        ll ret = 0;
        repi(i, children[v]) {
            auto res = rc(rc, c, ccnt, i, children);
            ans += res * (ccnt - res) * (tree.get_depth(i) - tree.get_depth(v));
            ret += res;
        }
        if (A[v] == c) ret++;
        return ret;
    };
    repi(c, nodes, cnodes) {
        ll ccnt = nodes.size();
        auto pars = tree.get_auxiliary_tree(nodes);
        um<ll, vll> children;
        repi(v, p, pars) children[p].pb(v);
        f(f, c, ccnt, nodes.front(), children);
    }
    print(ans);
}
