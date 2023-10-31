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
#define YESNO(bool) if(bool){cout<<"YES"<<'\n';}else{cout<<"NO"<<'\n';}
#define yesno(bool) if(bool){cout<<"yes"<<'\n';}else{cout<<"no"<<'\n';}
#define YesNo(bool) if(bool){cout<<"Yes"<<'\n';}else{cout<<"No"<<'\n';}
#define CSI constexpr static int
#define CSLL constexpr static ll
#define CSLD constexpr static ld

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
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : ""); cout << '\n';}
inline void print1(const vll& v, string s = " ")
    {rep(i, v.size()) cout << (v[i] + 1) << (i != (ll)v.size() - 1 ? s : ""); cout << '\n';}
template <typename T, typename S> inline void print(const pair<T, S>& p)
    {cout << p.first << " " << p.second << '\n';}
template <typename T> inline void print(const T& x) {cout << x << '\n';}
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

bool is_dag_impl(vvll &edges, ll v, vi &status) {
    status[v] = 1;
    repi(i, edges[v]) {
        if (status[i] == 1)
            return false;
        else if (status[i] == 0 && !is_dag_impl(edges, i, status))
            return false;
    }
    status[v] = 2;
    return true;
}

bool is_dag(vvll &edges) {
    auto status = vi(edges.size(), 0);
    rep(i, edges.size()) {
        if (status[i] == 0 && !is_dag_impl(edges, i, status))
            return false;
    }
    return true;
}

vll topo_sort(um<ll, usll> &edges) {
    vll ans;
    um<ll, ll> in_deg;
    repi(i, edges) in_deg[i.first] = 0;

    // 入次数をカウント
    repi(i, edges) repi(j, i.second) in_deg[j]++;

    queue<ll> q;
    repi(i, in_deg) {
        if (i.second == 0) {
            q.push(i.first);
        }
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        repi(i, edges[v]) {
            if (--in_deg[i] == 0)
                q.push(i);
        }
        ans.pb(v);
    }

    return ans;
}

void impl(vvll &edges, vll &in_deg, usll &in_deg_0, ll K, vll &ans, vvll &anses) {
    if (anses.size() == K)
        return;
    if (in_deg_0.empty()) {
        anses.emplace_back(ans);
        return;
    }
    auto in_deg_0_cpy = in_deg_0;
    repi(v, in_deg_0_cpy) {
        in_deg_0.erase(v);
        repi(i, edges[v]) {
            if (--in_deg[i] == 0) {
                in_deg_0.insert(i);
            }
        }
        ans.pb(v);
        impl(edges, in_deg, in_deg_0, K, ans, anses);
        ans.pop_back();
        repi(i, edges[v]) {
            ++in_deg[i];
            in_deg_0.erase(i);
        }
        in_deg_0.insert(v);
    }
}

int main() {
    auto N = in_ll();
    auto M = in_ll();
    auto K = in_ll();
    auto AB = in_vpll(M);
    repi(ab, AB) {
        ab.first--;
        ab.second--;
    }

    auto edges = vvll();
    rep(i, N) edges.pb(vll());
    repi(ab, AB) edges[ab.first].pb(ab.second);

    if (!is_dag(edges)) {
        print("-1");
        return 0;
    }

    if (N <= 10) {
        auto ary = vll();
        rep(i, N) ary.pb(i);
        auto ans = vvll();
        int cnt = 0;
        do {
            bool flg = true;
            repi(ab, AB) {
                if (ary[ab.first] >= ary[ab.second]) {
                    flg = false;
                    break;
                }
            }
            if (flg) {
                auto tmp = vll(N);
                rep(i, N) tmp[ary[i]] = i;
                ans.pb(tmp);
                if (++cnt == K) {
                    break;
                }
            }
        } while (next_permutation(all(ary)));
        if (cnt == K) {
            repi(i, ans) print1(i);
        } else {
            print(-1);
        }
        return 0;
    }

    dsu uf(N);
    repi(ab, AB) {
        uf.merge(ab.first, ab.second);
    }

    vector<ll> group_num(N, 0);
    vector<um<ll, usll>> group_edges;
    if (uf.size(0) != N) {
        auto groups = uf.groups();
        rep(i, groups.size()) {
            repi(j, groups[i]) group_num[j] = i;
        }
        group_edges.resize(groups.size());
    } else {
        group_edges.resize(1);
    }

    rep(i, group_edges.size()) group_edges[i] = um<ll, usll>();
    rep(i, N) group_edges[group_num[i]][i] = usll();
    repi(ab, AB) group_edges[group_num[ab.first]][ab.first].insert(ab.second);

    vvll groups;
    repi(i, group_edges) groups.pb(topo_sort(i));

    sort(all(groups), [](vll &a, vll &b) { return a.size() > b.size(); });
    if (groups.size() == 2) {
        if (groups[0].size() >= 9) {
            rep(i, K) {
                vll ans;
                ll idx = 0;
                rep(j, groups[0].size() + 1) {
                    if (j == i) {
                        repi(k, groups[1]) ans.pb(k);
                    } else {
                        ans.pb(groups[0][idx++]);
                    }
                }
                print1(ans);
            }
        } else {
            rep(i, K) {
                vll ans;
                ll fir, sec;
                if (i <= 3) {
                    fir = 0;
                    sec = i + 1;
                } else if (i <= 6) {
                    fir = 1;
                    sec = i - 2;
                } else if (i <= 8) {
                    fir = 2;
                    sec = i - 4;
                } else {
                    fir = 3;
                    sec = 4;
                }
                rep(j, groups[0].size()) {
                    if (j == fir) {
                        ans.pb(groups[1][0]);
                    } else if (j == sec) {
                        reps(k, 1, groups[1].size()) ans.pb(groups[1][k]);
                    }
                    ans.pb(groups[0][j]);
                }
                print1(ans);
            }
        }
    } else if (groups.size() == 3) {
        rep(i, K) {
            vll ans;
            ll fir, sec;
            if (i <= 3) {
                fir = 0;
                sec = i + 1;
            } else if (i <= 6) {
                fir = 1;
                sec = i - 2;
            } else if (i <= 8) {
                fir = 2;
                sec = i - 4;
            } else {
                fir = 3;
                sec = 4;
            }
            rep(j, groups[0].size()) {
                if (j == fir) {
                    ans.pb(groups[1][0]);
                } else if (j == sec) {
                    reps(k, 1, groups[1].size()) ans.pb(groups[1][k]);
                }
                ans.pb(groups[0][j]);
            }
            if (sec == groups[0].size()) {
                reps(k, 1, groups[1].size()) ans.pb(groups[1][k]);
            }
            print1(ans);
        }
    } else if (groups.size() >= 4) {
        vi gis = {0, 1, 2, 3};
        rep(i, K) {
            vll ans;
            repi(j, gis) {
                if (j == 3) {
                    reps(k, 3, groups.size()) repi(l, groups[k]) ans.pb(l);
                } else {
                    repi(k, groups[j]) ans.pb(k);
                }
            }
            print1(ans);
            next_permutation(all(gis));
        }
    } else {
        auto in_deg = vll(N, 0);
        repi(i, edges) repi(j, i) in_deg[j]++;
        auto in_deg_0 = usll();
        rep(i, N) if (in_deg[i] == 0) in_deg_0.insert(i);
        vll ans;
        vvll anses;
        impl(edges, in_deg, in_deg_0, K, ans, anses);
        if (anses.size() == K) {
            repi(i, anses) print1(i);
        } else {
            print(-1);
        }
    }

    return 0;
}