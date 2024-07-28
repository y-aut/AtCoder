#pragma region "Template"

#ifdef DEBUG
#include "template.hpp"
#else
#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <atcoder/all>
#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;
using namespace atcoder;

// clang-format off

#ifndef DEBUG
#ifdef __x86_64__
#pragma GCC target("avx")
#endif
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); } } fast;
#endif

/* templates */
#define TPL_T template <typename T>
#define TPL_TS template <typename T, typename S>
#define TPL_TSU template <typename T, typename S, typename U>
#define TPL_TSUV template <typename T, typename S, typename U, typename V>
#define TPL_TSUVW template <typename T, typename S, typename U, typename V, typename W>

/* alias */
// type
#define us unordered_set
#define um unordered_map
using ull = unsigned long long;
using ll = long long;
using mll = mpz_class;
using md = mpf_class;
// pair
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// vector
TPL_T using v = vector<T>;
TPL_T using vv = v<v<T>>;
TPL_T using vvv = v<vv<T>>;
using vi = v<int>;
using vll = v<ll>;
using vmll = v<mll>;
using vd = v<double>;
using vmd = v<md>;
using vb = v<bool>;
using vc = v<char>;
using vs = v<string>;
using vpii = v<pii>;
using vpll = v<pll>;
using vvi = v<vi>;
using vvll = v<vll>;
using vvb = v<vb>;
using vvpii = v<vpii>;
using vvpll = v<vpll>;
// unordered set
using usi = us<int>;
using usll = us<ll>;
using uss = us<string>;
// unordered map
using umi = um<int, int>;
using umll = um<ll, ll>;

/* mint */
#define DEFINE_MOD(m)               \
    using mint = static_modint<m>;  \
    using vm = v<mint>;             \
    using vvm = v<vm>;              \
    using pmm = pair<mint, mint>;   \
    inline vm in_vm(int length) { vm res; rep(i, length) res.pb(in_ll()); return res; } \
    inline vvm in_vvm(int height, int width) { vvm res; rep(i, height) res.pb(in_vm(width)); return res; }

/* extract params */
#define HEAD_NAME(x, ...) #x
#define OVERLOAD3(_1, _2, _3, x, ...) x

/* define short */
#define CSI constexpr static int
#define CSLL constexpr static ll
#define CSD constexpr static double
#define pb push_back
#define eb emplace_back
#define all(obj) (obj).begin(), (obj).end()
#define pcnt __builtin_popcount
#define pcntll __builtin_popcountll

/* set variables */
#define VAR(type, ...) type __VA_ARGS__; IN(__VA_ARGS__)
#define INT(...) VAR(int, __VA_ARGS__)
#define LL(...) VAR(ll, __VA_ARGS__)
#define MLL(...) VAR(mll, __VA_ARGS__)
#define DBL(...) VAR(double, __VA_ARGS__)
#define CHR(...) VAR(char, __VA_ARGS__)
#define STR(...) VAR(string, __VA_ARGS__)
#define PII(...) VAR(pii, __VA_ARGS__)
#define PLL(...) VAR(pll, __VA_ARGS__)
#define VI(a, b) auto a = in_vi(b)
#define VLL(a, b) auto a = in_vll(b)
#define VMLL(a, b) auto a = in_vmll(b)
#define VM(a, b) auto a = in_vm(b)
#define VD(a, b) auto a = in_vd(b)
#define VC(a, b) auto a = in_vc(b)
#define VS(a, b) auto a = in_vs(b)
#define VPII(a, b) auto a = in_vpii(b)
#define VPLL(a, b) auto a = in_vpll(b)
#define VVI(a, h, w) auto a = in_vvi(h, w)
#define VVLL(a, h, w) auto a = in_vvll(h, w)
#define VVM(a, h, w) auto a = in_vvm(h, w)

/* REP macro */
#define REP2(i, a, n) for (ll i = (ll)(a); i < (ll)(n); i++)
#define REP1(i, n) REP2(i, 0, n)
#define RREP2(i, a, n) for (ll i = (ll)(a); i <= (ll)(n); i++)
#define RREP1(i, n) RREP2(i, 1, n)
#define REPD2(i, a, n) for (ll i = (ll)(n) - 1; i >= (ll)(a); i--)
#define REPD1(i, n) REPD2(i, 0, n)
#define RREPD2(i, a, n) for (ll i = (ll)(n); i >= (ll)(a); i--)
#define RREPD1(i, n) RREPD2(i, 1, n)
#define REPI1(a, v) for (auto&& a : (v))
#define REPI2(a, b, v) for (auto&& [a, b] : (v))
#define rep(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define rrep(...) OVERLOAD3(__VA_ARGS__, RREP2, RREP1)(__VA_ARGS__)
#define repd(...) OVERLOAD3(__VA_ARGS__, REPD2, REPD1)(__VA_ARGS__)
#define rrepd(...) OVERLOAD3(__VA_ARGS__, RREPD2, RREPD1)(__VA_ARGS__)
#define repi(...) OVERLOAD3(__VA_ARGS__, REPI2, REPI1)(__VA_ARGS__)

