#include <bits/stdc++.h>
using namespace std;

int dirs[] = {0, 1, 0, -1, 0};
bool recursion(vector<vector<char>>& board, string word, int i, int j, int k, bool** visited) {
    int m = board.size();
    int n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) {
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
        if (x < 0 || x >= m || y < 0 || y >= n) {
            continue;
        }
        if (visited[x][y]) {
            continue;
        }
        if (recursion(board, word, x, y, k + 1, visited)) {
            return true;
        }
    }
    visited[i][j] = false;
    return false;
}

vector<string> wordSearch(int n, int m, vector<vector<char>> board, int k, vector<string> word) {
    vector<string> sol;
    for (int i = 0; i < k; i++) {
        bool** visited = new bool*[n];
        for (int j = 0; j < n; j++) {
            visited[j] = new bool[m];
            for (int k = 0; k < m; k++) {
                visited[j][k] = false;
            }
        }
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (found) {
                break;
            }
            for (int l = 0; l < m; l++) {
                if (word[i][0] == board[j][l] && recursion(board, word[i], j, l, 0, visited)) {
                    sol.push_back(word[i]);
                    found = true;
                    break;
                }
            }
        }
    }
    return sol;
}

int main() {
    int n, m, k;
    // cin >> n >> m;
    n = 4;
    m = 4;
    vector<vector<char>> board(n, vector<char>(m));
    board = {{'o', 'a', 'n', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cin >> board[i][j];
    //     }
    // }
    // cin >> k;
    k = 4;
    vector<string> word(k);
    word = {"oath", "eat", "pea", "rain"};
    // for (int i = 0; i < k; i++) {
    //     cin >> word[i];
    // }
    vector<string> sol = wordSearch(n, m, board, k, word);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << endl;
    }
    return 0;
}