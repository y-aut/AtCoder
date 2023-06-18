#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

// clang-format off
/* accelration */
// 高速バイナリ生成
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// cin cout の結びつけ解除, stdioと同期しない(入出力非同期化)
// cとstdの入出力を混在させるとバグるので注意
struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;

/* alias */
// type
using ull = unsigned long long;
using ll = long long;
using ld = long double;
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
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvb = vector<vb>;
using vpii = vector<pii>;
using vpll = vector<pll>;
// unordered set
using usi = unordered_set<int>;
using usll = unordered_set<ll>;
using uss = unordered_set<string>;

/* define short */
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<'\n';}else{cout<<"NO"<<'\n';}
#define yesno(bool) if(bool){cout<<"yes"<<'\n';}else{cout<<"no"<<'\n';}
#define YesNo(bool) if(bool){cout<<"Yes"<<'\n';}else{cout<<"No"<<'\n';}
#define CSI constexpr static int
#define CSLL constexpr static ll
#define CSLD constexpr static ld

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

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << '\n';

/* func */
inline int in_int() {int x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline double in_double() {double x; cin >> x; return x;}
inline pii in_pii() {pii x; cin >> x.first >> x.second; return x;}
inline pll in_pll() {pll x; cin >> x.first >> x.second; return x;}
inline char in_char() {char c; cin >> c; return c;}
inline string in_str() {string x; cin >> x; return x;}
inline vi in_vi(int length) {vi res; rep(i, length) res.pb(in_int()); return res;}
inline vll in_vll(int length) {vll res; rep(i, length) res.pb(in_ll()); return res;}
inline vd in_vd(int length) {vd res; rep(i, length) res.pb(in_double()); return res;}
inline vc in_vc(int length) {vc res; rep(i, length) res.pb(in_char()); return res;}
inline vs in_vs(int height) {vs res; rep(i, height) res.pb(in_str()); return res;}
inline vpii in_vpii(int height)
    {vpii res; rep(i, height) {pii tmp; tmp.first = in_int(); tmp.second = in_int(); res.pb(tmp);} return res;}
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
template <typename T> inline void print(const vector<T>& v, string s = " ")
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : ""); cout << '\n';}
template <typename T, typename S> inline void print(const pair<T, S>& p)
    {cout << p.first << " " << p.second << '\n';}
template <typename T> inline void print(const T& x) {cout << x << '\n';}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v)
    {for (auto&& p : v) print(p);}
template <typename T, typename S> inline void print(const map<T, S>& m)
    {for (auto&& p : m) print(p);}
template <int V> inline void print(const static_modint<V> v) {print(v.val());}
inline void print(const modint v) {print(v.val());}
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare; if ((compare = a > b)) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare; if ((compare = a < b)) a = b; return compare;}
// デバッグ用関数
template <typename T> void dprint(const vector<T> &v) {
    rep(i, v.size()) {cout << "[" << i << "]: "; print(v[i]); cout << flush;}
}
template <typename T> void dprint(const vector<vector<T>> &v) {
    rep(i, v.size()) rep(j, v[i].size()) {cout << "[" << i << "][" << j << "]: "; print(v[i][j]); cout << flush;}
}
template<typename T> void dprint(const T v[], const int size) {
    rep(i, size) {cout << "[" << i << "]: "; print(v[i]); cout << flush;}
}
template <typename T> void dprint(const T v[], const int W, const int H) {
    rep(i, W) rep(j, H) {cout << "[" << i << "][" << j << "]: "; print(v[i][j]); cout << flush;}
}

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = (1LL << 60);
CSI INF = 1000000006;
CSLD EPS = 1e-10;
CSLD PHI = 1.6180339887498948;

using mint = int;
using vm = vector<mint>;
using vvm = vector<vm>;

// clang-format on

#pragma region "Tree"

class Tree {
protected:
    const ll size;
    vvll edges;
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