/* control */
#define EXIT(...) ({ __VA_ARGS__; exit(0); })
#define BREAK(...) ({ __VA_ARGS__; break; })
#define CONTINUE(...) ({ __VA_ARGS__; continue; })

// istream
TPL_TS istream &operator>>(istream &is, pair<T, S> &v) { is >> v.first >> v.second; return is; }

/* func */
// input
inline int in_int() { int x; cin >> x; return x; }
inline ll in_ll() { ll x; cin >> x; return x; }
inline mll in_mll() { mll x; cin >> x; return x; }
inline double in_double() { double x; cin >> x; return x; }
inline char in_char() { char c; cin >> c; return c; }
inline string in_str() { string x; cin >> x; return x; }
inline pii in_pii() { pii x; cin >> x; return x; }
inline pll in_pll() { pll x; cin >> x; return x; }
inline vi in_vi(int length) { vi res; rep(i, length) res.pb(in_int()); return res; }
inline vll in_vll(int length) { vll res; rep(i, length) res.pb(in_ll()); return res; }
inline vmll in_vmll(int length) { vmll res; rep(i, length) res.pb(in_mll()); return res; }
inline vd in_vd(int length) { vd res; rep(i, length) res.pb(in_double()); return res; }
inline vc in_vc(int length) { vc res; rep(i, length) res.pb(in_char()); return res; }
inline vs in_vs(int height) { vs res; rep(i, height) res.pb(in_str()); return res; }
inline vpii in_vpii(int height) { vpii res; rep(i, height) res.pb(in_pii()); return res; }
inline vpll in_vpll(int height) { vpll res; rep(i, height) res.pb(in_pll()); return res; }
inline vvi in_vvi(int height, int width) { vvi res; rep(i, height) res.pb(in_vi(width)); return res; }
inline vvll in_vvll(int height, int width) { vvll res; rep(i, height) res.pb(in_vll(width)); return res; }
template <bool bidir> inline vvll in_edges(int N, int height, ll base = 1)
    { vvll res(N, vll()); rep(i, height) { ll a = in_ll() - base; ll b = in_ll() - base;
    res[a].pb(b); if (bidir) res[b].pb(a); } return res; }
template <bool bidir> inline v<usll> in_edges_us(int N, int height, ll base = 1)
    { v<usll> res(N, usll()); rep(i, height) { ll a = in_ll() - base; ll b = in_ll() - base;
    res[a].insert(b); if (bidir) res[b].insert(a); } return res; }
template <bool bidir> inline vvpll in_wedges(int N, int height, ll base = 1)
    { vvpll res(N, vpll()); rep(i, height) { ll a = in_ll() - base; ll b = in_ll() - base; ll w = in_ll();
    res[a].eb(b, w); if (bidir) res[b].eb(a, w); } return res; }
inline void IN() {}
template <typename First, typename... Rest> inline void IN(First &first, Rest &...rest) { cin >> first; IN(rest...); }

// conversion
inline mll to_mll(ll v) { return mll(to_string(v)); }
inline md to_md(ll v) { return md(to_string(v)); }

// change min/max
template <typename T, typename S> inline bool chmin(T &a, const S &b) { return a > b && (a = b, true); }
template <typename T, typename S> inline bool chmax(T &a, const S &b) { return a < b && (a = b, true); }

