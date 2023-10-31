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
#define YESNO(bool) if(bool){cout<<"YES"<<'\n';}else{cout<<"NO"<<'\n';}
#define yesno(bool) if(bool){cout<<"yes"<<'\n';}else{cout<<"no"<<'\n';}
#define YesNo(bool) if(bool){cout<<"Yes"<<'\n';}else{cout<<"No"<<'\n';}
#define CSI constexpr static int
#define CSLL constexpr static ll
#define CSLD constexpr static ld

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); i++)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
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
inline vi in_vi(int length) {vi res = vi(); rep(i, length) res.pb(in_int()); return res;}
inline vll in_vll(int length) {vll res = vll(); rep(i, length) res.pb(in_ll()); return res;}
inline vs in_vs(int height) {vs res = vs(); rep(i, height) res.pb(in_str()); return res;}
inline vvi in_vvi(int width, int height)
    {vvi res = vvi(); rep(i, height) {vi tmp = vi(); rep(j, width) tmp.pb(in_int()); res.pb(tmp);} return res;}
inline vvll in_vvll(int width, int height)
    {vvll res = vvll(); rep(i, height) {vll tmp = vll(); rep(j, width) tmp.pb(in_ll()); res.pb(tmp);} return res;}
inline vpii in_vpii(int height)
    {vpii res = vpii(); rep(i, height) {pii tmp; tmp.first = in_int(); tmp.second = in_int(); res.pb(tmp);} return res;}
inline vpll in_vpll(int height)
    {vpll res = vpll(); rep(i, height) {pll tmp; tmp.first = in_ll(); tmp.second = in_ll(); res.pb(tmp);} return res;}
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
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare; if (compare = a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare; if (compare = a < b) a = b; return compare;}

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = (1LL << 60);
CSI INF = 1000000006;
CSLD EPS = 1e-10;
CSLD PHI = 1.6180339887498948;

// clang-format on

#pragma region "Union-Find"

class UnionFind {
    ll size;
    vll parents;

public:
    UnionFind(const ll _size) {
        size = _size;
        parents.resize(size, -1);
    }

    ll root(const ll v) {
        if (parents[v] == -1) {
            return v;
        } else {
            return parents[v] = root(parents[v]);
        }
    }

    bool is_connected(const ll v1, const ll v2) {
        return root(v1) == root(v2);
    }

    void merge(const ll v1, const ll v2) {
        parents[root(v2)] = v1;
    }
};

#pragma endregion

ll op(ll a, ll b) { return 0; }
ll e() { return 0; }
ll add(ll a, ll b) { return a + b; }

lazy_segtree<ll, op, e, ll, add, add, e> etree;
lazy_segtree<ll, op, e, ll, add, add, e> otree;

inline ll get(ll i) {
    if (i % 2 == 0)
        return etree.get(i / 2);
    else
        return otree.get(i / 2);
}

int main() {
    auto N = in_ll();
    auto Q = in_ll();
    auto TXYV = in_vvll(4, Q);

    etree = lazy_segtree<ll, op, e, ll, add, add, e>((N + 1) / 2);
    otree = lazy_segtree<ll, op, e, ll, add, add, e>(N / 2);

    auto tree = UnionFind(N);

    vll group_b;
    rep(i, N) {
        group_b.pb(i + 1);
    }

    repi(q, TXYV) {
        q[1]--;
        q[2]--;
        if (q[0] == 0) {
            if (group_b[q[2]] == -1)
                continue;
            auto add = q[3] - get(q[1]) - get(q[2]);
            if (add != 0) {
                // [q[2], group_b[q[2]]) を +/- add する
                if (q[2] % 2 == 0) {
                    etree.apply(q[2] / 2, (group_b[q[2]] + 1) / 2, add);
                    otree.apply(q[2] / 2, group_b[q[2]] / 2, -add);
                } else {
                    etree.apply((q[2] + 1) / 2, (group_b[q[2]] + 1) / 2, -add);
                    otree.apply(q[2] / 2, group_b[q[2]] / 2, add);
                }
            }
            group_b[tree.root(q[1])] = group_b[q[2]];
            group_b[q[2]] = -1;
            tree.merge(q[1], q[2]);
        } else {
            if (!tree.is_connected(q[1], q[2])) {
                print("Ambiguous");
            } else {
                ll add = q[3] - get(q[1]);
                if ((q[1] - q[2]) % 2 != 0)
                    add *= -1;
                print(get(q[2]) + add);
            }
        }
    }

    return 0;
}