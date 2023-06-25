#include "../tpl/template.cpp"

#pragma region "BFS"

// 各頂点への距離を求める
vll bfs(const vvll &edges, ll v) {
    vll ans(edges.size(), -1);
    ans[v] = 0;

    queue<ll> q;
    repi(i, edges[v]) {
        if (ans[i] == -1) {
            q.push(i);
            ans[i] = ans[v] + 1;
        }
    }

    while (true) {
        repi(i, edges[v]) {
            if (ans[i] == -1) {
                q.push(i);
                ans[i] = ans[v] + 1;
            }
        }
        if (q.empty()) break;
        v = q.front();
        q.pop();
    }

    return ans;
}

#pragma endregion

#pragma region "ダイクストラ法"

class Dijkstra {
    const vvpll &edges;
    ll start;
    vll dist;
    vll prev; // 直前の頂点を記録する配列

    void set_dist() {
        // (現時点での最短距離, 頂点)
        priority_queue<pll, vector<pll>, greater<pll>> q;
        q.emplace(dist[start] = 0, start);

        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            if (dist[p.second] < p.first) continue;

            repi(i, edges[p.second]) {
                ll d = dist[p.second] + i.second;
                if (d < dist[i.first]) {
                    prev[i.first] = p.second;
                    q.emplace(dist[i.first] = d, i.first);
                }
            }
        }
    }

public:
    Dijkstra(const vvpll &_edges, ll _start) : edges(_edges), start(_start), dist(edges.size(), LINF), prev(edges.size(), -1) {
        set_dist();
    }

    ll get_dist(ll v) const { return dist[v]; }
    vll &get_dist() { return dist; }

    // 最短経路を取得
    vll get_path(ll v) const {
        vll ans;
        for (ll i = v; i >= 0; i = prev[i]) ans.pb(i);
        reverse(all(ans));
        return ans;
    }
};

#pragma endregion

#pragma region "01-BFS"

class BFS01 {
    vll dist;

public:
    BFS01(vvll &zero_edges, vvll &one_edges, ll startIndex) : dist(zero_edges.size(), LINF) {
        dist[startIndex] = 0;

        deque<ll> q;
        q.emplace_back(startIndex);

        while (!q.empty()) {
            auto v = q.front();
            q.pop_front();

            repi(i, zero_edges[v]) {
                if (dist[v] < dist[i]) {
                    dist[i] = dist[v];
                    q.push_front(i);
                }
            }
            repi(i, one_edges[v]) {
                if (dist[v] + 1 < dist[i]) {
                    dist[i] = dist[v] + 1;
                    q.push_back(i);
                }
            }
        }
    }

    // 最短距離を取得
    ll get_distance(const ll v) const {
        return dist[v];
    }
};

#pragma endregion

#pragma region "強連結成分分解"

class SCC {
    const ll size;
    const vvll &graph;
    vvll r_graph;
    ll component_size;
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
    SCC(const vvll &_graph) : size(_graph.size()), graph(_graph), r_graph(size, vll()),
                              component(size, -1), used(size, false) {
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
    bool is_same(const ll u, const ll v) const { return component[u] == component[v]; }

    // 各強連結成分を取得する
    vvll get_components() const {
        auto ans = vvll();
        rep(i, component_size) ans.pb(vll());
        rep(v, size) ans[component[v]].pb(v);
        return ans;
    }

    // 強連結成分を1つのノードに潰したグラフを再構築する
    vvll rebuild() const {
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
    const ll size;
    vll parents;

public:
    UnionFind(const ll _size) : size(_size), parents(size, -1) {}

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
        if (is_connected(v1, v2))
            return;
        parents[root(v2)] = root(v1);
    }
};

#pragma endregion

#pragma region "閉路検出"

bool is_dag_impl(const vvll &edges, const ll v, vc &status) {
    status[v] = 1;
    repi(i, edges[v]) {
        if (status[i] == 1)
            return false;
        else if (status[i] == 0 && !is_dag_impl(edges, i, status))
            return false;
    }
    status[v] = 2;
    return true;
}

bool is_dag(const vvll &edges) {
    auto status = vc(edges.size(), (char)0);
    rep(i, edges.size()) {
        if (status[i] == 0 && !is_dag_impl(edges, i, status))
            return false;
    }
    return true;
}

#pragma endregion

#pragma region "トポロジカルソート"

vll topological_sort(const vvll &edges) {
    vll ans;
    vll in_deg(edges.size(), 0);

    // 入次数をカウント
    repi(i, edges) repi(j, i) in_deg[j]++;

    queue<ll> q;
    rep(i, in_deg.size()) {
        if (in_deg[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        repi(i, edges[v]) {
            if (--in_deg[i] == 0)
                q.push(i);
        }
        ans.pb(v);
    }

    return ans;
}

#pragma endregion

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

#pragma region "全方位木DP"

template <class T>
class ReRooting : Tree {
    // index[i][j]: edges[i][j] からみて，i が何番目の頂点か
    vvll index;

    vector<vector<T>> dp;
    vector<T> res;

    const function<T()> e;
    const function<T(T, T)> op;
    const function<T(T, ll)> mapping;

public:
    // 単方向の辺を受け取る
    ReRooting(const vvll &_edges, function<T()> _e, function<T(T, T)> _op, function<T(T, ll)> _mapping)
        : Tree(_edges, 0), index(size, vll()), res(size), e(_e), op(_op), mapping(_mapping) {

        // dict[i][j]: i からみて，j が何番目の頂点か
        vector<um<ll, ll>> dict(size, um<ll, ll>());
        rep(i, size) rep(j, edges[i].size()) dict[i][edges[i][j]] = j;
        rep(i, size) repi(j, edges[i]) index[i].pb(dict[j][i]);
        rep(i, size) dp.pb(vector<T>(edges[i].size(), e()));

        if (size == 1) {
            res[0] = mapping(e(), 0);
        } else {
            init();
        }
    }

    T get(const ll node) { return res[node]; }

private:
    void init() {
        auto order = get_preorder();

        // from leaf
        for (ll i = order.size() - 1; i >= 1; i--) {
            auto node = order[i];
            auto parent = parents[node];

            T accum = e();
            ll parent_i = -1;
            rep(j, edges[node].size()) {
                if (edges[node][j] == parent) {
                    parent_i = j;
                    continue;
                }
                accum = op(accum, dp[node][j]);
            }
            dp[parent][index[node][parent_i]] = mapping(accum, node);
        }

        // to leaf
        rep(i, order.size()) {
            auto node = order[i];

            T accum = e();
            vector<T> accums_rev(edges[node].size());
            accums_rev[accums_rev.size() - 1] = e();

            for (ll j = accums_rev.size() - 1; j >= 1; j--)
                accums_rev[j - 1] = op(dp[node][j], accums_rev[j]);

            rep(j, accums_rev.size()) {
                dp[edges[node][j]][index[node][j]] =
                    mapping(op(accum, accums_rev[j]), node);
                accum = op(accum, dp[node][j]);
            }
            res[node] = mapping(accum, node);
        }
    }
};

#pragma endregion

#pragma region "WTree"

// Tree の edges は実体に変更する

struct WEdge {
    ll to;
    ll cost;

    WEdge() {}
    WEdge(ll _to, ll _cost) : to(_to), cost(_cost) {}
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
