#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// int changeDenominationsRecursion(int n, vector<int>& coins, int amount) {
//     if (amount == 0) {
//         return 1;
//     }
//     if (n == 0) {
//         return 0;
//     }
//     if (coins[n - 1] <= amount) {
//         return changeDenominationsRecursion(n, coins, amount - coins[n - 1]) + changeDenominationsRecursion(n - 1, coins, amount);
//     } else {
//         return changeDenominationsRecursion(n - 1, coins, amount);
//     }
// }

void changeDenominations(int n, vector<int>& coins, int amount) {
    int dp[n + 1][amount + 1];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= amount; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (coins[i - 1] <= j) {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][amount] << endl;
}

int main() {
    int t;
    cin >> t;
    int n, amount;
    while (t--) {
        cin >> n;
        vector<int> coins(n);
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }
        cin >> amount;
        changeDenominations(n, coins, amount);
        // cout << changeDenominationsRecursion(n, coins, amount) << endl;
    }
    return 0;
}