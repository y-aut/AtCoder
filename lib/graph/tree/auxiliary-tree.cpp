#include "lib/graph/tree/lca-doubling.cpp"

class AuxiliaryTree : public LCADoubling {
private:
    // 各節点に対して，行きがけ順での番号を格納したもの
    vll preorder_map;
    // 各節点に対して，Euler Tour における最初の出現位置，最後の出現位置のペア
    vpll et_map;

    void set_maps() {
        auto preorder = get_preorder();
        preorder_map.resize(size);
        rep(i, preorder.size()) preorder_map[preorder[i]] = i;
        auto et = get_euler_tour();
        et_map.resize(size, {-1, -1});
        rep(i, et.size()) {
            if (et_map[et[i]].first == -1) et_map[et[i]].first = i;
            et_map[et[i]].second = i;
        }
    }

public:
    AuxiliaryTree(const vvll &_edges, ll _root = 0) : LCADoubling(_edges, _root) {
        set_maps();
    }

    /// @brief Auxiliary Tree を取得する
    /// @param nodes 頂点集合．Auxiliary Tree に登場する頂点を行きがけ順に並べたものに更新される
    /// @return Auxiliary Tree の各頂点の親
    umll get_auxiliary_tree(vll &nodes) const {
        sort(all(nodes), [&](ll a, ll b) { return preorder_map.at(a) < preorder_map.at(b); });
        ll m = nodes.size();
        rep(i, m - 1) nodes.pb(get_lca(nodes[i], nodes[i + 1]));
        sort(all(nodes), [&](ll a, ll b) { return preorder_map.at(a) < preorder_map.at(b); });
        nodes.erase(unique(all(nodes)), nodes.end());
        umll ans;
        stack<ll> s;
        s.push(nodes[0]);
        rep(i, 1, nodes.size()) {
            while (et_map[s.top()].second < et_map[nodes[i]].first) s.pop();
            ans[nodes[i]] = s.top();
            s.push(nodes[i]);
        }
        return ans;
    }
};
