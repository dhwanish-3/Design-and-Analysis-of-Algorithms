#include <bits/stdc++.h>
using namespace std;

class kthSmallest {
public:
    // Approach 1: Sorting
    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
    int sorting(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[k];
    }

    // Approach 2: Priority Queue
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
    int priorityQueue(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }
        int i = 1;
        while (i < k) {
            q.pop();
            i++;
        }
        return q.top();
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << kthSmallest().priorityQueue(nums, k);
    return 0;
}