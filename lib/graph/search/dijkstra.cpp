// !hidden
#include "template.hpp"
// !endhidden

class Dijkstra {
    const vvpll &wedges;
    const ll start;
    vll dist;
    vll prev; // 直前の頂点を記録する配列

    void set_dist() {
        // (現時点での最短距離, 頂点)
        priority_queue<pll, vector<pll>, greater<pll>> q;
        q.emplace(dist[start] = 0, start);

        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            if (dist[p.second] < p.first) continue;

            repi(i, wedges[p.second]) {
                ll d = dist[p.second] + i.second;
                if (d < dist[i.first]) {
                    prev[i.first] = p.second;
                    q.emplace(dist[i.first] = d, i.first);
                }
            }
        }
    }

public:
    Dijkstra(const vvpll &_edges, ll _start) : wedges(_edges), start(_start), dist(wedges.size(), LINF), prev(wedges.size(), -1) {
        set_dist();
    }

    ll get_dist(ll v) const { return dist[v]; }
    vll &get_dist() { return dist; }

    // 最短経路を取得
    vll get_path(ll v) const {
        vll ans;
        for (ll i = v; i >= 0; i = prev[i]) ans.pb(i);
        reverse(all(ans));
        return ans;
    }
};
