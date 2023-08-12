// Q1. Find the minimum and the maximum from a given array

#include <bits/stdc++.h>
using namespace std;

class MinMax {
public:
    // Approach 1: Normal way
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    pair<int, int> NormalWayMinMax(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return make_pair(-1, nums[0]);
        }
        int maxy = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            maxy = max(maxy, nums[i]);
            mini = min(mini, nums[i]);
        }
        return make_pair(mini, maxy);
    }
};

int main(){
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