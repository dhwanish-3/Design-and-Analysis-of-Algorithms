// Q1. Find the minimum and the maximum from a given array

#include <bits/stdc++.h>
using namespace std;

class MinMax {
public:
    // Approach 1: Normal way
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Number of comparisons = 1 + 2(n - 2)
    pair<int, int> NormalWayMinMax(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return make_pair(-1, nums[0]);
        }
        int maxy = INT_MIN;
        int mini = INT_MAX;
        if (nums[0] > nums[1]) {
            maxy = nums[0];
            mini = nums[1];
        } else {
            maxy = nums[1];
            mini = nums[0];
        }
        for (int i = 2; i < n; i++) {
            maxy = max(maxy, nums[i]);
            mini = min(mini, nums[i]);
        }
        return make_pair(mini, maxy);
    }

    // Approach 1: Taking 2 at a time
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Number of comparisons = 1 + 3(n - 2) / 2 (better than Normal way)
    pair<int, int> takingTwo(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return make_pair(-1, nums[0]);
        }
        int maxy = INT_MIN;
        int mini = INT_MAX;
        if (nums[0] > nums[1]) {
            maxy = nums[0];
            mini = nums[1];
        } else {
            maxy = nums[1];
            mini = nums[0];
        }
        for (int i = 2; i < n; i += 2) {
            if (nums[i] > nums[i + 1]) {
                maxy = max(maxy, nums[i]);
                mini = min(mini, nums[i + 1]);
            } else {
                maxy = max(maxy, nums[i + 1]);
                mini = min(mini, nums[i]);
            }
        }
        return make_pair(mini, maxy);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int  i = 0; i < n; i++) {
        cin >> nums[i];
    }
    pair<int, int> minMax = MinMax().NormalWayMinMax(nums);
    cout << minMax.first << " " << minMax.second << endl;
    return 0;
}