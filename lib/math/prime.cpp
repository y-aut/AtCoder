// !hidden
#include "template.hpp"
// !endhidden

bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n % 2 == 0) return n == 2;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// 素因数分解
// a^b * c^d: [(a, b), (c, d)]
vpll prime_factors(ll n) {
    vpll ans;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            n /= i;
            ll cnt = 1;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            ans.eb(i, cnt);
            if (n == 1) break;
        }
    }
    if (n != 1) ans.eb(n, 1);
    return ans;
}

// [0, n] の各整数の素因数を列挙する
vvll prime_factors_all(ll n) {
    vvll ans(n + 1);
    rrep(i, 2, n) {
        if (!ans[i].empty()) continue;
        for (ll j = i; j <= n; j += i) ans[j].pb(i);
    }
    return ans;
}

// [0, n] の各整数の素因数の個数を列挙する
vll prime_factors_count_all(ll n) {
    vll ans(n + 1);
    rrep(i, 2, n) {
        if (ans[i]) continue;
        for (ll j = i; j <= n; j += i) ans[j]++;
    }
    return ans;
}

// [0, n] の素数を列挙する
vll get_primes(ll n) {
    vll ans;
    vb cnt(n + 1);
    rrep(i, 2, n) {
        if (cnt[i]) continue;
        ans.pb(i);
        for (ll j = i; j <= n; j += i) cnt[j] = true;
    }
    return ans;
}
