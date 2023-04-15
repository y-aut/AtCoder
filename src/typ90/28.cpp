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

class SegmentAdd
{
    ll size;
    vll data;

    void add_impl(const ll l, const ll r, const ll val, ll k, ll data_l, ll data_r) { 
        // k: 現在見ているノードの位置
        // [data_l, data_r): data[k] が表している区間
        if (data_r <= l || r <= data_l) { // 範囲外なら考えない
            return;
        } else if (l <= data_l && data_r <= r) { // 範囲内なので加算
            data[k] += val;
        } else { // 一部区間が被る時
            add_impl(l, r, val, k * 2 + 1, data_l, (data_l + data_r) / 2);
            add_impl(l, r, val, k * 2 + 2, (data_l + data_r) / 2, data_r);
        }
    }

    // 最上位ビットのみを残した値を取得
    ull bits_msb(ull v)
    {
        v = v | (v >>  1);
        v = v | (v >>  2);
        v = v | (v >>  4);
        v = v | (v >>  8);
        v = v | (v >> 16);
        v = v | (v >> 32);
        return v ^ (v >> 1);
    }
    
public:
    SegmentAdd(const ll _size) {
        size = bits_msb(_size);
        if (size < _size) size <<= 1;
        data = vll(size * 2 - 1, 0);
    }

    // [l, r) の地点を val だけ加算
    void add(const ll l, const ll r, const ll val) {
        add_impl(l, r, val, 0, 0, size);
    }

    // i の地点の値を取得
    ll get(const ll i) {
        ll tmp = i + size - 1;
        ll ans = data[tmp];
        while (tmp > 0) {
            tmp = (tmp - 1) / 2;
            ans += data[tmp];
        }
        return ans;
    }
};

int main()
{
    auto N = in_ll();
    auto pos = in_vvll(4, N);

    int tiles[1002][1002] = {};
    for (auto p : pos) {
        tiles[p[0]][p[1]]++;
        tiles[p[2]][p[3]]++;
        tiles[p[0]][p[3]]--;
        tiles[p[2]][p[1]]--;
    }

    rep(i, 1002) {
        rep(j, 1001) {
            tiles[j+1][i] += tiles[j][i];
        }
    }
    rep(i, 1002) {
        rep(j, 1001) {
            tiles[i][j+1] += tiles[i][j];
        }
    }

    vi sum = vi(N, 0);
    rep(i, 1001) {
        rep(j, 1001) {
            if (tiles[i][j] != 0) {
                sum[tiles[i][j] - 1]++;
            }
        }
    }

    for (auto s : sum) print(s);

    return 0;
}