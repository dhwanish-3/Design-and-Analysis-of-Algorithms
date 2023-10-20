#include <bits/stdc++.h>
using namespace std;

void recursion(int open, int close, vector<string>& sol, string s) {
    if (open == 0 && close == 0) {
        sol.push_back(s);
        return;
    }
    if (close < open) {
        return;
    }
    if (open == 0) {
        recursion(open, close - 1, sol, s + ")");
    } else if(close == 0) {
        return;
    } else {
        recursion(open - 1, close, sol, s + "(");
        recursion(open, close - 1, sol, s + ")");
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> sol;
    recursion(n, n, sol, "");
    return sol;
}

int main() {
    int n;
    cin >> n;
    vector<string> sol = generateParenthesis(n);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << endl;
    }
    return 0;
}