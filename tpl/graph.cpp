#include "./template.cpp"

// --------------------- ここからコピー --------------------
#pragma region "ダイクストラ法"

struct DEdge {
    ll to;
    ll cost;
};
using DGraph = vector<vector<DEdge>>;

class Dijkstra {
    ll size;
    vll distances;
    // 直前の頂点を記録する配列
    vll previous;

public:
    Dijkstra(const DGraph &graph, const ll startIndex) {
        distances.resize(graph.size(), LINF);
        previous.resize(graph.size(), -1);

        // 「現時点での最短距離, 頂点」の順に取り出す priority_queue
        priority_queue<pll, vector<pll>, greater<pll>> q;
        q.emplace((distances[startIndex] = 0), startIndex);

        while (!q.empty()) {
            const auto distance = q.top().first;
            const auto from = q.top().second;
            q.pop();

            // 最短距離でなければ処理しない
            if (distances[from] < distance) {
                continue;
            }

            // 現在の頂点からの各辺について
            for (const auto &edge : graph[from]) {
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

class SCC {
    ll size, component_size;
    vvll graph, r_graph;
    vll order, component;
    vector<bool> used;

    void dfs(const ll v) {
        used[v] = true;
        for (auto nv : graph[v]) {
            if (!used[nv])
                dfs(nv);
        }
        order.pb(v);
    }

    void rdfs(const ll v, const ll k) {
        component[v] = k;
        for (auto nv : r_graph[v]) {
            if (component[nv] < 0)
                rdfs(nv, k);
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
            for (auto nv : graph[v])
                r_graph[nv].pb(v);
        }
        rep(v, size) if (!used[v]) dfs(v);

        component_size = 0;
        repd(i, order.size()) {
            if (component[order[i]] == -1)
                rdfs(order[i], component_size++);
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

class UnionFind {
    ll size;
    vll parents;

    ll root(const ll v) {
        if (parents[v] == -1) {
            return v;
        } else {
            return parents[v] = root(parents[v]);
        }
    }

public:
    UnionFind(const ll _size) {
        size = _size;
        parents.resize(size, -1);
    }

    bool is_connected(const ll v1, const ll v2) {
        return root(v1) == root(v2);
    }

    void merge(const ll v1, const ll v2) {
        parents[root(v1)] = v2;
    }
};

#pragma endregion

#pragma region "Tree"

class Tree {
protected:
    ll size;
    ll root;
    vll depth;
    ll height; // max(depth) + 1
    vvll edges;
    vll parents;
    vvll children;

private:
    void set_depth() {
        depth.resize(size, -1);
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
        parents.resize(size);
        parents[root] = root;
        rep(i, size) children.pb(vll());
        rep(i, size) repi(j, edges[i]) {
            if (depth[i] < depth[j]) {
                parents[j] = i;
            } else {
                children[j].pb(i);
            }
        }
    }

    void get_preorder_impl(vll &order, ll v) {
        order.pb(v);
        repi(i, children[v]) {
            get_preorder_impl(order, i);
        }
    }

    void get_postorder_impl(vll &order, ll v) {
        repi(i, children[v]) {
            get_postorder_impl(order, i);
        }
        order.pb(v);
    }

    void get_euler_tour_impl(vll &order, ll v) {
        order.pb(v);
        repi(i, children[v]) {
            get_euler_tour_impl(order, i);
            order.pb(v);
        }
    }

public:
    Tree(ll _size, vvll &_edges, ll _root = 0) {
        size = _size;
        edges = _edges;
        root = _root;
        set_depth();
        set_parents_and_children();
    }

    ll get_size() { return size; }
    ll get_root() { return root; }
    ll get_depth(ll v) { return depth[v]; }
    ll get_height() { return height; }
    vll get_edges(ll v) { return edges[v]; }
    ll get_parent(ll v) { return parents[v]; }
    vll get_children(ll v) { return children[v]; }

    // 頂点の行きがけ順を取得する
    vll get_preorder() {
        auto ans = vll();
        get_preorder_impl(ans, root);
        return ans;
    }

    // 頂点の帰りがけ順を取得する
    vll get_postorder() {
        auto ans = vll();
        get_postorder_impl(ans, root);
        return ans;
    }

    // オイラーツアーを取得する
    vll get_euler_tour() {
        auto ans = vll();
        get_euler_tour_impl(ans, root);
        return ans;
    }
};

#pragma endregion

#pragma region "LCADoubling"

// 木の LCA をダブリングを用いて計算する
class LCADoubling : Tree {
    // doubling[i][j]: j から 2^i 個頂点を遡った祖先
    vvll doubling;

    // 最上位ビットの下から数えた位置を取得
    int msb_pos(ull x) {
        return x == 0 ? -1 : (sizeof(ull)) * 8 - __builtin_clzll(x) - 1;
    }

    void set_doubling() {
        int max_i = msb_pos(height) + 1;
        rep(i, max_i) doubling.pb(vll(size));
        rep(i, size) doubling[0][i] = parents[i];
        rep(i, max_i - 1) {
            rep(j, size) {
                doubling[i + 1][j] = doubling[i][doubling[i][j]];
            }
        }
    }

public:
    LCADoubling(ll _size, vvll &_edges, ll _root = 0) : Tree(_size, _edges, _root) {
        set_doubling();
    }

    // v の d 個上の祖先を取得する
    ll level_ancestor(ll v, ll d) {
        repd(i, doubling.size()) {
            if (1 << i <= d) {
                d -= 1 << i;
                v = doubling[i][v];
            }
        }
        return v;
    }

    ll get_lca(ll v1, ll v2) {
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
};

#pragma endregion
