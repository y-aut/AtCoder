// !hidden
#include "template.hpp"
// !endhidden

// 回分半径を取得する．ex) "abaaababa" -> [1,2,1,4,1,2,3,2,1]
template <typename RandomAccessIterator>
vll get_manacher(const RandomAccessIterator first, const RandomAccessIterator last) {
    ll i = 0, j = 0, size = distance(first, last);
    vll ans(size);
    while (i < size) {
        while (i - j >= 0 && i + j < size && *(first + i - j) == *(first + i + j)) j++;
        ans[i] = j;
        ll k = 1;
        while (i - k >= 0 && k + ans[i - k] < j) ans[i + k] = ans[i - k], k++;
        i += k;
        j -= k;
    }
    return ans;
}
