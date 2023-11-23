#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// int distinctPathRecursion(int m, int n, vector<vector<int>>& grid, int i, int j) {
//     if (i == m - 1 && j == n - 1) {
//         return 1;
//     }
//     if (i >= m || j >= n) {
//         return 0;
//     }
//     if (grid[i][j] == 1) {
//         return 0;
//     }
//     return distinctPathRecursion(m, n, grid, i + 1, j) + distinctPathRecursion(m, n, grid, i, j + 1);
// }

void distinctPath(int m, int n, vector<vector<int>>& grid) {
    int** dp = new int*[m];
    for (int i = 0; i < m; i++) {
        dp[i] = new int[n];
    }
    dp[m - 1][n - 1] = 1;
    for (int i = m - 2; i >= 0; i--) {
        if (grid[i][n - 1] == 1) {
            dp[i][n - 1] = 0;
        } else {
            dp[i][n - 1] = dp[i + 1][n - 1];
        }
    }
    for (int j = n - 2; j >= 0; j--) {
        if (grid[m - 1][j] == 1) {
            dp[m - 1][j] = 0;
        } else {
            dp[m - 1][j] = dp[m - 1][j + 1];
        }
    }
    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
    }
    cout << dp[0][0] << endl;
}

int main() {
    int t, m, n;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }
        distinctPath(m, n, grid);
    }
    return 0;
}