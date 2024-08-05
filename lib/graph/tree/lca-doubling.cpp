#include "lib/graph/tree/tree.cpp"

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
    LCADoubling(const vvll &_edges, ll _root = 0) : Tree(_edges, _root) {
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

    ll get_dist(ll v1, ll v2) const {
        auto l = get_lca(v1, v2);
        return depth[v1] + depth[v2] - 2 * depth[l];
    }
};