// operator
TPL_TS pair<T, S> operator-(const pair<T, S> &v) { return { -v.first, -v.second }; }
TPL_TS pair<T, S> &operator+=(pair<T, S> &a, const pair<T, S> &b) { a.first += b.first; a.second += b.second; return a; }
TPL_TS pair<T, S> &operator-=(pair<T, S> &a, const pair<T, S> &b) { return a += -b; }
TPL_TSU pair<T, S> &operator*=(pair<T, S> &a, const U &b) { a.first *= b; a.second *= b; return a; }
TPL_TSU pair<T, S> &operator/=(pair<T, S> &a, const U &b) { a.first /= b; a.second /= b; return a; }
TPL_TS pair<T, S> &operator+=(pair<T, S> &&a, const pair<T, S> &b) { return a += b; }
TPL_TS pair<T, S> &operator-=(pair<T, S> &&a, const pair<T, S> &b) { return a -= b; }
TPL_TSU pair<T, S> &operator*=(pair<T, S> &&a, const U &b) { return a *= b; }
TPL_TSU pair<T, S> &operator/=(pair<T, S> &&a, const U &b) { return a /= b; }
TPL_TS pair<T, S> operator+(const pair<T, S> &a, const pair<T, S> &b) { return pair<T, S>(a) += b; }
TPL_TS pair<T, S> operator-(const pair<T, S> &a, const pair<T, S> &b) { return pair<T, S>(a) -= b; }
TPL_TSU pair<T, S> operator*(const pair<T, S> &a, const U &b) { return pair<T, S>(a) *= b; }
TPL_TSU pair<T, S> operator/(const pair<T, S> &a, const U &b) { return pair<T, S>(a) /= b; }

// math
inline ll powll(ll a, ll b) { ll ans = 1; rep(i, b) ans *= a; return ans; }
inline ll llceil(ll a, ll b) { return a % b == 0 ? a / b : (a >= 0 ? (a / b) + 1 : -((-a) / b)); }
inline ll llfloor(ll a, ll b) { return a % b == 0 ? a / b : (a >= 0 ? (a / b) : -((-a) / b) - 1); }
TPL_T T abs2(const pair<T, T> &p) { return p.first * p.first + p.second * p.second; }
double abs(const pll &p) { return sqrt(abs2(p)); }

// hash
TPL_T struct Hasher { ull operator()(const T &v) const { return hash<T>()(v); } };
template <> struct Hasher<pii> { ull operator()(const pii &v) const { return (ull)v.first << 32 | (ull)v.second; } };
template <> struct Hasher<pll> { ull operator()(const pll &v) const { return (ull)v.first << 32 | (ull)v.second; } };
TPL_T using ush = us<T, Hasher<T>>;
TPL_TS using umh = um<T, S, Hasher<T>>;

// ostream
#define OSTREAM(class, ...) \
    void __inner_print(ostream& os) const { print_all(os, __VA_ARGS__); } \
    friend ostream& operator<<(ostream& os, const class& v) { v.__inner_print(os); return os; }
template <int V> ostream &operator<<(ostream &os, const static_modint<V> &v) { os << v.val(); return os; }
ostream &operator<<(ostream &os, const modint &v) { os << v.val(); return os; }
TPL_TS ostream &operator<<(ostream &os, const pair<T, S> &v) { os << v.first << " " << v.second; return os; }

// print
TPL_T inline void print(const T &v, string end = "\n") { cout << v << end; }
TPL_TS inline void print(const v<pair<T, S>> &v) { repi(i, v) print(i); }
TPL_TS inline void print(const map<T, S> &v) { repi(i, v) print(i); }
TPL_T inline typename enable_if<is_base_of<forward_iterator_tag,
    typename iterator_traits<T>::iterator_category>::value>::type print(const T &begin, const T &end, string sep = " ")
    { for (auto i = begin; i != end; i++) print(*i, i != prev(end) ? sep : ""); cout << '\n'; }
TPL_T inline void print(const v<T> &v, string sep = " ") { print(all(v), sep); }
TPL_T inline void print(const set<T> &v, string sep = " ") { print(all(v), sep); }
TPL_T inline void print(const vv<T> &v) { repi(i, v) print(i); }
void print_all_inner(ostream&) {}
template <typename First, typename... Rest> void print_all_inner(ostream& os, const First &f, const Rest &...r)
    { os << ' ' << f; print_all_inner(os, r...); }
template <typename First, typename... Rest> void print_all(ostream& os, const First &f, const Rest &...r)
    { os << f; print_all_inner(os, r...); }

#define YES print("YES")
#define NO print("NO")
#define Yes print("Yes")
#define No print("No")
#define YESNO(bool) if (bool) YES; else NO
#define YesNo(bool) if (bool) Yes; else No

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...) (void)0
#define debugs(...) (void)0
#endif

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = (ll)4.1e18;
CSI INF = 1000000006;
CSD EPS = 1e-11;
CSD PI = 3.141592653589793;
CSD PHI = 1.6180339887498948;
CSLL DX[] = {1, 0, -1, 0};
CSLL DY[] = {0, 1, 0, -1};
#endif
#endif

// clang-format on

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

DEFINE_MOD(MOD2);

template <int char_size>
struct TrieNode {
    int nxt[char_size];

    int exist;
    vector<int> accept;

    TrieNode() : exist(0) {
        memset(nxt, -1, sizeof(nxt));
    }
};

