// !hidden
#include "template.hpp"
// !endhidden

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
