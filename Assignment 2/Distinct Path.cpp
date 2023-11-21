#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void distinctPath(int m, int n, vector<vector<int>>& grid) {
    int** dp = new int*[m];
    for (int i = 0; i < m; i++) {
        dp[i] = new int[n];
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; i++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[m - 1][n - 1] << endl;
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