#pragma region "Template"

#include "leetcode.hpp"

void solve();
int main() {
    cout << fixed << setprecision(16);
    solve();
    return 0;
}

#pragma endregion

class Solution {
private:
    double median(vector<int> &nums) {
        assert(!nums.empty());
        if (nums.size() % 2 == 0) return (double)(nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2;
        else return nums[nums.size() / 2];
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m == 0) return median(nums2);
        if (n == 0) return median(nums1);
        int lower = min(nums1.front(), nums2.front());
        int upper = max(nums1.back(), nums2.back()) + 1;
        while (true) {
            if (lower + 1 >= upper) break;
            int mid = (lower + upper) / 2;
            int l1 = lower_bound(nums1.begin(), nums1.end(), mid) - nums1.begin();
            int u1 = upper_bound(nums1.begin(), nums1.end(), mid) - nums1.begin();
            int l2 = lower_bound(nums2.begin(), nums2.end(), mid) - nums2.begin();
            int u2 = upper_bound(nums2.begin(), nums2.end(), mid) - nums2.begin();
            int l = l1 + l2, u = u1 + u2, s = u - l, g = m + n - u;
            int mid_prev = -1e8, mid_next = 1e8;
            if (l1 > 0) mid_prev = nums1[l1 - 1];
            if (l2 > 0) mid_prev = max(mid_prev, nums2[l2 - 1]);
            if (u1 < m) mid_next = nums1[u1];
            if (u2 < n) mid_next = min(mid_next, nums2[u2]);
            if (l == s + g) return (double)((s ? mid : mid_next) + mid_prev) / 2;
            if (g == s + l) return (double)((s ? mid : mid_prev) + mid_next) / 2;
            if (l > s + g) {
                upper = mid;
                continue;
            }
            if (g > s + l) {
                lower = mid;
                continue;
            }
            return mid;
        }
        return lower;
    }
};

void solve() {
    Solution sol;
    STR(S, T);
    auto nums1 = parse_vi(S);
    auto nums2 = parse_vi(T);
    print(sol.findMedianSortedArrays(nums1, nums2));
}
