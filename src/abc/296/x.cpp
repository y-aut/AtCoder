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
using vd = vector<double>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvb = vector<vb>;
using vpii = vector<pii>;
using vpll = vector<pll>;
// unordered set
using usi = unordered_set<int>;
using usll = unordered_set<ll>;
using uss = unordered_set<string>;

/* define short */
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define um unordered_map
#define us unordered_set
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<'\n';}else{cout<<"NO"<<'\n';}
#define yesno(bool) if(bool){cout<<"yes"<<'\n';}else{cout<<"no"<<'\n';}
#define YesNo(bool) if(bool){cout<<"Yes"<<'\n';}else{cout<<"No"<<'\n';}
#define CSI constexpr static int
#define CSLL constexpr static ll
#define CSLD constexpr static ld
#define INVAR(type, ...) type __VA_ARGS__; set_vars(__VA_ARGS__)
#define ININT(...) INVAR(int, __VA_ARGS__)
#define INLL(...) INVAR(ll, __VA_ARGS__)

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); i++)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i, n) for (ll i = n - 1; i >= 0; i--)
#define rrepd(i, n) for (ll i = n; i >= 1; i--)
#define repi(a, v) for (auto&& a : (v))

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << '\n';

/* func */
inline int in_int() {int x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline double in_double() {double x; cin >> x; return x;}
inline pii in_pii() {pii x; cin >> x.first >> x.second; return x;}
inline pll in_pll() {pll x; cin >> x.first >> x.second; return x;}
inline char in_char() {char c; cin >> c; return c;}
inline string in_str() {string x; cin >> x; return x;}
inline vi in_vi(int length) {vi res; rep(i, length) res.pb(in_int()); return res;}
inline vll in_vll(int length) {vll res; rep(i, length) res.pb(in_ll()); return res;}
inline vd in_vd(int length) {vd res; rep(i, length) res.pb(in_double()); return res;}
inline vc in_vc(int length) {vc res; rep(i, length) res.pb(in_char()); return res;}
inline vs in_vs(int height) {vs res; rep(i, height) res.pb(in_str()); return res;}
inline vvi in_vvi(int width, int height)
    {vvi res; rep(i, height) {vi tmp; rep(j, width) tmp.pb(in_int()); res.pb(tmp);} return res;}
inline vvll in_vvll(int width, int height)
    {vvll res; rep(i, height) {vll tmp; rep(j, width) tmp.pb(in_ll()); res.pb(tmp);} return res;}
inline vpii in_vpii(int height)
    {vpii res; rep(i, height) {pii tmp; tmp.first = in_int(); tmp.second = in_int(); res.pb(tmp);} return res;}
inline vpll in_vpll(int height)
    {vpll res; rep(i, height) {pll tmp; tmp.first = in_ll(); tmp.second = in_ll(); res.pb(tmp);} return res;}
template <bool bidir> inline vvll in_edges(int N, int height)
    {vvll res(N, vll());
    rep(i, height) {ll a = in_ll()-1; ll b = in_ll()-1; res[a].pb(b); if (bidir) res[b].pb(a);} return res;}
template <bool bidir> inline vector<usll> in_edges_us(int N, int height)
    {vector<usll> res(N, usll());
    rep(i, height) {ll a = in_ll()-1; ll b = in_ll()-1; res[a].insert(b); if (bidir) res[b].insert(a);} return res;}
inline void set_vars() {}
template <typename First, typename... Rest> inline void set_vars(First& first, Rest&... rest)
    {cin >> first; set_vars(rest...);}
inline int ctoi(char c) {return c - '0';}
template <typename T> inline void print(const vector<T>& v, string s = " ")
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : ""); cout << '\n';}
template <typename T, typename S> inline void print(const pair<T, S>& p)
    {cout << p.first << " " << p.second << '\n';}
template <typename T> inline void print(const T& x) {cout << x << '\n';}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v)
    {for (auto&& p : v) print(p);}
template <typename T, typename S> inline void print(const map<T, S>& m)
    {for (auto&& p : m) print(p);}
