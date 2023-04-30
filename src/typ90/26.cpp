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
using vc = vector<char>;
using vs = vector<string>;
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
#define INVAR(type, ...) type __VA_ARGS__; set_vars(__VA_ARGS__)
#define ININT(...) INVAR(int, __VA_ARGS__)
#define INLL(...) INVAR(ll, __VA_ARGS__)

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
inline vi in_vi(int length) {vi res; rep(i, length) res.pb(in_int()); return res;}
inline vll in_vll(int length) {vll res; rep(i, length) res.pb(in_ll()); return res;}
inline vc in_vc(int length) {vc res; rep(i, length) res.pb(in_char()); return res;}
inline vs in_vs(int height) {vs res; rep(i, height) res.pb(in_str()); return res;}
inline vvi in_vvi(int width, int height)
    {vvi res; rep(i, height) {vi tmp; rep(j, width) tmp.pb(in_int()); res.pb(tmp);} return res;}
inline vvll in_vvll(int width, int height)
    {vvll res; rep(i, height) {vll tmp; rep(j, width) tmp.pb(in_ll()); res.pb(tmp);} return res;}
inline vpii in_vpii(int height)
    {vpii res; rep(i, height) {pii tmp; tmp.first = in_int(); tmp.second = in_int(); res.pb(tmp);} return res;}
inline vpll in_vpll(int height)
    {vpll res; rep(i, height) {pll tmp; tmp.first = in_ll(); tmp.second = in_ll(); res.pb(tmp);} return res;}
template <bool bidir> inline vvll in_edges(int N, int height)
    {vvll res(N, vll());
    rep(i, height) {ll a = in_ll()-1; ll b = in_ll()-1; res[a].pb(b); if (bidir) res[b].pb(a);} return res;}
template <bool bidir> inline vector<usll> in_edges_us(int N, int height)
    {vector<usll> res(N, usll());
    rep(i, height) {ll a = in_ll()-1; ll b = in_ll()-1; res[a].insert(b); if (bidir) res[b].insert(a);} return res;}
inline void set_vars() {}
template <typename First, typename... Rest> inline void set_vars(First& first, Rest&... rest)
    {cin >> first; set_vars(rest...);}
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
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare; if ((compare = a > b)) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare; if ((compare = a < b)) a = b; return compare;}

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = (1LL << 60);
CSI INF = 1000000006;
CSLD EPS = 1e-10;
CSLD PHI = 1.6180339887498948;

// clang-format on

#pragma region "ダイクストラ法"

struct WEdge {
    ll to;
    ll cost;
};
using WGraph = vector<vector<WEdge>>;

class Dijkstra {
    vll dist;
    // 直前の頂点を記録する配列
    vll prev;

public:
    Dijkstra(const WGraph &graph, const ll startIndex) : dist(graph.size(), LINF), prev(graph.size(), -1) {
        // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
        priority_queue<pll, vector<pll>, greater<pll>> q;
        q.emplace((dist[startIndex] = 0), startIndex);

        while (!q.empty()) {
            const auto distance = q.top().first;
            const auto from = q.top().second;
            q.pop();

            // 最短距離でなければ処理しない
            if (dist[from] < distance) {
                continue;
            }

            // 現在の頂点からの各辺について
            for (const auto &edge : graph[from]) {
                // to までの新しい距離
                ll d = dist[from] + edge.cost;

                // d が現在の記録より小さければ更新
                if (d < dist[edge.to]) {
                    prev[edge.to] = from;
                    q.emplace((dist[edge.to] = d), edge.to);
                }
            }
        }
    }

    // 最短距離を取得
    ll get_distance(const ll v) const {
        return dist[v];
    }

    // 最短経路を取得
    vll get_path(const ll v) const {
        auto path = vll();
        for (int i = v; i >= 0; i = prev[i]) {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

#pragma endregion

int main() {
    auto N = in_ll();
    auto edge = in_vvll(2, N - 1);

    auto graph = WGraph();
    rep(i, N) graph.pb(vector<WEdge>());
    for (auto e : edge) {
        graph[e.at(0) - 1].pb({e.at(1) - 1, 1});
        graph[e.at(1) - 1].pb({e.at(0) - 1, 1});
    }

    auto d = Dijkstra(graph, 0);
    auto odd = vll();
    auto even = vll();
    rep(i, N) {
        if (d.get_distance(i) % 2 == 0) {
            even.pb(i + 1);
            if (even.size() >= N / 2) {
                break;
            }
        } else {
            odd.pb(i + 1);
            if (odd.size() >= N / 2) {
                break;
            }
        }
    }

    auto ans = vll();
    if (even.size() == N / 2) {
        print(even);
    } else {
        print(odd);
    }

    return 0;
}