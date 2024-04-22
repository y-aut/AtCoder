#ifndef TEMPLATE_H
#include "template.hpp"
#endif

vs split(const string &s, char delim) {
    vs elems;
    string item;
    repi(c, s) {
        if (c == delim) {
            elems.pb(item);
            item.clear();
        } else {
            item += c;
        }
    }
    elems.pb(item);
    return elems;
}

vi parse_vi(const string &s) {
    vi ans;
    repi(i, split(s.substr(1, s.size() - 2), ',')) {
        ans.pb(stoi(i));
    }
    return ans;
}
