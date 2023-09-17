#include "../tpl/template.cpp"

#pragma region "二項係数"

class Binomial {
    const ll mod = 0;
    vll fact, fact_inv, inv;

public:
    Binomial(const ll size, const ll _mod) : mod(_mod), fact(size + 5), fact_inv(size + 5), inv(size + 5) {
        fact[0] = fact[1] = 1;
        fact_inv[0] = fact_inv[1] = 1;
        inv[1] = 1;

        for (ll i = 2; i < size + 5; i++) {
            fact[i] = fact[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
        }
    }

    /// nCk % mod を求める
    ll nCk(const ll n, const ll k) const {
        if (k < 0 || n < k)
            return 0;
        return fact[n] * (fact_inv[k] * fact_inv[n - k] % mod) % mod;
    }

    /// nPk % mod を求める
    ll nPk(const ll n, const ll k) const {
        if (k < 0 || n < k)
            return 0;
        return fact[n] * (fact_inv[n - k] % mod) % mod;
    }

    /// nHk % mod を求める
    ll nHk(const ll n, const ll k) const {
        if (n == 0 && k == 0)
            return 1;
        return nCk(n + k - 1, k);
    }
};

#pragma endregion

#pragma region "素数判定"

bool is_prime(ll n) {
    if (n <= 1) return false;
    if (n % 2 == 0) return n == 2;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

#pragma endregion

#pragma region "素因数分解"

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

#pragma endregion

#pragma region "約数列挙"

vll factors(ll n) {
    vll ans{1};
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) ans.pb(i);
    }
    for (ll i = ans.size() - (ans.back() * ans.back() == n ? 2 : 1); i >= 0; i--) {
        ans.pb(n / ans[i]);
    }
    return ans;
}

#pragma endregion

#pragma region "素数・素因数列挙"

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
vll primes(ll n) {
    vll ans;
    vb cnt(n + 1);
    rrep(i, 2, n) {
        if (cnt[i]) continue;
        ans.pb(i);
        for (ll j = i; j <= n; j += i) cnt[j] = true;
    }
    return ans;
}

#pragma endregion
