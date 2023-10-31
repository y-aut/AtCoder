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
inline char in_char() {char c; cin >> c; return c;}
inline string in_str() {string x; cin >> x; return x;}
inline vi in_vi(int length) {vi res = vi(); rep(i, length) res.pb(in_int()); return res;}
inline vll in_vll(int length) {vll res = vll(); rep(i, length) res.pb(in_ll()); return res;}
inline vvi in_vvi(int width, int height)
    {vvi res = vvi(); rep(i, height) {vi tmp = vi(); rep(j, width) tmp.pb(in_int()); res.pb(tmp);} return res;}
inline vvll in_vvll(int width, int height)
    {vvll res = vvll(); rep(i, height) {vll tmp = vll(); rep(j, width) tmp.pb(in_ll()); res.pb(tmp);} return res;}
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

// clang-format on

#pragma region "多角形"

struct Polygon {
    ll size;
    // 時計回り or 反時計回り
    vpll points;

    // p1 -> p2 -> p3 が右曲がりか
    static bool is_ccw(pll &p1, pll &p2, pll &p3) {
        return (p2.first - p1.first) * (p3.second - p2.second) <=
               (p2.second - p1.second) * (p3.first - p2.first);
    }

public:
    Polygon(vpll &_points) {
        size = _points.size();
        points = _points;
    }

    ll get_size() { return size; }
    pll get_point(ll i) { return points[i]; }

    // 面積の2倍を求める
    ll get_area2() {
        ll ans = 0;
        rep(i, size) {
            ans += (points[i].first - points[(i + 1) % size].first) *
                   (points[i].second + points[(i + 1) % size].second);
        }
        return abs(ans);
    }

    // 凸包を求める
    static Polygon get_convex_hull(vpll &points) {
        sort(all(points), [](pll &a, pll &b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        auto q = deque<pll>();
        repi(p, points) {
            while (q.size() >= 2) {
                auto first = q.back();
                q.pop_back();
                auto second = q.back();
                if (!is_ccw(second, first, p)) {
                    q.push_back(first);
                    break;
                }
            }
            q.push_back(p);
        }
        ll lower_size = q.size();
        reps(i, 1, points.size()) {
            while (q.size() - lower_size >= 1) {
                auto first = q.front();
                q.pop_front();
                auto second = q.front();
                if (is_ccw(second, first, points[i])) {
                    q.push_front(first);
                    break;
                }
            }
            if (i != points.size() - 1)
                q.push_front(points[i]);
        }

        auto ans = vpll(all(q));
        return Polygon(ans);
    }
};

#pragma endregion

// 線分 a, b 上の格子点の数を求める
inline ll get_count(const pll &a, const pll &b) {
    auto cx = abs(a.first - b.first);
    auto cy = abs(a.second - b.second);
    if (cx == 0 || cy == 0)
        return cx + cy + 1;
    return gcd(cx, cy) + 1;
}

int main() {
    auto N = in_ll();
    auto XY = in_vpll(N);

    auto poly = Polygon::get_convex_hull(XY);

    ll b = 0;
    rep(i, poly.get_size()) {
        b += get_count(poly.get_point(i), poly.get_point((i + 1) % poly.get_size()));
    }
    b -= poly.get_size();

    ll ans = (poly.get_area2() + 2 - b) / 2 + b;
    print(ans - N);

    return 0;
}