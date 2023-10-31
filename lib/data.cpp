#include "../tpl/template.cpp"

#pragma region "区間を set で管理する"

/// @brief 開区間を set で管理する．
/// @tparam merge [3, 4), [4, 5) を [3, 5) と扱うかどうか．
template <bool merge>
class IntervalSet {
    set<pll> s;

    inline bool lt(ll x, ll y) const {
        if (merge) return x <= y;
        else return x < y;
    }

public:
    IntervalSet() {
        s.insert({-LINF, -LINF});
        s.insert({LINF, LINF});
    }

    set<pll> &get_set() { return s; }

    // 指定した区間と交わる区間を取得する
    vpll intersect(const pll &interval) {
        vpll ans;
        auto itr = prev(s.lower_bound(interval));
        if (itr->first <= interval.first && interval.first < itr->second) {
            ans.pb(*itr);
        }
        while (true) {
            itr++;
            if (interval.first <= itr->first && itr->first < interval.second) {
                ans.pb(*itr);
            } else break;
        }
        return ans;
    }

    // 区間を挿入し，マージする
    pll insert(const pll &interval) {
        ll x = interval.first, y = interval.second;
        auto itr = prev(s.lower_bound(interval));

        // 直前の区間が被っていたらマージする
        if (itr->first <= x && lt(x, itr->second)) {
            chmin(x, itr->first);
            chmax(y, itr->second);
            s.erase(itr);
        }
        itr = s.lower_bound({x, y});

        while (true) {
            if (x <= itr->first && lt(itr->first, y)) {
                chmax(y, itr->second);
                itr = s.erase(itr);
            } else break;
        }
        s.insert({x, y});
        return {x, y};
    }
};

#pragma endregion
