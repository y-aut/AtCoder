#include "../tpl/template.cpp"

#pragma region "ローリングハッシュ"

CSLL MOD_SIZE = 6;
const ull HASH_BASE[] = {889293976, 1872217329, 1787722576, 1005514673, 981914693, 1375179334};
const ull HASH_MOD[] = {1944897763, 1925898167, 1912776091, 1935497281, 1939942439, 1902550399};
vector<ull> HASH_BASE_POW[] = {{1}, {1}, {1}, {1}, {1}, {1}};

ull get_hash_base_pow(ll index, ull n) {
    assert(0 <= index && index < MOD_SIZE);
    while (HASH_BASE_POW[index].size() <= n) {
        HASH_BASE_POW[index].pb(HASH_BASE_POW[index].back() * HASH_BASE[index] % HASH_MOD[index]);
    }
    return HASH_BASE_POW[index][n];
}

template <int mod_num = 4>
struct RollingHash {
    ll size;
    array<ull, mod_num> hash = {};

    RollingHash() : size(0) {}
    RollingHash(const string s) : size(s.size()) {
        rep(i, size) rep(j, mod_num) {
            hash[j] += get_hash_base_pow(j, size - i - 1) * s[i];
            hash[j] %= HASH_MOD[j];
        }
    }
    RollingHash(char c) : size(1) { rep(i, mod_num) hash[i] = c; }
    RollingHash(const RollingHash &src) : size(src.size), hash(src.hash) {}
    RollingHash(RollingHash &&src) : size(src.size), hash(move(src.hash)) {}

    void pop_front(char c) {
        rep(i, mod_num) {
            hash[i] += HASH_MOD[i] - get_hash_base_pow(i, size - 1) * c % HASH_MOD[i];
            hash[i] %= HASH_MOD[i];
        }
        size--;
    }

    void push_back(char c) {
        rep(i, mod_num) {
            hash[i] *= HASH_BASE[i];
            hash[i] += c;
            hash[i] %= HASH_MOD[i];
        }
        size++;
    }

    RollingHash &operator=(const RollingHash &v) & {
        size = v.size;
        hash = v.hash;
        return *this;
    }
    RollingHash &operator=(RollingHash &&v) & noexcept {
        if (this != &v) {
            size = v.size;
            hash = move(v.hash);
        }
        return *this;
    }
    RollingHash &operator+=(const RollingHash &v) {
        rep(i, mod_num) {
            hash[i] *= get_hash_base_pow(i, v.size);
            hash[i] += v.hash[i];
            hash[i] %= HASH_MOD[i];
        }
        size += v.size;
        return *this;
    }
};

template <int n>
bool operator==(const RollingHash<n> &a, const RollingHash<n> &b) {
    rep(i, n) if (a.hash[i] != b.hash[i]) return false;
    return a.size == b.size;
}
template <int n>
bool operator!=(const RollingHash<n> &a, const RollingHash<n> &b) { return !(a == b); }
template <int n>
RollingHash<n> operator+(const RollingHash<n> &a, const RollingHash<n> &b) {
    return RollingHash(a) += b;
}

#pragma endregion
