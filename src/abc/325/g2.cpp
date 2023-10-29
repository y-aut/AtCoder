#include <bits/stdc++.h>
namespace {
#pragma GCC diagnostic ignored "-Wunused-function"
#include <atcoder/all>
#pragma GCC diagnostic warning "-Wunused-function"
    using namespace std;
    using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
    template <class T>
    bool chmax(T &a, const T &b) {
        if (a < b) {
            a = b;
            return true;
        } else return false;
    }
    template <class T>
    bool chmin(T &a, const T &b) {
        if (b < a) {
            a = b;
            return true;
        } else return false;
    }
    using ll = long long;
    using P = pair<int, int>;
    using VI = vector<int>;
    using VVI = vector<VI>;
    using VL = vector<ll>;
    using VVL = vector<VL>;

    bool can_delete[310][310];
    int dp[310];

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    reverse(all(s));
    int k;
    cin >> k;
    int n = s.size();
    for (int l = n - 1; l >= 0; l--)
        if (s[l] == 'f') {
            dp[l + 1] = 0;
            for (int r = l + 1; r < n; r++) {
                dp[r + 1] = dp[r] + 1;
                if (s[r] == 'o') {
                    if (dp[r] == 0) can_delete[l][r] = true;
                    for (int i = l + 1; i < r; i++)
                        if (can_delete[i][r]) {
                            chmin(dp[r + 1], max(0, dp[i] - k));
                        }
                }
            }
        }
    dp[0] = 0;
    for (int r = 0; r < n; r++) {
        dp[r + 1] = dp[r] + 1;
        if (s[r] == 'o') {
            for (int i = 0; i < r; i++)
                if (can_delete[i][r]) {
                    chmin(dp[r + 1], max(0, dp[i] - k));
                }
        }
    }
    cout << dp[n] << '\n';
}