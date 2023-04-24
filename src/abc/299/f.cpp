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
using pll = pair<ll, ll>;
// vector
using vi = vector<int>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvb = vector<vb>;
using vs = vector<string>;
using vpii = vector<pii>;
using vpll = vector<pll>;
// unordered set
using usi = unordered_set<int>;
using usll = unordered_set<ll>;
using uss = unordered_set<string>;

/* define short */
#define pb push_back
#define mp make_pair
#define um unordered_map
#define us unordered_set
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
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define rrepd(i, n) for (ll i = n; i >= 1; i--)
#define repi(a, v) for (auto a : (v))

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << endl;

/* func */
inline int in_int() {int x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline double in_double() {double x; cin >> x; return x;}
inline pii in_pii() {pii x; cin >> x.first >> x.second; return x;}
inline pll in_pll() {pll x; cin >> x.first >> x.second; return x;}
inline char in_char() {char c; cin >> c; return c;}
inline string in_str() {string x; cin >> x; return x;}
inline vi in_vi(int length) {vi res = vi(); rep(i, length) res.pb(in_int()); return res;}
inline vll in_vll(int length) {vll res = vll(); rep(i, length) res.pb(in_ll()); return res;}
inline vs in_vs(int height) {vs res = vs(); rep(i, height) res.pb(in_str()); return res;}
inline vvi in_vvi(int width, int height)
    {vvi res = vvi(); rep(i, height) {vi tmp = vi(); rep(j, width) tmp.pb(in_int()); res.pb(tmp);} return res;}
inline vvll in_vvll(int width, int height)
    {vvll res = vvll(); rep(i, height) {vll tmp = vll(); rep(j, width) tmp.pb(in_ll()); res.pb(tmp);} return res;}
inline vpii in_vpii(int height)
    {vpii res = vpii(); rep(i, height) {pii tmp; tmp.first = in_int(); tmp.second = in_int(); res.pb(tmp);} return res;}
inline vpll in_vpll(int height)
    {vpll res = vpll(); rep(i, height) {pll tmp; tmp.first = in_ll(); tmp.second = in_ll(); res.pb(tmp);} return res;}
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
CSLD PHI = 1.6180339887498948;

// clang-format on
modint998244353 dp[102][102] = {};

int main() {
    auto S = in_str();

    // sigma[i][j]: Si...S[N-1] で j が現れる最も左のインデックス
    int sigma[102][26];
    rep(i, 102) rep(j, 26) sigma[i][j] = -1;
    repd(i, S.size()) {
        rep(j, 26) sigma[i][j] = sigma[i + 1][j];
        sigma[i][S[i] - 'a'] = i;
    }

    modint998244353 ans = 0;
    reps(b, 1, S.size()) {
        auto a = sigma[0][S[b] - 'a'];
        if (a >= b)
            continue;
        // dp[i][j]: S[a..i] == S[b..j] となる部分文字列の個数
        rep(i, 102) rep(j, 102) dp[i][j] = 0;
        dp[a][b] = 1;
        reps(i, a, b) reps(j, b, S.size()) {
            rep(c, 26) {
                auto si = sigma[i + 1][c];
                auto sj = sigma[j + 1][c];
                if (si != -1 && sj != -1 && si < b) {
                    dp[si][sj] += dp[i][j];
                }
            }
        }
        // sigma[i+1][S[b]] == b でなければならない
        reps(i, a, b) {
            if (sigma[i + 1][S[b] - 'a'] != b)
                continue;
            reps(j, b, S.size()) {
                ans += dp[i][j];
            }
        }
    }

    print(ans.val());

    return 0;
}