// !hidden
#include "template.hpp"
// !endhidden

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
