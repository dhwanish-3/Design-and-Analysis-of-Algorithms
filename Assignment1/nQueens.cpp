#include <bits/stdc++.h>
using namespace std;

void printSolution(int n, vector<vector<char>> board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cout << board[i][j];
        }
        cout << " ";
    }
    cout << endl;
}

void nQueensHelper(int n, int row, vector<vector<vector<char>>>& sol, vector<vector<char>>& board, bool* col, bool* diag1, bool* diag2) {
    if (row == n) {
        // printSolution(n, board);
        sol.push_back(board);
    }
    for (int i = 0; i < n; i++) {
        if (!col[i] && !diag1[row + i] && !diag2[row - i + n - 1]) {
            board[row][i] = 'Q';
            col[i] = true;
            diag1[row + i] = true;
            diag2[row - i + n - 1] = true;
            nQueensHelper(n, row + 1, sol, board, col, diag1, diag2);
            board[row][i] = '.';
            col[i] = false; // Backtracking
            diag1[row + i] = false;
            diag2[row - i + n - 1] = false;
        }
    }
}

vector<vector<vector<char>>> nQueens(int n) {
    vector<vector<vector<char>>> sol;
    vector<vector<char>> board;
    for (int i = 0; i < n; i++) {
        vector<char> row(n, '.');
        board.push_back(row);
    }
    bool col[n] = {false};
    bool diag1[2 * n - 1] = {false};
    bool diag2[2 * n - 1] = {false};
    nQueensHelper(n, 0, sol, board, col, diag1, diag2);
    return sol;
}

int main() {
    int n;
    cin >> n;
    nQueens(n);
    vector<vector<vector<char>>> sol = nQueens(n);
    cout << sol.size() << endl;
    for (int i = 0; i < sol.size(); i++) {
        printSolution(n, sol[i]);
    }
    return 0;
}