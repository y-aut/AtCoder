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

// 各 i に対して，A[0:i] の LIS を求める
vll get_lis(const vll &A) {
    vll ans, tmp;
    repi(a, A) {
        auto cnt = lower_bound(all(tmp), a) - tmp.begin();
        if (cnt == tmp.size()) {
            tmp.pb(a);
        } else {
            tmp[cnt] = a;
        }
        ans.pb(tmp.size());
    }
    return ans;
}

#pragma endregion
