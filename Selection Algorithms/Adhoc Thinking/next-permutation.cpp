// Q. Given a permutation with n digits.
// find the next greater permutation.

#include <bits/stdc++.h>
using namespace std;

class NextPermutation {
public:
    // Approach 1: BruteForec
    // Time Complexity: O(2^n)
    // Space Complexity: O(2^n)
    void checkPermutations(string per, string nextPermutation, int i, int len) {
        
    }
    string checkAllPermutation(string per) {
        int len = per.length();
        string nextPermutation = "";
        checkPermutations(per, nextPermutation, 1, len);
        return nextPermutation;
    }

    // Approach 2: Optimization
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    string optimized(string per) {
        int i = per.length() - 1;
        for (; i > 0; i--) {
            if (per[i - 1] < per[i]) {
                break;
            }
        }
        i--;
        cout << i << endl;
        int nextGreater = i + 1;
        for (int j = i; j < per.length(); j++) {
            if (per[j] > per[i] && per[nextGreater] > per[j]) {
                nextGreater = j;
            }
        }
        cout << nextGreater << endl;
        swap(per[i], per[nextGreater]);
        reverse(per.begin() + i + 1, per.end());
        return per;
    }
};

int main() {
    string per = "1234";
    cout << NextPermutation().optimized(per) << endl;
    cout << NextPermutation().checkAllPermutation(per) << endl;
    return 0;
}