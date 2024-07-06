#pragma once

#ifndef TEMPLATE_H
#include "template.hpp"
#endif

#define OVERLOAD9(_1, _2, _3, _4, _5, _6, _7, _8, x, ...) x

#define MACRO_MAP_1(f, _1) f(_1);
#define MACRO_MAP_2(f, _1, _2) MACRO_MAP_1(f, _1) MACRO_MAP_1(f, _2)
#define MACRO_MAP_3(f, _1, _2, _3) MACRO_MAP_1(f, _1) MACRO_MAP_2(f, _2, _3)
#define MACRO_MAP_4(f, _1, _2, _3, _4) MACRO_MAP_1(f, _1) MACRO_MAP_3(f, _2, _3, _4)
#define MACRO_MAP_5(f, _1, _2, _3, _4, _5) MACRO_MAP_1(f, _1) MACRO_MAP_4(f, _2, _3, _4, _5)
#define MACRO_MAP_6(f, _1, _2, _3, _4, _5, _6) MACRO_MAP_1(f, _1) MACRO_MAP_5(f, _2, _3, _4, _5, _6)
#define MACRO_MAP_7(f, _1, _2, _3, _4, _5, _6, _7) MACRO_MAP_1(f, _1) MACRO_MAP_6(f, _2, _3, _4, _5, _6, _7)
#define MACRO_MAP_8(f, _1, _2, _3, _4, _5, _6, _7, _8) MACRO_MAP_1(f, _1) MACRO_MAP_7(f, _2, _3, _4, _5, _6, _7, _8)

#define MACRO_MAP(f, ...) OVERLOAD9(__VA_ARGS__, MACRO_MAP_8, MACRO_MAP_7, MACRO_MAP_6, MACRO_MAP_5, MACRO_MAP_4, \
                                    MACRO_MAP_3, MACRO_MAP_2, MACRO_MAP_1)(f, __VA_ARGS__)

#define debug(...) dprint(__LINE__, HEAD_NAME(__VA_ARGS__), __VA_ARGS__)
#define debugs(...) \
    { MACRO_MAP(debug, __VA_ARGS__) }

TPL_T
inline string to_str(const T &val) { return to_string(val); }
template <>
inline string to_str(const string &val) { return val; }
TPL_TS
inline string to_str(const pair<T, S> &val) { return to_str(val.first) + "," + to_str(val.second); }

TPL_T
inline void dprint_base(ll line, string name, const T &val);
TPL_T
inline void dprint(ll line, string name, const T &val);
TPL_T
inline void dprint(ll line, string name, const v<T> &val);
template <>
inline void dprint(ll line, string name, const vvll &val);
template <typename T, size_t N>
inline void dprint(ll line, string name, const array<T, N> &val);
TPL_TSU
inline void dprint(ll line, string name, const set<T, S, U> &val);
TPL_TSU
inline void dprint(ll line, string name, const multiset<T, S, U> &val);
TPL_TSUV
inline void dprint(ll line, string name, const us<T, S, U, V> &val);
TPL_TSUV
inline void dprint(ll line, string name, const map<T, S, U, V> &val);
TPL_TSUVW
inline void dprint(ll line, string name, const um<T, S, U, V, W> &val);
TPL_T
inline void dprint(ll line, string name, const fenwick_tree<T> &val, ll n);
template <class S, auto op, auto e>
inline void dprint(ll line, string name, const segtree<S, op, e> &val, ll n);
template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
inline void dprint(ll line, string name, lazy_segtree<S, op, e, F, mapping, composition, id> &val, ll n);

TPL_T
inline void dprint_base(ll line, string name, const T &val) {
    cout << "\033[33m(line:" << line << ") " << name << ": ";
    print(val);
    cout << "\033[m" << flush;
}

TPL_T
inline void dprint(ll line, string name, const T &val) {
    dprint_base(line, name, val);
}

TPL_T
inline void dprint(ll line, string name, const v<T> &val) {
    if (val.empty()) dprint(line, name, "empty");
    else rep(i, val.size()) dprint(line, name + "[" + to_str(i) + "]", val[i]);
}

template <>
inline void dprint(ll line, string name, const vvll &val) {
    if (val.empty()) dprint(line, name, "empty");
    else rep(i, val.size()) dprint_base(line, name + "[" + to_str(i) + "]", val[i]);
}

template <typename T, size_t N>
inline void dprint(ll line, string name, const array<T, N> &val) {
    if (val.empty()) dprint(line, name, "empty");
    else rep(i, N) dprint(line, name + "[" + to_str(i) + "]", val[i]);
}

TPL_TSU
inline void dprint(ll line, string name, const set<T, S, U> &val) {
    if (val.empty()) dprint(line, name, "empty");
    else {
        ll idx = 0;
        repi(i, val) dprint(line, name + "[" + to_str(idx++) + "]", i);
    }
}

TPL_TSU
inline void dprint(ll line, string name, const multiset<T, S, U> &val) {
    if (val.empty()) dprint(line, name, "empty");
    else {
        ll idx = 0;
        repi(i, val) dprint(line, name + "[" + to_str(idx++) + "]", i);
    }
}

TPL_TSUV
inline void dprint(ll line, string name, const us<T, S, U, V> &val) {
    if (val.empty()) dprint(line, name, "empty");
    else {
        ll idx = 0;
        repi(i, val) dprint(line, name + "[" + to_str(idx++) + "]", i);
    }
}

TPL_TSUV
inline void dprint(ll line, string name, const map<T, S, U, V> &val) {
    if (val.empty()) dprint(line, name, "empty");
    else repi(i, val) dprint(line, name + "[" + to_str(i.first) + "]", i.second);
}

TPL_TSUVW
inline void dprint(ll line, string name, const um<T, S, U, V, W> &val) {
    if (val.empty()) dprint(line, name, "empty");
    else repi(i, val) dprint(line, name + "[" + to_str(i.first) + "]", i.second);
}

TPL_T
inline void dprint(ll line, string name, fenwick_tree<T> &val, ll n) {
    v<T> vc;
    rep(i, n) vc.pb(val.sum(i, i + 1));
    dprint(line, name, vc);
}

template <class S, auto op, auto e>
inline void dprint(ll line, string name, const segtree<S, op, e> &val, ll n) {
    v<S> vc;
    rep(i, n) vc.pb(val.get(i));
    dprint(line, name, vc);
}

template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
inline void dprint(ll line, string name, lazy_segtree<S, op, e, F, mapping, composition, id> &val, ll n) {
    v<S> vc;
    rep(i, n) vc.pb(val.get(i));
    dprint(line, name, vc);
}

template <typename T, typename... Rest>
inline void dprint(ll line, string name, const T val, ll size, Rest... rest) {
    rep(i, size) dprint(line, name + "[" + to_str(i) + "]", val[i], rest...);
}
