#pragma once

#ifndef TEMPLATE_H
#include "template.hpp"
#endif

#define debug(...) dprint(__LINE__, HEAD_NAME(__VA_ARGS__), __VA_ARGS__)

TPL_T
inline string to_str(const T &v) { return to_string(v); }
template <>
inline string to_str(const string &v) { return v; }
TPL_TS
inline string to_str(const pair<T, S> &v) { return to_str(v.first) + "," + to_str(v.second); }

TPL_T
inline void dprint(ll line, string name, const T &v);
TPL_T
inline void dprint(ll line, string name, const v<T> &v);
template <typename T, size_t N>
inline void dprint(ll line, string name, const array<T, N> &v);
TPL_TSU
inline void dprint(ll line, string name, const set<T, S, U> &v);
TPL_TSUV
inline void dprint(ll line, string name, const us<T, S, U, V> &v);
TPL_TSUV
inline void dprint(ll line, string name, const map<T, S, U, V> &v);
TPL_TSUVW
inline void dprint(ll line, string name, const um<T, S, U, V, W> &v);
TPL_T
inline void dprint(ll line, string name, const fenwick_tree<T> &v, ll n);
template <class S, auto op, auto e>
inline void dprint(ll line, string name, const segtree<S, op, e> &v, ll n);
template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
inline void dprint(ll line, string name, lazy_segtree<S, op, e, F, mapping, composition, id> &v, ll n);

TPL_T
inline void dprint(ll line, string name, const T &v) {
    cout << "\033[33m(line:" << line << ") " << name << ": ";
    print(v);
    cout << "\033[m" << flush;
}

TPL_T
inline void dprint(ll line, string name, const v<T> &v) {
    if (v.empty()) dprint(line, name, "empty");
    else rep(i, v.size()) dprint(line, name + "[" + to_str(i) + "]", v[i]);
}

template <typename T, size_t N>
inline void dprint(ll line, string name, const array<T, N> &v) {
    if (v.empty()) dprint(line, name, "empty");
    else rep(i, N) dprint(line, name + "[" + to_str(i) + "]", v[i]);
}

TPL_TSU
inline void dprint(ll line, string name, const set<T, S, U> &v) {
    if (v.empty()) dprint(line, name, "empty");
    else {
        ll idx = 0;
        repi(i, v) dprint(line, name + "[" + to_str(idx++) + "]", i);
    }
}

TPL_TSUV
inline void dprint(ll line, string name, const us<T, S, U, V> &v) {
    if (v.empty()) dprint(line, name, "empty");
    else {
        ll idx = 0;
        repi(i, v) dprint(line, name + "[" + to_str(idx++) + "]", i);
    }
}

TPL_TSUV
inline void dprint(ll line, string name, const map<T, S, U, V> &v) {
    if (v.empty()) dprint(line, name, "empty");
    else repi(i, v) dprint(line, name + "[" + to_str(i.first) + "]", i.second);
}

TPL_TSUVW
inline void dprint(ll line, string name, const um<T, S, U, V, W> &v) {
    if (v.empty()) dprint(line, name, "empty");
    else repi(i, v) dprint(line, name + "[" + to_str(i.first) + "]", i.second);
}

TPL_T
inline void dprint(ll line, string name, fenwick_tree<T> &v, ll n) {
    v<T> vc;
    rep(i, n) vc.pb(v.sum(i, i + 1));
    dprint(line, name, vc);
}

template <class S, auto op, auto e>
inline void dprint(ll line, string name, const segtree<S, op, e> &v, ll n) {
    v<S> vc;
    rep(i, n) vc.pb(v.get(i));
    dprint(line, name, vc);
}

template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
inline void dprint(ll line, string name, lazy_segtree<S, op, e, F, mapping, composition, id> &v, ll n) {
    v<S> vc;
    rep(i, n) vc.pb(v.get(i));
    dprint(line, name, vc);
}

template <typename T, typename... Rest>
inline void dprint(ll line, string name, const T v, ll size, Rest... rest) {
    rep(i, size) dprint(line, name + "[" + to_str(i) + "]", v[i], rest...);
}
