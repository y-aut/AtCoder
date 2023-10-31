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
#define contains(a, v) (a.find(v) != a.end())
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
    {vvll res = vvll(N, vll());
    rep(i, height) {ll a = in_ll()-1; ll b = in_ll()-1; res[a].pb(b); if (bidir) res[b].pb(a);} return res;}
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

// sgn(cnt - K) を返す
ll get_cnt(ll N, ll P, ll K, vvll &A, ll X) {
    auto graph = WGraph(N, vector<WEdge>());
    rep(i, N) rep(j, N) {
        if (i == j)
            continue;
        graph[i].pb({j, A[i][j] == -1 ? X : A[i][j]});
    }
    ll cnt = 0;
    rep(i, N - 1) {
        auto dij = Dijkstra(graph, i);
        reps(j, i + 1, N) {
            if (dij.get_distance(j) <= P)
                cnt++;
        }
        if (cnt > K)
            return 1;
    }
    if (cnt == K)
        return 0;
    else
        return -1;
}

ll low_b(ll N, ll P, ll K, vvll &A, ll xmin, ll xmax) {
    while (true) {
        // cnt(xmin) == 1, cnt(xmax) <= 0
        if (xmin + 1 == xmax) {
            return xmax;
        }
        ll xmid = (xmin + xmax) / 2;
        auto cnt = get_cnt(N, P, K, A, xmid);
        if (cnt <= 0) {
            xmax = xmid;
        } else {
            xmin = xmid;
        }
    }
}

int main() {
    INLL(N, P, K);
    auto A = in_vvll(N, N);

    ll xmin = 1;
    ll xmax = LINF;

    ll k_min_x = -1;
    ll k_max_x = -1;

    auto cnt = get_cnt(N, P, K, A, xmax);
    if (cnt == 0) {
        print("Infinity");
        return 0;
    } else if (cnt > 0) {
        print(0);
        return 0;
    }

    cnt = get_cnt(N, P, K, A, xmin);
    if (cnt == 0) {
        k_min_x = xmin;
    } else if (cnt < 0) {
        print(0);
        return 0;
    }

    if (k_min_x == -1) {
        k_min_x = low_b(N, P, K, A, xmin, xmax);
    }
    k_max_x = low_b(N, P, K - 1, A, k_min_x - 1, xmax);

    print(k_max_x - k_min_x);

    return 0;
}