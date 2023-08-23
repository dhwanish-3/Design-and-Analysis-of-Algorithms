// Q. Given n dice roles, print all combinations that gives a sum s

#include <bits/stdc++.h>
using namespace std;

void diceSum(int n, string s, int sum, int target) {
    if (n == 0) {
        if (sum == target) {
            cout << s << endl;
        }
        return;
    }
    for (int i = 1;  i < 7; i++) {
        if (sum + i + n - 1 <= target && sum + i + 6 * (n - 1) >= target) { // Backtracking
            diceSum(n - 1, s + to_string(i) + " ", sum + i, target);
        }
    }
}

int main() {
    int n, target;
    cin >> n >> target;
    diceSum(n, "", 0, target);
    return 0;
}