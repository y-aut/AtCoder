// !hidden
#include "template.hpp"
// !endhidden

struct CentroidDecomposition {
private:
    const vvll &edges;
    vb dead;

    void set_partial_size(umll &ans, ll root, ll par = -1) const {
        ans[root] = 1;
        repi(i, edges[root]) {
            if (i == par || dead[i]) continue;
            set_partial_size(ans, i, root);
            ans[root] += ans[i];
        }
    }

    ll get_centroid(const umll &partial_size, ll root, ll par = -1) const {
        ll v = root;
        while (true) {
            ll max_size = 0, max_i = 0;
            repi(i, edges[v]) {
                if (i == par || dead[i]) continue;
                if (chmax(max_size, partial_size.at(i))) max_i = i;
            }
            if (max_size <= partial_size.at(root) / 2) return v;
            par = v;
            v = max_i;
        }
        return v;
    }

    ll perform_impl(const function<void(ll root, ll size, const vb &dead, const vll &children, ll par)> f, ll root, ll par = -1) {
        umll partial_size;
        set_partial_size(partial_size, root, par);
        auto centroid = get_centroid(partial_size, root, par);
        dead[centroid] = true;
        vll children;
        repi(i, edges[centroid]) if (i != par && !dead[i]) children.pb(perform_impl(f, i, centroid));
        dead[centroid] = false;
        f(centroid, partial_size[root], dead, children, par);
        return centroid;
    }

public:
    CentroidDecomposition(const vvll &_edges) : edges(_edges), dead(_edges.size()) {}

    // root を根とする size の部分木に対して，根をまたぐ処理 f を再帰的に適用する．dead にある頂点は存在しないものとして扱う必要がある
    // children は，子部分木を処理したときの root の値．par はこの部分木が結合される先の頂点（なければ -1）
    // 部分木のサイズを N として f の計算量が O(N) のとき，全体の計算量は O(N logN) となる
    void perform(const function<void(ll root, ll size, const vb &dead, const vll &children, ll par)> f) {
        perform_impl(f, 0);
    }
};
