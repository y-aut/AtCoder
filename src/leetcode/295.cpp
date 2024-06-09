#pragma region "Template"

#include "leetcode.hpp"

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

class MedianFinder {
    map<int, int> nums;
    int mid;
    int offset;
    int size = 0;

    void move_left() {
        if (offset == 0) {
            auto itr = prev(nums.find(mid));
            mid = itr->first;
            offset = itr->second - 1;
        } else {
            offset--;
        }
    }

    void move_right() {
        if (++offset == nums[mid]) {
            mid = next(nums.find(mid))->first;
            offset = 0;
        }
    }

public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (size == 0) {
            nums[num]++;
            mid = num;
            offset = 0;
            size++;
            return;
        }
        if (size % 2 == 0) {
            nums[num]++;
            size++;
            if (num == mid) {
                offset++;
            } else if (num > mid) {
                move_right();
            }
        } else {
            nums[num]++;
            size++;
            if (num < mid) {
                move_left();
            }
        }
    }

    double findMedian() {
        if (size % 2 != 0) {
            return mid;
        } else {
            if (offset + 1 < nums[mid]) {
                return mid;
            } else {
                return (double)(mid + next(nums.find(mid))->first) / 2;
            }
        }
    }
};

/*
    itr, offset
    [1, 3, 4]: *itr == 3, offset == 0
    [1, 3]: *itr == 1, offset == 0
    [1, 2, 2, 2, 3]: *itr == 2, offset == 1

    O(NlogN)
    O(N)
*/

void solve() {
    MedianFinder m;
    m.addNum(1);
    print(m.findMedian());
    m.addNum(2);
    print(m.findMedian());
    m.addNum(2);
    print(m.findMedian());
    m.addNum(1);
    print(m.findMedian());
    m.addNum(3);
    print(m.findMedian());
}