    void set_depth_impl(const ll v, const ll d) {
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

    void get_preorder_impl(vll &order, const ll v) const {
        order.pb(v);
        repi(i, children[v]) {
            get_preorder_impl(order, i);
        }
    }

    void get_postorder_impl(vll &order, const ll v) const {
        repi(i, children[v]) {
            get_postorder_impl(order, i);
        }
        order.pb(v);
    }

    void get_euler_tour_impl(vll &order, const ll v) const {
        order.pb(v);
        repi(i, children[v]) {
            get_euler_tour_impl(order, i);
            order.pb(v);
        }
    }

    void set_partial_size() {
        set_partial_size_impl(root);
    }

    void set_partial_size_impl(const ll v) {
        partial_size[v] = 1;
        repi(c, children[v]) {
            set_partial_size_impl(c);
            partial_size[v] += partial_size[c];
        }
    }

public:
    Tree(const vvll &_edges, const ll _root = 0) : size(_edges.size()), edges(_edges), root(_root), depth(size, -1),
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
    ll get_depth(const ll v) const { return depth[v]; }
    ll get_height() const { return height; }
    const vvll &get_edges() const { return edges; }
    const vll &get_edges(const ll v) const { return edges[v]; }
    const vll &get_parent() const { return parents; }
    ll get_parent(const ll v) const { return parents[v]; }
    const vvll &get_children() const { return children; }
    const vll &get_children(const ll v) const { return children[v]; }
    const vll &get_partial_size() const { return partial_size; }
    ll get_partial_size(const ll v) const { return partial_size[v]; }

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

#pragma region "WTree"

struct WEdge {
    ll to;
    ll cost;
};
using WGraph = vector<vector<WEdge>>;

class WTree : public Tree {
protected:
    const WGraph &wedges;
    vll wdepth;

private:
    void set_wdepth() {
        set_wdepth_impl(0, 0);
    }

    void set_wdepth_impl(const ll v, const ll c) {
        wdepth[v] = c;
        repi(i, wedges[v]) {
            if (wdepth[i.to] == -1)
                set_wdepth_impl(i.to, c + i.cost);
        }
    }

    static vvll wedges_to_edges(const WGraph &wedges) {
        vvll ans(wedges.size(), vll());
        rep(i, wedges.size()) repi(j, wedges[i]) ans[i].pb(j.to);
        return ans;
    }

public:
    WTree(const WGraph &_wedges, const ll _root = 0)
        : Tree(wedges_to_edges(_wedges), _root), wedges(_wedges), wdepth(size, -1) {
        set_wdepth();
    }

    const vll &get_wdepth() const { return wdepth; }
    ll get_wdepth(const ll v) const { return wdepth[v]; }
    const WGraph &get_wedges() const { return wedges; }
    const vector<WEdge> &get_wedges(const ll v) const { return wedges[v]; }
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
    LCADoubling(const vvll &_edges, const ll _root = 0) : Tree(_edges, _root) {
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

    ll get_dist(const ll v1, const ll v2) const {
        auto l = get_lca(v1, v2);
        return depth[v1] + depth[v2] - 2 * depth[l];
    }
};

#pragma endregion

ll e() { return 0; }
ll add(ll a, ll b) { return a + b; }

int main() {
    LL(N);
    VVLL(uvw, N - 1, 3);
    repi(i, uvw) {
        i[0]--;
        i[1]--;
    }
    LL(Q);

    WGraph wedges(N);
    repi(i, uvw) {
        wedges[i[0]].pb({i[1], i[2]});
        wedges[i[1]].pb({i[0], i[2]});
    }

    WTree tree(wedges);
    LCADoubling doubling(tree.get_edges());

    auto order = tree.get_postorder();

    vll edge_to_order(N);
    rep(i, N) edge_to_order[order[i]] = i;

    // 帰りがけ順に重さを格納
    vll wdepth_v(N);
    rep(i, N) wdepth_v[edge_to_order[i]] = tree.get_wdepth(i);

    lazy_segtree<ll, add, e, ll, add, add, e> wdepth(wdepth_v);

    rep(q, Q) {
        if (in_int() == 1) {
            LL(i, w);
            i--;
            auto u = uvw[i][0], v = uvw[i][1];
            auto dif = w - uvw[i][2];
            uvw[i][2] = w;

            if (tree.get_depth(u) > tree.get_depth(v)) swap(u, v);
            // v の部分木に含まれる頂点の深さを変更
            auto ind = edge_to_order[v];
            wdepth.apply(ind - tree.get_partial_size(v) + 1, ind + 1, dif);

        } else {
            LL(u, v);
            u--;
            v--;
            auto l = doubling.get_lca(u, v);
            print(wdepth.get(edge_to_order[u]) + wdepth.get(edge_to_order[v]) - 2 * wdepth.get(edge_to_order[l]));
        }
    }

    return 0;
}
