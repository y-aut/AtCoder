#ifndef TEMPLATE_H
#include "template.hpp"
#endif

pair<string, string> parenthesis{"({[", ")}]"};

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

// 括弧を考慮する
vs split_with_parenthesis(const string &s, char delim) {
    vs elems;
    string item;
    stack<size_t> par;
    repi(c, s) {
        auto pos = parenthesis.first.find(c);
        if (pos != string::npos) {
            par.push(pos);
        } else {
            pos = parenthesis.second.find(c);
            if (pos != string::npos) {
                assert(!par.empty() && pos == par.top());
                par.pop();
            }
        }

        if (par.empty() && c == delim) {
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

vvi parse_vvi(const string &s) {
    vvi ans;
    repi(i, split_with_parenthesis(s.substr(1, s.size() - 2), ',')) {
        ans.pb(vi());
        repi(j, split(i.substr(1, i.size() - 2), ',')) {
            ans.back().pb(stoi(j));
        }
    }
    return ans;
}
