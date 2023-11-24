#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.*/
/* For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".*/
/* Return the number of different expressions that you can build, which evaluates to target.*/

// int PlusOrMinusRecursion(int n, vector<int>& nums, int target, int curSum, int curIndex) {
//     if (curIndex == n) {
//         if (curSum == target) {
//             return 1;
//         }
//         return 0;
//     }
//     int add = PlusOrMinusRecursion(n, nums, target, curSum + nums[curIndex], curIndex + 1);
//     int subtract = PlusOrMinusRecursion(n, nums, target, curSum - nums[curIndex], curIndex + 1);
//     return add + subtract;
// }

// tabulation
int PlusOrMinusTabulation(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    if (abs(target) > sum) {
        return 0;
    }
    vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
    dp[0][sum] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2 * sum + 1; j++) {
            if (j - nums[i - 1] >= 0) {
                dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
            if (j + nums[i - 1] <= 2 * sum) {
                dp[i][j] += dp[i - 1][j + nums[i - 1]];
            }
        }
    }
    return dp[n][sum + target];
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
        // cout << PlusOrMinusRecursion(n, nums, k, 0, 0) << endl;
        cout << PlusOrMinusTabulation(nums, k) << endl;
    }
    return 0;
}