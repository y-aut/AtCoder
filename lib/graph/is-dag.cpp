// !hidden
#include "template.hpp"
// !endhidden

bool is_dag_impl(const vvll &edges, ll v, vc &status) {
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

/// @brief 閉路が存在しないかどうか
bool is_dag(const vvll &edges) {
    auto status = vc(edges.size(), (char)0);
    rep(i, edges.size()) {
        if (status[i] == 0 && !is_dag_impl(edges, i, status))
            return false;
    }
    return true;
}
