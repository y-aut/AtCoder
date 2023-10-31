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
inline char in_char() {char c; cin >> c; return c;}
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

CSI MAX_SIZE = 25;

inline int get_index(int r, int c, int W) {
    return r * W + c;
}

inline bool is_placable(int n, int board, int W) {
    int c = n % W;
    if (c == 0) {
        return (board & 0b110) == 0;
    }
    if (c == W-1) {
        return (board & (1 << W | 0b11)) == 0;
    }
    return (board & (1 << W | 0b111)) == 0;
}

int fib[MAX_SIZE] = {2,3};
int trans[MAX_SIZE][250000][2] = {};
modint1000000007 dp[MAX_SIZE*MAX_SIZE][250000] = {};

int array_to_fib(int n, int array) {
    if (n <= 2) {
        return array;
    }
    if ((array >> (n-1)) == 0) {
        return array_to_fib(n-1, array);
    }
    else {
        return array_to_fib(n-2, array & ((1 << (n-1)) - 1)) + fib[n-2];
    }
}

int fib_to_array(int n, int num) {
    if (n <= 2) {
        return num;
    }
    if (num >= fib[n-2]) {
        return 1 << (n-1) | fib_to_array(n-2, num-fib[n-2]);
    }
    else {
        return fib_to_array(n-1, num);
    }
}

int board_to_fib(int col, int board, int W) {
    // col==0: (1,W)
    // col==1: (W,1)
    // col==n: (W+1-n,n)
    int lower = col == 0 ? W : col;
    int upper = W + 1 - lower;
    int lowerboard = board >> upper;
    int upperboard = board & ((1 << upper) - 1);
    return array_to_fib(upper, upperboard) * fib[lower-1] + array_to_fib(lower, lowerboard);
}

int fib_to_board(int col, int num, int W) {
    int lower = col == 0 ? W : col;
    int upper = W + 1 - lower;
    int upperfib = num / fib[lower-1];
    int lowerfib = num % fib[lower-1];
    return fib_to_array(lower, lowerfib) << upper | fib_to_array(upper, upperfib);
}

inline int fib_max(int col, int W) {
    int lower = col == 0 ? W : col;
    int upper = W + 1 - lower;
    return fib[upper-1] * fib[lower-1];
}

int main()
{
    // フィボナッチ数 fib[n]: 長さ n+1 の 01 文字列で，1 が連続しないもの
    reps(i, 2, MAX_SIZE) fib[i] = fib[i-1] + fib[i-2];

    auto H = in_int();
    auto W = in_int();
    
    set<int> whites{};
    rep(i, H) {
        rep(j, W) {
            if (in_char() == '.')
                whites.insert(get_index(i, j, W));
        }
    }

    // 遷移を計算
    rep(c, W) {
        rep(i, fib_max(c, W)) {
            auto board = fib_to_board(c, i, W);
            trans[c][i][0] = board_to_fib((c+1) % W, board >> 1, W);
            trans[c][i][1] = board_to_fib((c+1) % W, board >> 1 | 1 << W, W);
        }
    }
    
    dp[*whites.begin()][board_to_fib(*whites.begin() % W, 0, W)] = 1;
    reps(i, *whites.begin(), H*W) {
        rep(j, fib_max(i % W, W)) {
            dp[i+1][trans[i % W][j][0]] += dp[i][j];
            if (whites.find(i) != whites.end() && is_placable(i, fib_to_board(i % W, j, W), W))
                dp[i+1][trans[i % W][j][1]] += dp[i][j];
        }
    }

    // rep(i, H*W) rep(j, fib_max(i % W, W)) {
    //     cout << "dp[" << i << "][" << j << "]: " << dp[i][j].val() << endl;
    //     cout << "col: " << i % W << ", board: " << bitset<25>(fib_to_board(i % W, j, W)) << endl;
    // }
    
    modint1000000007 ans = 0;
    rep(j, fib_max(0, W)) {
        ans += dp[H*W][j];
    }
    print(ans.val());

    return 0;
}