// !hidden
#include "template.hpp"
// !endhidden

class Bipartite {
    const vvll &edges;

    bool dfs(vll &colors, usll &vs, ll v, ll col) const {
        vs.erase(v);
        colors[v] = col;
        repi(i, edges[v]) {
            vs.erase(i);
            if (colors[i] == col) return false;
            if (colors[i] == 0 && !dfs(colors, vs, i, -col)) {
                return false;
            }
        }
        return true;
    }

public:
    Bipartite(vvll &_edges) : edges(_edges) {}

    bool is_bipartite() const {
        vll colors(edges.size(), 0);
        usll vs;
        rep(i, edges.size()) vs.insert(i);
        while (!vs.empty()) {
            if (!dfs(colors, vs, *vs.begin(), 1)) return false;
        }
        return true;
    }
};
