#include "../tpl/template.cpp"

#pragma region "座標圧縮"

// 1 次元配列を座標圧縮する
vll get_compressed(const vll &A) {
    vll B = A;
    sort(all(B));
    B.erase(unique(all(B)), B.end());

    vll ans(A.size());
    rep(i, A.size()) {
        ans[i] = lower_bound(all(B), A[i]) - B.begin();
    }

    return ans;
}

#pragma endregion

#pragma region "転倒数"

// 座標圧縮された数列に対して，転倒数を求める
ll get_inversion(const vll &A) {
    fenwick_tree<ll> ft(A.size());
    ll ans = 0;
    repd(i, A.size()) {
        ans += ft.sum(0, A[i]);
        ft.add(A[i], 1);
    }
    return ans;
}

#pragma endregion

#pragma region "最長増加部分列"

class LIS {
    const vll &v;
    // lis[i]: v[0] ~ v[i] の LIS の長さ
    vll len;

    void set_len() {
        vll tmp;
        repi(a, v) {
            auto itr = lower_bound(all(tmp), a);
            auto cnt = distance(tmp.begin(), itr);
            if (cnt == tmp.size()) {
                tmp.pb(a);
            } else {
                tmp[cnt] = a;
            }
            len.pb(tmp.size());
        }
    }

public:
    LIS(vll &_v) : v(_v) {
        set_len();
    }

    ll get_length(const ll i) const { return len[i]; }
};

#pragma endregion
