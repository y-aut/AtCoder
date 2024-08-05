// !hidden
#include "template.hpp"
DEFINE_MOD(MOD2);
// !endhidden

class Polynomial;
using Poly = Polynomial;

class Polynomial {
    // \sum a[i]x^i
    vm a;

public:
    Polynomial(const vm &_a) : a(_a) {}

    ll get_size() const { return a.size(); }
    mint get(const ll i) const { return a[i]; }
    vm &get() { return a; }

    // 値を代入する
    mint val(mint x) {
        mint ans = 0;
        mint tmp = 1;
        rep(i, get_size()) {
            ans += a[i] * tmp;
            tmp *= x;
        }
        return ans;
    }

    // 逆元を求める
    Poly inv() const {
        ll d = get_size();
        Poly f({1});
        ll accuracy = 1;
        while (accuracy < d) {
            accuracy <<= 1;
            f = f * 2 - *this * f * f;
            f.a.resize(accuracy);
        }
        f.a.resize(d);
        return f;
    }

    // 累乗を求める
    Poly pow(ll k) const {
        Poly ans({1}), p = *this;
        for (ll mask = 1; k; mask <<= 1) {
            if (k & mask) {
                k ^= mask;
                ans *= p;
            }
            if (k) p *= p;
        }
        return ans;
    }

    // pow(k) の x^n の係数を求める
    mint pow_n(ll k, ll n) const {
        Poly ans({1}), p = *this;
        for (ll mask = 1; k; mask <<= 1) {
            if (k & mask) {
                k ^= mask;
                ans *= p;
                if (ans.get_size() > n + 1) ans.a.resize(n + 1);
            }
            if (k) {
                p *= p;
                if (p.get_size() > n + 1) p.a.resize(n + 1);
            }
        }
        return ans.get_size() > n ? ans[n] : 0;
    }

    // 偶数番目の項のみを取り出す
    Poly even() const {
        vm ans;
        for (ll i = 0; i < get_size(); i += 2) {
            ans.pb(a[i]);
        }
        return ans;
    }

    // 奇数番目の項のみを取り出す
    Poly odd() const {
        vm ans;
        for (ll i = 1; i < get_size(); i += 2) {
            ans.pb(a[i]);
        }
        return ans;
    }

    // 奇数項目の係数を -1 倍したものを取得する
    Poly bar() const {
        vm ans;
        rep(i, get_size()) {
            if (i % 2 == 0) ans.pb(a[i]);
            else ans.pb(-a[i]);
        }
        return ans;
    }

    // *this / p の x^n の係数を求める (Bostan-Mori)
    mint div_n(Poly p, ll n) const {
        Poly cpy = *this;
        while (n > 0) {
            auto bar_p = p.bar();
            auto f = cpy * bar_p;
            if (n % 2 == 0) cpy = f.even();
            else cpy = f.odd();
            p = (p * bar_p).even();
            n >>= 1;
        }
        return cpy[0] / p[0];
    }

    const mint &operator[](ll i) const { return a[i]; }
    mint &operator[](ll i) { return a[i]; }

    const Poly operator-() const {
        auto ans = a;
        repi(i, ans) i = -i;
        return ans;
    }

    Poly &operator+=(const Poly &p) {
        if (p.get_size() > get_size()) a.resize(p.get_size(), 0);
        rep(i, p.get_size()) a[i] += p.a[i];
        return *this;
    }
    const Poly operator+(const Poly &p) const {
        auto ans = *this;
        ans += p;
        return ans;
    }

    Poly &operator-=(const Poly &p) { return operator+=(-p); }
    const Poly operator-(const Poly &p) const { return operator+(-p); }

    Poly &operator*=(const mint v) {
        repi(i, a) i *= v;
        return *this;
    }
    const Poly operator*(const mint v) const {
        auto ans = *this;
        ans *= v;
        return ans;
    }

    Poly &operator*=(const Poly &p) {
        a = convolution(a, p.a);
        return *this;
    }
    const Poly operator*(const Poly &p) const {
        auto ans = *this;
        ans *= p;
        return ans;
    }

    Poly &operator/=(const mint v) {
        repi(i, a) i /= v;
        return *this;
    }
    const Poly operator/(const mint v) const {
        auto ans = *this;
        ans /= v;
        return ans;
    }

    Poly &operator/=(const Poly &p) { return operator*=(p.inv()); }
    const Poly operator/(const Poly &p) const { return operator*(p.inv()); }

    bool operator==(const Poly &p) const { return a == p.a; }
    bool operator!=(const Poly &p) const { return !(*this == p); }
};
