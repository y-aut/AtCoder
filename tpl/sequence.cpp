#include "./template.cpp"

// --------------------- ここからコピー ---------------------
#pragma region 最長増加部分列

class LIS {
    vll v;
    // lis[i]: v[0] ~ v[i] の LIS の長さ
    vll len;

    void set_len() {
        vll tmp;
        repi(a, v) {
            auto itr = lower_bound(all(tmp), a);
            auto cnt = distance(tmp.begin(), itr);
            if (cnt == tmp.size()) {
                tmp.pb(a);
            } else {
                tmp[cnt] = a;
            }
            len.pb(tmp.size());
        }
    }

public:
    LIS(vll &_v) {
        v = _v;
        set_len();
    }

    ll get_length(ll i) { return len[i]; }
};

#pragma endregion
