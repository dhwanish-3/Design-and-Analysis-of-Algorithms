// Q2. Given an array of if size n return the second lowest value in the array

#include <bits/stdc++.h>
using namespace std;

class SecondMinimum {
public:
    // Approach 1: BruteForce
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int BruteForce(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = min1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            min1 = min(min1, nums[i]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != min1) {
                min2 = min(min2, nums[i]);
            }
        }
        return min2;
    }

    // Approach 2: Single run
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int SingleRun(vector<int>& nums) {
        int n = nums.size();
        int min1 = min(nums[0], nums[1]);
        int min2 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            if (nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        return min2;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << SecondMinimum().BruteForce(nums);
    return 0;
}