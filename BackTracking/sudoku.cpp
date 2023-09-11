#include <bits/stdc++.h>
using namespace std;

void fillRowCol(vector<vector<int>> sudoku, vector<vector<bool>>& row, vector<vector<bool>>& col) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            row[i][sudoku[i][j]] = true;
            col[j][sudoku[i][j]] = true;
        }
    }
}

void fillSubSudoku(vector<vector<int>>& sudoku, vector<vector<bool>>& subSudoku) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            subSudoku[((i / 3) * 3) + j / 3][sudoku[i][j]] = true;
        }
    }
}

bool isSafe(vector<vector<int>> sudoku, vector<vector<bool>> row, vector<vector<bool>> col, vector<vector<bool>> subSudoku, int r, int c, int num) {
    return !row[r][num] && !col[c][num] && !subSudoku[((r / 3) * 3) + c / 3][num] && sudoku[r][c] == 0;
}

bool isComplete(vector<vector<int>> sudoku, int& r, int& c) {
    for (r = 0; r < 9; r++) {
        for (c = 0; c < 9; c++) {
            if (sudoku[r][c] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>>& sudoku, vector<vector<bool>>& row,vector<vector<bool>>& col, vector<vector<bool>>& subSudoku, int r, int c) {
    if (r == 9) {
        return true;
    }
    if (c == 9) {
        return solve(sudoku, row, col, subSudoku, r + 1, 0);
    }
    if (sudoku[r][c] != 0) {
        return solve(sudoku, row, col, subSudoku, r, c + 1);
    }
    for (int num = 1; num < 10; num++) {
        if (isSafe(sudoku, row, col, subSudoku,r, c, num)) {
            sudoku[r][c] = num;
            row[r][num] = true;
            col[c][num] = true;
            subSudoku[((r / 3) * 3) + c / 3][num] = true;
            if (solve(sudoku, row, col, subSudoku, r, c + 1)) {
                return true;
            }
            sudoku[r][c] = 0;
            row[r][num] = false;
            col[c][num] = false;
            subSudoku[((r / 3) * 3) + c / 3][num] = false;
        }
    }
    return false;
}

vector<vector<int>> solveSudoku(vector<vector<int>>& sudoku) {
    vector<vector<bool>> row(9, vector<bool>(10, false));
    vector<vector<bool>> col(9, vector<bool>(10, false));
    vector<vector<bool>> subSudoku(9, vector<bool>(10, false));
    fillRowCol(sudoku, row, col);
    fillSubSudoku(sudoku, subSudoku);
    solve(sudoku, row, col, subSudoku, 0, 0);
    return sudoku;
}

int main() {
    vector<vector<int>> sudoku(9, vector<int>(9, 0));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }
    // vector<vector<int>> sudoku = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
	// 				{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
	// 				{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
	// 				{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
	// 				{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
	// 				{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
	// 				{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
	// 				{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
	// 				{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    vector<vector<int>> sol = solveSudoku(sudoku);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}