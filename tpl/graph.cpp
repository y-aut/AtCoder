#include <bits/stdc++.h>
using namespace std;

// clang-format off
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

#define pb push_back
#define CSI constexpr static int
#define CSLL constexpr static ll
#define CSLD constexpr static ld

#define reps(i, a, n) for (ll i = (a); i < (ll)(n); i++)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i,n) for (ll i = n - 1; i >= 0; i--)
#define rrepd(i,n) for (ll i = n; i >= 1; i--)

CSLL LINF = (1LL << 60);

// --------------------- ここからコピー --------------------
#pragma region "ダイクストラ法"

struct Dijkstra_Edge { ll to; ll cost; };
using Dijkstra_Graph = vector<vector<Dijkstra_Edge>>;

class Dijkstra
{
    ll size;
    vll distances;
    // 直前の頂点を記録する配列
    vll previous;

public:
    Dijkstra(const Dijkstra_Graph& graph, const ll startIndex) {
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

#pragma region "強連結成分分解"

class SCC
{
    ll size, component_size;
    vvll graph, r_graph;
    vll order, component;
    vector<bool> used;

    void dfs(const ll v) {
        used[v] = true;
        for (auto nv : graph[v]) {
            if (!used[nv]) dfs(nv);
        }
        order.pb(v);
    }

    void rdfs(const ll v, const ll k) {
        component[v] = k;
        for (auto nv : r_graph[v]) {
            if (component[nv] < 0) rdfs(nv, k);
        }
    }

public:
    SCC(const vvll &_graph) {
        size = _graph.size();
        graph = _graph;
        r_graph.resize(size);
        component.assign(size, -1);
        used.resize(size);
        rep(v, size) {
            for (auto nv : graph[v]) r_graph[nv].pb(v);
        }
        rep(v, size) if (!used[v]) dfs(v);

        component_size = 0;
        repd(i, order.size()) {
            if (component[order[i]] == -1) rdfs(order[i], component_size++);
        }
    }

    // 頂点(u, v)が同じ強連結成分に含まれるか
    bool is_same(const ll u, const ll v) { return component[u] == component[v]; }

    // 各強連結成分を取得する
    vvll get_components() {
        auto ans = vvll();
        rep(i, component_size) ans.pb(vll());
        rep(v, size) ans[component[v]].pb(v);
        return ans;
    }

    // 強連結成分を1つのノードに潰したグラフを再構築する
    vvll rebuild() {
        ll N = *max_element(component.begin(), component.end()) + 1;
        vvll ans(N);
        set<pll> connected;
        rep(v, N) {
            for (auto nv : graph[v]) {
                if (component[v] != component[nv] && !connected.count(pair(v, nv))) {
                    connected.insert(pair(v, nv));
                    ans[component[v]].pb(component[nv]);
                }
            }
        }
        return ans;
    }
};

#pragma endregion

#pragma region "Union-Find"

class UnionFind
{
    ll size;
    vll parents;

    ll root(const ll v) {
        if (parents[v] == -1) {
            return v;
        }
        else {
            return parents[v] = root(parents[v]);
        }
    }

public:
    UnionFind(const ll _size) {
        size = _size;
        parents = vll(size, -1);
    }

    bool is_connected(const ll v1, const ll v2) {
        return root(v1) == root(v2);
    }

    void merge(const ll v1, const ll v2) {
        parents[root(v1)] = v2;
    }
};

#pragma endregion
