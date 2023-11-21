#include <bits/stdc++.h>
using namespace std;

int dirs[] = {0, 1, 0, -1, 0};
bool recursion(char** board, int n, int m, string word, int i, int j, int k, bool** visited) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    if (board[i][j] != word[k]) {
        return false;
    }
    if (k == word.size() - 1) {
        return true;
    }
    visited[i][j] = true;
    for (int l = 0; l < 4; l++) {
        int x = i + dirs[l];
        int y = j + dirs[l + 1];
        if (x < 0 || x >= n || y < 0 || y >= m) {
            continue;
        }
        if (visited[x][y]) {
            continue;
        }
        if (word[k + 1] == board[x][y] && recursion(board, n, m, word, x, y, k + 1, visited)) {
            return true;
        }
    }
    visited[i][j] = false;
    return false;
}

bool wordSearch(int n, int m, char** board, string word) {
    bool** visited = new bool*[n];
    for (int j = 0; j < n; j++) {
        visited[j] = new bool[m];
        for (int k = 0; k < m; k++) {
            visited[j][k] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < m; l++) {
            if (word[0] == board[i][l] && recursion(board, n, m, word, i, l, 0, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m, k;
    n = 4;
    m = 4;
    char** board = new char*[n];
    for (int i = 0; i < n; i++) {
        board[i] = new char[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    cin >> k;
    vector<string> word(k);
    for (int i = 0; i < k; i++) {
        cin >> word[i];
    }
    for (int i = 0; i < k; i++) {
        if (wordSearch(n, m, board, word[i])) {
            cout << word[i] << endl;
        }
    }
    return 0;
}