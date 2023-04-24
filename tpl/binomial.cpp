#include "./template.cpp"

// --------------------- ここからコピー ---------------------
class Binomial {
    ll mod = 0;
    vll fact, fact_inv, inv;

public:
    Binomial(const ll size, const ll _mod) {
        mod = _mod;
        fact = vll(size + 5);
        fact_inv = vll(size + 5);
        inv = vll(size + 5);

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
    ll nCk(const ll n, const ll k) {
        if (k < 0 || n < k)
            return 0;
        return fact[n] * (fact_inv[k] * fact_inv[n - k] % mod) % mod;
    }

    /// nPk % mod を求める
    ll nPk(const ll n, const ll k) {
        if (k < 0 || n < k)
            return 0;
        return fact[n] * (fact_inv[n - k] % mod) % mod;
    }

    /// nHk % mod を求める
    ll nHk(const ll n, const ll k) {
        if (n == 0 && k == 0)
            return 1;
        return nCk(n + k - 1, k);
    }
};
