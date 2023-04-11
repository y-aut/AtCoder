#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

// clang-format off
/* accelration */
// 高速バイナリ生成
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// cin cout の結びつけ解除, stdioと同期しない(入出力非同期化)
// cとstdの入出力を混在させるとバグるので注意
struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;

/* alias */
// type
using ull = unsigned long long;
using ll = long long;
using ld = long double;
// pair
using pii = pair<int, int>;
// vector
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using vpii = vector<pii>;
// unordered set
using usi = unordered_set<int>;
using usll = unordered_set<ll>;
using uss = unordered_set<string>;

/* define short */
#define pb push_back
#define mp make_pair
#define um unordered_map
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define CSI constexpr static int
#define CSLL constexpr static ll
#define CSLD constexpr static ld

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); i++)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i,n) for (ll i = n - 1; i >= 0; i--)
#define rrepd(i,n) for (ll i = n; i >= 1; i--)

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << endl;

/* func */
inline int in_int() {int x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline double in_double() {double x; cin >> x; return x;}
inline string in_str() {string x; cin >> x; return x;}
inline vi in_vi(int length) {vi res = vi(); rep(i, length) res.pb(in_int()); return res;}
inline vll in_vll(int length) {vll res = vll(); rep(i, length) res.pb(in_ll()); return res;}
inline vvi in_vvi(int width, int height)
    {vvi res = vvi(); rep(i, height) {vi tmp = vi(); rep(j, width) tmp.pb(in_int()); res.pb(tmp);} return res;}
inline vvll in_vvll(int width, int height)
    {vvll res = vvll(); rep(i, height) {vll tmp = vll(); rep(j, width) tmp.pb(in_ll()); res.pb(tmp);} return res;}
inline int ctoi(char c) {return c - '0';}
template <typename T> inline void print(const vector<T>& v, string s = " ")
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : ""); cout << endl;}
template <typename T, typename S> inline void print(const pair<T, S>& p)
    {cout << p.first << " " << p.second << endl;}
template <typename T> inline void print(const T& x) {cout << x << endl;}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v)
    {for (auto&& p : v) print(p);}
template <typename T, typename S> inline void print(const map<T, S>& m)
    {for (auto&& p : m) print(p);}
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare; if (compare = a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare; if (compare = a < b) a = b; return compare;}

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = (1LL << 60);
CSI INF = 1000000006;
CSLD EPS = 1e-10;

ll binomial_mod = 0;
vector<ll> binomial_fact, binomial_fact_inv, binomial_inv;

// 二項係数のための前処理 O(n)
void init_binomial(const ll size, const ll mod) {
    binomial_mod = mod;
    binomial_fact.resize(size + 5);
    binomial_fact_inv.resize(size + 5);
    binomial_inv.resize(size + 5);
    binomial_fact[0] = binomial_fact[1] = 1;
    binomial_fact_inv[0] = binomial_fact_inv[1] = 1;
    binomial_inv[1] = 1;
    for (ll i = 2; i < size + 5; i++) {
        binomial_fact[i] = binomial_fact[i - 1] * i % binomial_mod;
        binomial_inv[i] = binomial_mod - binomial_inv[binomial_mod % i] * (binomial_mod / i) % binomial_mod;
        binomial_fact_inv[i] = binomial_fact_inv[i - 1] * binomial_inv[i] % binomial_mod;
    }
}

// nCk % binomial_mod を求める
ll nCk(const ll n, const ll k) {
    if (k < 0 || n < k) return 0;
    return binomial_fact[n] * (binomial_fact_inv[k] * binomial_fact_inv[n - k] % binomial_mod) % binomial_mod;
}

int main()
{
    auto H = in_ll();
    auto W = in_ll();
    auto K = in_ll();

    init_binomial(H * W, MOD2);
    modint998244353 all_cnt = nCk(H * W, K);
    modint998244353 sum = 0;

    // (HW)C(K) のうち，マス (i,j) が長方形に含まれるようなものの個数
    rep(i, H) rep(j, W) {
        modint998244353 cnt = all_cnt -
            (nCk(i * W, K) + nCk((H-i-1) * W, K) + nCk(H * j, K) + nCk(H * (W-j-1), K) -
            nCk(i * j, K) - nCk((H-i-1) * j, K) - nCk(i * (W-j-1), K) - nCk((H-i-1) * (W-j-1), K));
        sum += cnt;
    }

    print((sum / all_cnt).val());

    return 0;
}