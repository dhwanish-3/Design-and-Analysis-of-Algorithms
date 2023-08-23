#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<int>& sol, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (sol[i] == col || abs(sol[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

bool nQueensHelper(int n, int row, vector<int>& sol, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2) {
    if (row == n) {
        return true;
    }
    for (int i = 0; i < n; i++) {
        if (!col[i] && !diag1[row + i] && !diag2[row - i + n - 1]) {
            sol[row] = i;
            col[i] = true;
            diag1[row + i] = true;
            diag2[row - i + n - 1] = true;
            if (nQueensHelper(n, row + 1, sol, col, diag1, diag2)) {
                return true;
            }
            col[i] = false; // Backtracking
            diag1[row + i] = false;
            diag2[row - i + n - 1] = false;
        }
    }
    return false;
}

vector<int> nQueens(int n) {
    vector<int> sol(n);
    vector<bool> col(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);
    if (nQueensHelper(n, 0, sol, col, diag1, diag2) == false) {
        cout << "No solution exists";
        return {};
    }
    return sol;
}

int main() {
    int n;
    cin >> n;
    vector<int> sol = nQueens(n);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    return 0;
}