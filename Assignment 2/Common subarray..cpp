#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.*/

// int recursiveCommonSubarray(int n, vector<int>& nums1, int m, vector<int>& nums2) {
//     if (n == 0 || m == 0) {
//         return 0;
//     }
//     if (nums1[n - 1] == nums2[m - 1]) {
//         return 1 + recursiveCommonSubarray(n - 1, nums1, m - 1, nums2);
//     } else {
//         return max(recursiveCommonSubarray(n - 1, nums1, m, nums2), recursiveCommonSubarray(n, nums1, m - 1, nums2));
//     }
// }

int commonSubarray(int n, vector<int>& nums1, int m, vector<int>& nums2) {
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m ; j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    int n, m;
    while (t--) {
        cin >> n >> m;
        vector<int> nums1(n);
        for (int i = 0; i < n; i++) {
            cin >> nums1[i];
        }
        vector<int> nums2(m);
        for (int i = 0; i < m; i++) {
            cin >> nums2[i];
        }
        // cout << recursiveCommonSubarray(n, nums1, m, nums2) << endl;
        cout << commonSubarray(n, nums1, m, nums2) << endl;
    }
    return 0;
}