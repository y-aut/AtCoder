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

#pragma region "正方行列"

/**
 * @brief Square-Matrix(正方行列)
 */
template <class T, size_t N>
struct SquareMatrix {
    array<array<T, N>, N> A;

    SquareMatrix() : A{{}} {}

    size_t size() const { return N; }

    inline const array<T, N> &operator[](int k) const {
        return (A.at(k));
    }

    inline array<T, N> &operator[](int k) {
        return (A.at(k));
    }

    static SquareMatrix add_identity() {
        return SquareMatrix();
    }

    static SquareMatrix mul_identity() {
        SquareMatrix mat;
        for (size_t i = 0; i < N; i++) mat[i][i] = 1;
        return mat;
    }

    SquareMatrix &operator+=(const SquareMatrix &B) {
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }

    SquareMatrix &operator-=(const SquareMatrix &B) {
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }

    SquareMatrix &operator*=(const SquareMatrix &B) {
        array<array<T, N>, N> C;
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                for (size_t k = 0; k < N; k++) {
                    C[i][j] = (C[i][j] + (*this)[i][k] * B[k][j]);
                }
            }
        }
        A.swap(C);
        return (*this);
    }

    SquareMatrix &operator^=(uint64_t k) {
        SquareMatrix B = SquareMatrix::mul_identity();
        while (k > 0) {
            if (k & 1) B *= *this;
            *this *= *this;
            k >>= 1LL;
        }
        A.swap(B.A);
        return *this;
    }

    SquareMatrix operator+(const SquareMatrix &B) const {
        return SquareMatrix(*this) += B;
    }

    SquareMatrix operator-(const SquareMatrix &B) const {
        return SquareMatrix(*this) -= B;
    }

    SquareMatrix operator*(const SquareMatrix &B) const {
        return SquareMatrix(*this) *= B;
    }

    SquareMatrix operator^(uint64_t k) const {
        return SquareMatrix(*this) ^= k;
    }

    SquareMatrix pow(uint64_t n) const {
        SquareMatrix a = *this, res = mul_identity();
        for (; n; a = a * a, n >>= 1)
            if (n & 1) res = res * a;
        return res;
    }

    friend ostream &operator<<(ostream &os, SquareMatrix &p) {
        for (int i = 0; i < N; i++) {
            os << "[";
            for (int j = 0; j < N; j++) {
                os << p[i][j] << (j + 1 == N ? "]\n" : ",");
            }
        }
        return os;
    }
};

#pragma endregion
