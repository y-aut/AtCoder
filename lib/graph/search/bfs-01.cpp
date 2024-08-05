// !hidden
#include "template.hpp"
// !endhidden

class BFS01 {
    vll dist;

public:
    BFS01(vvll &zero_edges, vvll &one_edges, ll startIndex) : dist(zero_edges.size(), LINF) {
        dist[startIndex] = 0;

        deque<ll> q;
        q.emplace_back(startIndex);

        while (!q.empty()) {
            auto v = q.front();
            q.pop_front();

            repi(i, zero_edges[v]) {
                if (dist[v] < dist[i]) {
                    dist[i] = dist[v];
                    q.push_front(i);
                }
            }
            repi(i, one_edges[v]) {
                if (dist[v] + 1 < dist[i]) {
                    dist[i] = dist[v] + 1;
                    q.push_back(i);
                }
            }
        }
    }

    // 最短距離を取得
    ll get_distance(ll v) const {
        return dist[v];
    }
};
