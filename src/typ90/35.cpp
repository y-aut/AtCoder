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
using vb = vector<bool>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvb = vector<vb>;
using vs = vector<string>;
using vpii = vector<pii>;
using vpll = vector<pll>;
// unordered set
using usi = unordered_set<int>;
using usll = unordered_set<ll>;
using uss = unordered_set<string>;

/* define short */
#define pb push_back
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define CSI constexpr static int
#define CSLL constexpr static ll
#define CSLD constexpr static ld

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); i++)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define rrepd(i, n) for (ll i = n; i >= 1; i--)
#define repi(a, v) for (auto a : (v))

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << endl;

/* func */
inline int in_int() {int x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline double in_double() {double x; cin >> x; return x;}
inline char in_char() {char c; cin >> c; return c;}
inline string in_str() {string x; cin >> x; return x;}
inline vi in_vi(int length) {vi res = vi(); rep(i, length) res.pb(in_int()); return res;}
inline vll in_vll(int length) {vll res = vll(); rep(i, length) res.pb(in_ll()); return res;}
inline vvi in_vvi(int width, int height)
    {vvi res = vvi(); rep(i, height) {vi tmp = vi(); rep(j, width) tmp.pb(in_int()); res.pb(tmp);} return res;}
inline vvll in_vvll(int width, int height)
    {vvll res = vvll(); rep(i, height) {vll tmp = vll(); rep(j, width) tmp.pb(in_ll()); res.pb(tmp);} return res;}
inline int ctoi(char c) {return c - '0';}
template <typename T> inline void print(const vector<T>& v, string s = " ")
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : ""); cout << endl;}
template <typename T, typename S> inline void print(const pair<T, S>& p)
    {cout << p.first << " " << p.second << endl;}
template <typename T> inline void print(const T& x) {cout << x << endl;}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v)
    {for (auto&& p : v) print(p);}
template <typename T, typename S> inline void print(const map<T, S>& m)
    {for (auto&& p : m) print(p);}
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare; if (compare = a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare; if (compare = a < b) a = b; return compare;}

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = (1LL << 60);
CSI INF = 1000000006;
CSLD EPS = 1e-10;

class Tree
{
    ll size;
    ll root;
    vll depth;
    vvll edges;
    vll parents;
    vvll children;
    vpll tour;
    vll tour_v; // tour 内で頂点 v が初めて現れるインデックス

    static pll seg_op(pll l, pll r) {
        if (l.first == -1 || r.first == -1)
            return { l.first + r.first + 1, l.second + r.second + 1 };
        return l.second < r.second ? l : r;
    }
    static pll seg_e() { return { -1, -1 }; }

    segtree<pll, seg_op, seg_e> tour_tree;

    void set_depth() {
        depth.resize(size, -1);
        set_depth_impl(0, 0);
    }

    void set_depth_impl(ll v, ll d) {
        depth[v] = d;
        repi(i, edges[v]) {
            if (depth[i] == -1) set_depth_impl(i, d + 1);
        }
    }

    void set_parents_and_children() {
        parents.resize(size);
        parents[root] = -1;
        rep(i, size) children.pb(vll());
        rep(i, size) repi(j, edges[i]) {
            if (depth[i] < depth[j]) {
                parents[j] = i;
            }
            else {
                children[j].pb(i);
            }
        }
    }

    void set_tour() {
        set_tour_impl(root);
        tour_tree = segtree<pll, seg_op, seg_e>(tour);
        tour_v.resize(size, -1);
        rep(i, tour.size()) {
            if (tour_v[tour[i].first] == -1) {
                tour_v[tour[i].first] = i;
            }
        }
    }

    void set_tour_impl(ll v) {
        tour.pb({ v, depth[v] });
        repi(i, children[v]) {
            set_tour_impl(i);
            tour.pb({ v, depth[v] });
        }
    }

public:
    Tree(ll _size, vvll &_edges, ll _root = 0) {
        size = _size;
        edges = _edges;
        root = _root;
        set_depth();
        set_parents_and_children();
        set_tour();
    }

    ll get_size() { return size; }
    ll get_root() { return root; }
    ll get_depth(ll v) { return depth[v]; }
    ll get_parent(ll v) { return parents[v]; }
    vll get_children(ll v) { return children[v]; }

    ll get_lca(ll v1, ll v2) {
        return tour_tree.prod(min(tour_v[v1], tour_v[v2]), max(tour_v[v1], tour_v[v2]) + 1).first;
    }
};

ll get_edge_index(ll v1, ll v2, ll size) {
    if (v1 < v2) return v1 * size + v2;
    else return v2 * size + v1;
}

int main()
{
    auto N = in_ll();
    auto AB = in_vvll(2, N-1);
    auto Q = in_ll();
    auto querys = vvll();
    rep(i, Q) {
        auto k = in_ll();
        auto v = vll();
        rep(j, k) v.pb(in_ll()-1);
        querys.pb(v);
    }

    auto edges = vvll();
    rep(i, N) edges.pb(vll());
    repi(ab, AB) {
        edges[ab[0]-1].pb(ab[1]-1);
        edges[ab[1]-1].pb(ab[0]-1);
    }
    
    auto tree = Tree(N, edges);
    
    auto edge_set = us<ll>();
    repi(q, querys) {
        rep(i, q.size() - 1) {
            auto lca_d = tree.get_depth(tree.get_lca(q[i], q[i+1]));
            auto v = q[i];
            for (ll j = tree.get_depth(v); j > lca_d; j--) {
                edge_set.insert(get_edge_index(v, tree.get_parent(v), N));
                v = tree.get_parent(v);
            }
            v = q[i+1];
            for (ll j = tree.get_depth(v); j > lca_d; j--) {
                edge_set.insert(get_edge_index(v, tree.get_parent(v), N));
                v = tree.get_parent(v);
            }
        }
        print(edge_set.size());
        edge_set.clear();
    }

    return 0;
}