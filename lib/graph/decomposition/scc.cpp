// !hidden
#include "template.hpp"
// !endhidden

class SCC {
    const ll size;
    const vvll &graph;
    vvll r_graph;
    ll component_size;
    vll order, component;
    vector<bool> used;

    void dfs(ll v) {
        used[v] = true;
        for (auto nv : graph[v]) {
            if (!used[nv])
                dfs(nv);
        }
        order.pb(v);
    }

    void rdfs(ll v, ll k) {
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
    bool is_same(ll u, ll v) const { return component[u] == component[v]; }

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