template <int V> inline void print(const static_modint<V> v) {print(v.val());}
inline void print(const modint v) {print(v.val());}
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare; if ((compare = a > b)) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare; if ((compare = a < b)) a = b; return compare;}
// デバッグ用関数
template <typename T> void dprint(const vector<T> &v) {
    rep(i, v.size()) {cout << "[" << i << "]: "; print(v[i]); cout << flush;}
}
template <typename T> void dprint(const vector<vector<T>> &v) {
    rep(i, v.size()) rep(j, v[i].size()) {cout << "[" << i << "][" << j << "]: "; print(v[i][j]); cout << flush;}
}
template<typename T> void dprint(const T v[], const int size) {
    rep(i, size) {cout << "[" << i << "]: "; print(v[i]); cout << flush;}
}
template <typename T> void dprint(const T v[], const int W, const int H) {
    rep(i, W) rep(j, H) {cout << "[" << i << "][" << j << "]: "; print(v[i][j]); cout << flush;}
}

/* constants */
CSLL MOD = 1000000007;
CSLL MOD2 = 998244353;
CSLL LINF = (1LL << 60);
CSI INF = 1000000006;
CSLD EPS = 1e-10;
CSLD PHI = 1.6180339887498948;

using mint = int;
using vm = vector<mint>;
using vvm = vector<vm>;

// clang-format on

// 隣接するグループを統合
void merge_groups(vi &groups) {
    bool flg;
    do {
        flg = false;
        rep(i, groups.size()) {
            reps(j, i + 1, groups.size()) {
                if (groups[i] & (groups[j] << 1 | groups[j] >> 1)) {
                    groups[i] |= groups[j];
                    groups.erase(groups.begin() + j);
                    flg = true;
                    break;
                }
            }
        }
    } while (flg);
}

// 隣接するビットをグループに分ける
void add_groups(int bb, vi &ans) {
    bool flg = false;
    for (int mask = 1; bb; mask <<= 1) {
        if (bb & mask) {
            bb ^= mask;
            if (!flg) {
                ans.pb(mask);
                flg = true;
            } else {
                ans.back() |= mask;
            }
        } else {
            flg = false;
        }
    }
}

int pack_groups(const ll M, const vi &groups) {
    int ans = 0;
    repi(i, groups) ans = (ans << M) | i;
    return ans;
}

vi unpack_groups(const ll M, int group) {
    vi ans;
    for (int i = 0, mask = (1 << M) - 1; i < 4; i++, group >>= M) {
        auto tmp = group & mask;
        if (tmp) {
            ans.pb(tmp);
        }
    }
    return ans;
}

// 現在のマスが bb で，上のマスの group が M bits * 4 で各グループの bb を表している
vvi calc(const ll M, int bb, int group) {
    vvi res;

    // { group, cost }
    if (bb == 0 && group == 0) {
        res.pb({0, 0});
        return res;
    }

    auto groups = unpack_groups(M, group);
    int empty = ~bb & ((1 << M) - 1);

    for (int i = empty;; i = (i - 1) & empty) {
        // i を加える
        int target = bb | i;
        int cnt = __builtin_popcount(target ^ bb);

        int target_c = target;
        vi groups_new;

        bool flg = false;
        repi(g, groups) {
            auto tmp = target_c & g;
            if (tmp) {
                target_c ^= tmp;
                groups_new.pb(tmp);
            } else {
                // 引き継いでいないグループがあってはならない
                flg = true;
                break;
            }
        }
        if (!flg) {
            add_groups(target_c, groups_new);
            // 隣接するグループがあれば統合
            merge_groups(groups_new);

            int group_new = pack_groups(M, groups_new);

            res.pb({group_new, cnt});
        }

        if (i == 0) break;
    }
    return res;
}

int main() {
    INLL(N, M);
    auto S = in_vs(N);

    while (S.back().find('#') == string::npos) {
        S.pop_back();
        N--;
    }

    // dp[group]: min score
    um<int, int> dp;
    dp[0] = 0;

    rep(i, N) {
        um<int, int> nxt;
        int bb = 0;
        rep(j, M) {
            if (S[i][j] == '#') {
                bb ^= 1 << j;
            }
        }
        repi(g, dp) {
            vvi mvs = calc(M, bb, g.first);
            repi(m, mvs) {
                if (nxt.count(m[0])) {
                    chmin(nxt[m[0]], g.second + m[1]);
                } else {
                    nxt[m[0]] = g.second + m[1];
                }
            }
        }
        dp = move(nxt);
    }

    int ans = INF;
    // グループ数が 1 のもののみ
    rep(i, 1 << M) {
        if (dp.count(i))
            chmin(ans, dp[i]);
    }
    print(ans);

    return 0;
}
