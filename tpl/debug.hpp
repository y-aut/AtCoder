#pragma once

#ifndef TEMPLATE_H
#include "template.cpp"
#endif

#define debug(...) dprint(__LINE__, HEAD_NAME(__VA_ARGS__), __VA_ARGS__)

template <typename T>
inline void dprint(ll line, string name, const T &v) {
    cout << "\033[33m(line:" << line << ") " << name << ": ";
    print(v);
    cout << "\033[m" << flush;
}

template <typename T>
inline void dprint(ll line, string name, const vector<T> &v) {
    rep(i, v.size()) dprint(line, name + "[" + to_string(i) + "]", v[i]);
}

template <typename T, typename S>
inline void dprint(ll line, string name, const map<T, S> &v) {
    repi(i, v) dprint(line, name + "[" + to_string(i.first) + "]", i.second);
}

template <typename T, typename S>
inline void dprint(ll line, string name, const um<T, S> &v) {
    repi(i, v) dprint(line, name + "[" + to_string(i.first) + "]", i.second);
}

template <typename T, typename... Rest>
inline void dprint(ll line, string name, const T v, ll size, Rest... rest) {
    rep(i, size) dprint(line, name + "[" + to_string(i) + "]", v[i], rest...);
}
