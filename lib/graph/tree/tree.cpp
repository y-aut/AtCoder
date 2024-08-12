// !hidden
#include "template.hpp"
// !endhidden

class Tree {
protected:
    const ll size;
    vvll edges;
    const ll root;
    vll depth;
    ll height; // max(depth) + 1
    vll parents;
    vvll children;
    vll partial_size; // 部分木のノード数

private:
    void set_depth() {
        set_depth_impl(root, 0);
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
        parents[root] = root;
        rep(i, size) repi(j, edges[i]) {
            if (depth[i] < depth[j]) {
                parents[j] = i;
            } else {
                children[j].pb(i);
            }
        }
    }

    void get_preorder_impl(vll &order, ll v) const {
        order.pb(v);
        repi(i, children[v]) {
            get_preorder_impl(order, i);
        }
    }

    void get_postorder_impl(vll &order, ll v) const {
        repi(i, children[v]) {
            get_postorder_impl(order, i);
        }
        order.pb(v);
    }

    void get_euler_tour_impl(vll &order, ll v) const {
        order.pb(v);
        repi(i, children[v]) {
            get_euler_tour_impl(order, i);
            order.pb(v);
        }
    }

    void set_partial_size() {
        set_partial_size_impl(root);
    }

    void set_partial_size_impl(ll v) {
        partial_size[v] = 1;
        repi(c, children[v]) {
            set_partial_size_impl(c);
            partial_size[v] += partial_size[c];
        }
    }

    static vvll get_edges_from_parents(const vll &parents) {
        vvll edges(parents.size() + 1);
        rep(i, parents.size()) {
            edges[i + 1].pb(parents[i]);
            edges[parents[i]].pb(i + 1);
        }
        return edges;
    }

public:
    Tree(const vvll &_edges, ll _root = 0) : size(_edges.size()), edges(_edges), root(_root), depth(size, -1),
                                             parents(size, -1), children(size, vll()), partial_size(size, 0) {
        if (size == 0) {
            throw "The tree size is 0.";
        }
        set_depth();
        set_parents_and_children();
        set_partial_size();
    }

    // 頂点 0 を根ノードとして，1, 2, ..., N-1 の親ノードの情報から木を作成
    Tree(const vll &_parents) : Tree(get_edges_from_parents(_parents)) {}

    ll get_size() const { return size; }
    ll get_root() const { return root; }
    const vll &get_depth() const { return depth; }
    ll get_depth(ll v) const { return depth[v]; }
    ll get_height() const { return height; }
    const vvll &get_edges() const { return edges; }
    const vll &get_edges(ll v) const { return edges[v]; }
    const vll &get_parent() const { return parents; }
    ll get_parent(ll v) const { return parents[v]; }
    const vvll &get_children() const { return children; }
    const vll &get_children(ll v) const { return children[v]; }
    const vll &get_partial_size() const { return partial_size; }
    ll get_partial_size(ll v) const { return partial_size[v]; }

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

    // 重心の一つを取得する
    ll get_centroid() const {
        ll v = get_root();
        while (true) {
            ll max_size = 0, max_c = 0;
            repi(c, get_children(v)) {
                if (chmax(max_size, get_partial_size(c))) max_c = c;
            }
            if (max_size <= get_size() / 2) return v;
            v = max_c;
        }
    }

    // 木の直径と，それを実現する頂点の組を返す
    ll get_diameter(pll &nodes) const {
        nodes.first = max_element(all(depth)) - depth.begin();
        Tree tree(edges, nodes.first);
        nodes.second = max_element(all(tree.depth)) - tree.depth.begin();
        return tree.depth[nodes.second];
    }
};
