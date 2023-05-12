#include <bits/stdc++.h>
using namespace std;
long n, q, p, x[400010], y[400010], i = 1, a, b, t, k;
double px, py, d[400010];
main() {
    cin >> n;
    for (; i <= n; i++) cin >> x[i] >> y[i], x[i + n] = x[i], y[i + n] = y[i];
    px = accumulate(x + 1, x + 1 + n, 0.L) / n, py = accumulate(y + 1, y + 1 + n, 0.L) / n;
    for (i = 1; i <= n; i++) {
        d[i] = d[i + n] = atan2(y[i] - py, x[i] - px);
        if (d[i] < d[p]) p = i;
    }
    cin >> q;
    while (q--) {
        cin >> a >> b, t = lower_bound(d + p, d + p + n, atan2(b - py, a - px)) - d;
        k = (x[t] - x[t - 1]) * (b - y[t - 1]) - (y[t] - y[t - 1]) * (a - x[t - 1]);
        cout << (k < 0 ? "OUT\n" : k > 0 ? "IN\n" :
                                           "ON\n");
    }
}