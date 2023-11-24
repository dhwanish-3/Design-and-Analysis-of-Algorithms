#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.*/

bool EqualSubsetDivisionRecursionHelper(int n, vector<int>& nums, int target, vector<bool>& visited, int currSum, int currIndex) {
    if (target == currSum) {
        return true;
    }
    if (currSum > target) {
        return false;
    }
    for (int i = currIndex; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            if (EqualSubsetDivisionRecursionHelper(n, nums, target, visited, currSum + nums[i], i + 1)) {
                return true;
            }
            visited[i] = false;
        }
    }
    return false;
}

void EqualSubsetDivisionRecursion(int n, vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    if (sum % k != 0) {
        cout << "NO" << endl;
        return;
    }
    vector<bool> visited(n, false);
    if (EqualSubsetDivisionRecursionHelper(n, nums, sum / k, visited, 0, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    int n, k;
    while (t--) {
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cin >> k;
        EqualSubsetDivisionRecursion(n, nums, k);
    }
    return 0;
}