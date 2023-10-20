#include <bits/stdc++.h>
using namespace std;

void fillRowCol(int sudoku[][9], bool row[][10], bool col[][10]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            row[i][sudoku[i][j]] = true;
            col[j][sudoku[i][j]] = true;
        }
    }
}

void fillSubSudoku(int sudoku[][9], bool subSudoku[][10]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            subSudoku[((i / 3) * 3) + j / 3][sudoku[i][j]] = true;
        }
    }
}

bool isSafe(int sudoku[][9], bool row[][10], bool col[][10], bool subSudoku[][10], int r, int c, int num) {
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

bool solve(int sudoku[][9], bool row[][10], bool col[][10], bool subSudoku[][10], int r, int c) {
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

void solveSudoku(int sudoku[][9]) {
    bool row[9][10] = {false};
    bool col[9][10] = {false};
    bool subSudoku[9][10] = {false};
    fillRowCol(sudoku, row, col);
    fillSubSudoku(sudoku, subSudoku);
    solve(sudoku, row, col, subSudoku, 0, 0);
}

int main() {
    int sudoku[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }
    // int sudoku[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
    //                     {5, 2, 0, 0, 0, 0, 0, 0, 0},
    //                     {0, 8, 7, 0, 0, 0, 0, 3, 1},
    //                     {0, 0, 3, 0, 1, 0, 0, 8, 0},
    //                     {9, 0, 0, 8, 6, 3, 0, 0, 5},
    //                     {0, 5, 0, 0, 9, 0, 6, 0, 0},
    //                     {1, 3, 0, 0, 0, 0, 2, 5, 0},
    //                     {0, 0, 0, 0, 0, 0, 0, 7, 4},
    //                     {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    solveSudoku(sudoku);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}