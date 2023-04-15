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
// unordered set
using usi = unordered_set<int>;
using usll = unordered_set<ll>;
using uss = unordered_set<string>;

/* define short */
#define pb push_back
#define mp make_pair
#define um unordered_map
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
#define repd(i,n) for (ll i = n - 1; i >= 0; i--)
#define rrepd(i,n) for (ll i = n; i >= 1; i--)

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

#pragma region "ダイクストラ法"

struct DEdge { ll to; ll cost; };
using DGraph = vector<vector<DEdge>>;

class Dijkstra
{
    ll size;
    vll distances;
    // 直前の頂点を記録する配列
    vll previous;

public:
    Dijkstra(const DGraph& graph, const ll startIndex) {
        distances = vll(graph.size(), LINF);
        previous = vll(graph.size(), -1);

        // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
        priority_queue<pll, vector<pll>, greater<pll>> q;
        q.emplace((distances[startIndex] = 0), startIndex);

        while (!q.empty()) {
            const auto distance = q.top().first;
            const auto from = q.top().second;
            q.pop();

            // 最短距離でなければ処理しない
            if (distances[from] < distance) { continue; }

            // 現在の頂点からの各辺について
            for (const auto& edge : graph[from]) {
                // to までの新しい距離
                const ll d = (distances[from] + edge.cost);

                // d が現在の記録より小さければ更新
                if (d < distances[edge.to]) {
                    previous[edge.to] = from;
                    q.emplace((distances[edge.to] = d), edge.to);
                }
            }
        }
    }

    // 最短距離を取得
    ll get_distance(const ll v) {
        return distances[v];
    }

    // 最短経路を取得
    vll get_path(const ll v) {
        auto path = vll();
        for (int i = v; i >= 0; i = previous[i]) {
			path.push_back(i);
		}
		reverse(path.begin(), path.end());
        return path;
    }
};

#pragma endregion


int main()
{
    auto N = in_ll();
    auto edge = in_vvll(2, N-1);
    
    auto graph = DGraph();
    rep(i, N) graph.pb(vector<DEdge>());
    for (auto e : edge) {
        graph[e.at(0)-1].pb({ e.at(1)-1, 1 });
        graph[e.at(1)-1].pb({ e.at(0)-1, 1 });
    }

    auto d = Dijkstra(graph, 0);
    auto odd = vll();
    auto even = vll();
    rep(i, N) {
        if (d.get_distance(i) % 2 == 0) {
            even.pb(i+1);
            if (even.size() >= N / 2) {
                break;
            }
        }
        else {
            odd.pb(i+1);
            if (odd.size() >= N / 2) {
                break;
            }
        }
    }

    auto ans = vll();
    if (even.size() == N / 2) {
        print(even);
    }
    else {
        print(odd);
    }

    return 0;
}