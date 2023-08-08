#pragma once

#ifndef TEMPLATE_H
#include "template.cpp"
#endif

#define debug(...) dprint(__LINE__, HEAD_NAME(__VA_ARGS__), __VA_ARGS__)

inline string to_str(const string &v) { return v; }

template <typename T>
inline string to_str(const T &v) { return to_string(v); }

template <typename T>
inline void dprint(ll line, string name, const T &v);
template <typename T>
inline void dprint(ll line, string name, const vector<T> &v);
template <typename T>
inline void dprint(ll line, string name, const set<T> &v);
template <typename T>
inline void dprint(ll line, string name, const us<T> &v);
template <typename T, typename S>
inline void dprint(ll line, string name, const map<T, S> &v);
template <typename T, typename S>
inline void dprint(ll line, string name, const um<T, S> &v);

template <typename T>
inline void dprint(ll line, string name, const T &v) {
    cout << "\033[33m(line:" << line << ") " << name << ": ";
    print(v);
    cout << "\033[m" << flush;
}

template <typename T>
inline void dprint(ll line, string name, const vector<T> &v) {
    if (v.empty()) dprint(line, name, "empty");
    else rep(i, v.size()) dprint(line, name + "[" + to_str(i) + "]", v[i]);
}

template <typename T>
inline void dprint(ll line, string name, const set<T> &v) {
    if (v.empty()) dprint(line, name, "empty");
    else {
        ll idx = 0;
        repi(i, v) dprint(line, name + "[" + to_str(idx++) + "]", i);
    }
}

template <typename T>
inline void dprint(ll line, string name, const us<T> &v) {
    if (v.empty()) dprint(line, name, "empty");
    else {
        ll idx = 0;
        repi(i, v) dprint(line, name + "[" + to_str(idx++) + "]", i);
    }
}

template <typename T, typename S>
inline void dprint(ll line, string name, const map<T, S> &v) {
    if (v.empty()) dprint(line, name, "empty");
    else repi(i, v) dprint(line, name + "[" + to_str(i.first) + "]", i.second);
}

template <typename T, typename S>
inline void dprint(ll line, string name, const um<T, S> &v) {
    if (v.empty()) dprint(line, name, "empty");
    else repi(i, v) dprint(line, name + "[" + to_str(i.first) + "]", i.second);
}

template <typename T, typename... Rest>
inline void dprint(ll line, string name, const T v, ll size, Rest... rest) {
    rep(i, size) dprint(line, name + "[" + to_str(i) + "]", v[i], rest...);
}
