// Q. Given an array of size n of which more than n/2 elements are the same.
// return this majority element.

#include <bits/stdc++.h>
using namespace std;

class MajorityElement {
public:
    // Approach 1: Sort + Traverse
    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
    int sorting(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxCount = 0;
        int majority = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                if (count > maxCount) {
                    maxCount = count;
                    majority = nums[i - 1];
                }
                count = 1;
            }
        }
        return majority;
    }

    // Appraoch 2: HashMap
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int hashing(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        int maxCount = 0;
        int majority = nums[0];
        for (auto it : hash) {
            if (it.second > maxCount) {
                maxCount = it.second;
                majority = it.first;
            }
        }
        return majority;
    }
    
    // Approach 3: Bayer-Moore Voting alogorithm
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int BayerMooreVoting(vector<int>& nums) {
        int majority = nums[0];
        int votes = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == majority) {
                votes++;
            } else {
                votes--;
            }
            if (votes == 0) {
                majority = nums[i];
                votes = 1;
            }
        }
        return majority;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 3, 1, 1, 2, 1, 2, 1, 2, 1, 2};
    cout << MajorityElement().BayerMooreVoting(nums) << endl;
    cout << MajorityElement().hashing(nums) << endl;
    cout << MajorityElement().sorting(nums) << endl;
    return 0;
}