#include "./template.cpp"

// --------------------- ここからコピー ---------------------
#pragma region "多角形"

struct Polygon {
    const ll size;
    // 時計回り or 反時計回り
    const vpll &points;

    // p1 -> p2 -> p3 が右曲がりか
    static bool is_cw(const pll &p1, const pll &p2, const pll &p3) {
        return (p2.first - p1.first) * (p3.second - p2.second) <=
               (p2.second - p1.second) * (p3.first - p2.first);
    }

public:
    Polygon(vpll &_points) : size(_points.size()), points(_points) {}

    ll get_size() const { return size; }
    pll get_point(ll i) const { return points[i]; }

    // 面積の2倍を求める
    ll get_area2() const {
        ll ans = 0;
        rep(i, size) {
            ans += (points[i].first - points[(i + 1) % size].first) *
                   (points[i].second + points[(i + 1) % size].second);
        }
        return abs(ans);
    }

    // 凸包を求める
    static Polygon get_convex_hull(const vpll &points) {
        sort(all(points), [](pll &a, pll &b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        auto q = deque<pll>();
        repi(p, points) {
            while (q.size() >= 2) {
                auto first = q.back();
                q.pop_back();
                auto second = q.back();
                if (!is_cw(second, first, p)) {
                    q.push_back(first);
                    break;
                }
            }
            q.push_back(p);
        }
        ll lower_size = q.size();
        reps(i, 1, points.size()) {
            while (q.size() - lower_size >= 1) {
                auto first = q.front();
                q.pop_front();
                auto second = q.front();
                if (is_cw(second, first, points[i])) {
                    q.push_front(first);
                    break;
                }
            }
            if (i != points.size() - 1)
                q.push_front(points[i]);
        }

        auto ans = vpll(all(q));
        return Polygon(ans);
    }
};

#pragma endregion
