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

int main()
{
    auto N = in_ll();
    auto B = in_int();
    auto K = in_int();
    auto c = in_vi(K);

    static constexpr int DP_LEN = 65;

    // dp[i][j]: 2^i 桁, 余り j
    modint1000000007* dp[DP_LEN];
    rep(i, DP_LEN) {
        dp[i] = new modint1000000007[B];
        rep(j, B) dp[i][j] = modint1000000007();
    }

    rep(k, K) {
        dp[0][c.at(k) % B]++;
    }

    // power10[i]: 10^(2^i) % B
    ll power10[DP_LEN];
    power10[0] = 10 % B;

    reps(i, 1, DP_LEN) {
        power10[i] = power10[i-1] * power10[i-1] % B;
        rep(j, B) {
            rep(k, B) {
                dp[i][(j * power10[i-1] + k) % B] += dp[i-1][j] * dp[i-1][k];
            }
        }
    }

    modint1000000007* last[2];
    rep(i, 2) {
        last[i] = new modint1000000007[B];
        rep(j, B) last[i][j] = modint1000000007();
    }
    int sw = 0;

    bool flg = true;
    for (ll mask = 1, i = 0; mask <= N; mask <<= 1, i++) {
        if ((N & mask) == 0) continue;
        if (flg) {
            flg = false;
            memcpy(last[sw], dp[i], sizeof(modint1000000007) * B);
            sw ^= 1;
            continue;
        }
        rep(j, B) last[sw][j] = modint1000000007();
        rep(j, B) {
            rep(k, B) {
                last[sw][(j * power10[i] + k) % B] += last[sw ^ 1][j] * dp[i][k];
            }
        }
        sw ^= 1;
    }

    print(last[sw ^ 1][0].val());

    rep(i, 2) {
        delete[] last[i];
    }
    rep(i, DP_LEN) {
        delete[] dp[i];
    }

    return 0;
}