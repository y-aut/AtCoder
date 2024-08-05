#include "lib/graph/tree/tree.cpp"

class WTree : public Tree {
protected:
    const vvpll &wedges;
    vll wdepth;

private:
    void set_wdepth() {
        set_wdepth_impl(root, 0);
    }

    void set_wdepth_impl(ll v, ll c) {
        wdepth[v] = c;
        repi(i, wedges[v]) {
            if (wdepth[i.first] == -1)
                set_wdepth_impl(i.first, c + i.second);
        }
    }

    static vvll wedges_to_edges(const vvpll &wedges) {
        vvll ans(wedges.size(), vll());
        rep(i, wedges.size()) repi(j, wedges[i]) ans[i].pb(j.first);
        return ans;
    }

public:
    WTree(const vvpll &_wedges, ll _root = 0)
        : Tree(wedges_to_edges(_wedges), _root), wedges(_wedges), wdepth(size, -1) {
        set_wdepth();
    }

    const vll &get_wdepth() const { return wdepth; }
    ll get_wdepth(ll v) const { return wdepth[v]; }
    const vvpll &get_wedges() const { return wedges; }
    const vpll &get_wedges(ll v) const { return wedges[v]; }

    // 木の直径と，それを実現する頂点の組を返す
    ll get_wdiameter(pll &nodes) const {
        nodes.first = max_element(all(wdepth)) - wdepth.begin();
        WTree tree(wedges, nodes.first);
        nodes.second = max_element(all(tree.wdepth)) - tree.wdepth.begin();
        return tree.wdepth[nodes.second];
    }
};
