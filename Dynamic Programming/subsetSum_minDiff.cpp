#include <bits/stdc++.h>
using namespace std;

class subsetSum {
    bool recursionHelper(vector<int>& arr, int sum, int n) {
        if (sum == 0) {
            return true;
        }
        if (n == 0) {
            return false;
        }
        if (arr[n - 1] <= sum) {
            return recursionHelper(arr, sum - arr[n - 1], n - 1) || recursionHelper(arr, sum, n - 1);
        } else {
            return recursionHelper(arr, sum, n - 1);
        }
    }

    bool memoHelper(vector<int>& arr, int sum, int n, vector<vector<bool>>& dp) {
        if (sum == 0) {
            return true;
        }
        if (n == 0) {
            return false;
        }
        if (dp[n][sum] != -1) {
            return dp[n][sum];
        }
        if (arr[n - 1] <= sum) {
            return dp[n][sum] = memoHelper(arr, sum - arr[n - 1], n - 1, dp) || memoHelper(arr, sum, n - 1, dp);
        } else {
            return dp[n][sum] = memoHelper(arr, sum, n - 1, dp);
        }
    }

public:
    bool recursion(vector<int>& arr, int sum) {
        return recursionHelper(arr, sum, arr.size());
    }

    bool memoization(vector<int>& arr, int sum) {
        vector<vector<bool>> dp(arr.size() + 1, vector<bool>(sum + 1, false));
        return memoHelper(arr, sum, arr.size(), dp);
    }

    bool tabulation(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        for(int i = sum / 2; i >= 0; i--){
            if(dp[n][i] == true){
                return sum - 2 * i;
            }
        }
        return -1;
    }
};

int main() {
    int n, sum;
    n = 5;
    // cin >> n >> sum;
    vector<int> arr(n);
    arr = {11, 7};
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    // for (int& i : arr) {
    //     cin >> i;
    // }
    cout << subsetSum().tabulation(arr, sum) << endl;
    return 0;
}