template <int char_size, int margin>
struct Trie {
    using Node = TrieNode<char_size>;

    vector<Node> nodes;
    int root;

    Trie() : root(0) {
        nodes.push_back(Node());
    }

    void update_direct(int node, int id) {
        nodes[node].accept.push_back(id);
    }

    void update_child(int node, int child, int id) {
        ++nodes[node].exist;
    }

    void add(const string &str, int str_index, int node_index, int id) {
        if (str_index == str.size()) {
            update_direct(node_index, id);
        } else {
            const int c = str[str_index] - margin;
            if (nodes[node_index].nxt[c] == -1) {
                nodes[node_index].nxt[c] = (int)nodes.size();
                nodes.push_back(Node());
            }
            add(str, str_index + 1, nodes[node_index].nxt[c], id);
            update_child(node_index, nodes[node_index].nxt[c], id);
        }
    }

    void add(const string &str, int id) {
        add(str, 0, 0, id);
    }

    void add(const string &str) {
        add(str, nodes[0].exist);
    }

    void query(const string &str, const function<void(int)> &f, int str_index, int node_index) {
        for (auto &idx : nodes[node_index].accept) f(idx);
        if (str_index == str.size()) {
            return;
        } else {
            const int c = str[str_index] - margin;
            if (nodes[node_index].nxt[c] == -1) return;
            query(str, f, str_index + 1, nodes[node_index].nxt[c]);
        }
    }

    void query(const string &str, const function<void(int)> &f) {
        query(str, f, 0, 0);
    }

    int count() const {
        return (nodes[0].exist);
    }

    int size() const {
        return ((int)nodes.size());
    }
};

/**
 * @brief Aho-Corasick(エイホ–コラシック法)
 *
 */
template <int char_size, int margin>
struct AhoCorasick : Trie<char_size + 1, margin> {
    using Trie<char_size + 1, margin>::Trie;

    const int FAIL = char_size;
    vector<int> correct;

    void build(bool heavy = true) {
        correct.resize(this->size());
        for (int i = 0; i < this->size(); i++) {
            correct[i] = (int)this->nodes[i].accept.size();
        }
        queue<int> que;
        for (int i = 0; i <= char_size; i++) {
            if (~this->nodes[0].nxt[i]) {
                this->nodes[this->nodes[0].nxt[i]].nxt[FAIL] = 0;
                que.emplace(this->nodes[0].nxt[i]);
            } else {
                this->nodes[0].nxt[i] = 0;
            }
        }
        while (!que.empty()) {
            auto &now = this->nodes[que.front()];
            int fail = now.nxt[FAIL];
            correct[que.front()] += correct[fail];
            que.pop();
            for (int i = 0; i < char_size; i++) {
                if (~now.nxt[i]) {
                    this->nodes[now.nxt[i]].nxt[FAIL] = this->nodes[fail].nxt[i];
                    if (heavy) {
                        auto &u = this->nodes[now.nxt[i]].accept;
                        auto &v = this->nodes[this->nodes[fail].nxt[i]].accept;
                        vector<int> accept;
                        set_union(begin(u), end(u), begin(v), end(v), back_inserter(accept));
                        u = accept;
                    }
                    que.emplace(now.nxt[i]);
                } else {
                    now.nxt[i] = this->nodes[fail].nxt[i];
                }
            }
        }
    }

    map<int, int> match(const string &str, int now = 0) {
        map<int, int> result;
        for (auto &c : str) {
            now = this->nodes[now].nxt[c - margin];
            for (auto &v : this->nodes[now].accept) result[v] += 1;
        }
        return result;
    }

    pair<int64_t, int> move(const char &c, int now = 0) {
        now = this->nodes[now].nxt[c - margin];
        return {correct[now], now};
    }

    pair<int64_t, int> move(const string &str, int now = 0) {
        int64_t sum = 0;
        for (auto &c : str) {
            auto nxt = move(c, now);
            sum += nxt.first;
            now = nxt.second;
        }
        return {sum, now};
    }
};

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

void solve() {
    LL(N, M);
    VS(S, M);
    AhoCorasick<2, 'a'> tree;
    repi(i, S) tree.add(i);
    tree.build();
    SquareMatrix<mint, (1 << 7) + 10> mat;
    debug(tree.nodes.size());
    rep(i, tree.nodes.size()) {
        rep(c, 2) {
            if (tree.correct[tree.nodes[i].nxt[c]] == 0) {
                mat[tree.nodes[i].nxt[c]][i]++;
            }
        }
    }
    mat = mat.pow(N);
    mint ans = 0;
    rep(i, tree.nodes.size()) ans += mat[i][0];
    print(ans);
}
