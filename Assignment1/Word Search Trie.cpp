#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isEndOfWord;
    }
};

bool recursion(vector<vector<char>>& board, TrieNode* node, int i, int j, string& currWord, unordered_set<string>& foundWords, vector<vector<bool>>& visited) {
    if (node->isEndOfWord) {
        foundWords.insert(currWord);
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || node->children.find(board[i][j]) == node->children.end()) {
        return false;
    }
    visited[i][j] = true;
    currWord += board[i][j];
    bool found = recursion(board, node->children[board[i][j]], i + 1, j, currWord, foundWords, visited) ||
                 recursion(board, node->children[board[i][j]], i - 1, j, currWord, foundWords, visited) ||
                 recursion(board, node->children[board[i][j]], i, j + 1, currWord, foundWords, visited) ||
                 recursion(board, node->children[board[i][j]], i, j - 1, currWord, foundWords, visited);
    visited[i][j] = false;
    currWord.pop_back();
    return found;
}

vector<string> wordSearch(vector<vector<char>>& board, vector<string>& words) {
    Trie trie;
    for (string word : words) {
        trie.insert(word);
    }
    unordered_set<string> foundWords;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            string currWord = "";
            recursion(board, trie.root, i, j, currWord, foundWords, visited);
        }
    }
    vector<string> sol(foundWords.begin(), foundWords.end());
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
    vector<string> sol = wordSearch(board, word);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << endl;
    }
    return 0;
}