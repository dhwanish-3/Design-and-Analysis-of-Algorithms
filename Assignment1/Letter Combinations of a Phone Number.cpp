#include <bits/stdc++.h>
using namespace std;

string keyMapping[] = {
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void recursion(int i, string s, vector<string>& sol, string cur) {
    if (i >= s.length()) {
        sol.push_back(cur);
        return;
    }
    for (int j = 0; j < keyMapping[s[i] - '0' - 2].length(); j++) {
        recursion(i + 1, s, sol, cur + keyMapping[s[i] - '0' - 2][j]);
    }
}

vector<string> letterCombinations(string s) {
    int len = s.length();
    if (len == 0) {
        return {};
    }
    vector<string> sol;
    recursion(0, s, sol, "");
    return sol;
} 

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> sol = letterCombinations(s);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << endl;
    }
    return 0;
}