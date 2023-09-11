// Q. Print all the prime numbers from 1 to n.

#include <bits/stdc++.h>
using namespace std;

class Prime {
    bool isPrime(int n) {
        if (n == 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            } 
        }
        return true;
    }
public:
    // Approach 1: Naive
    // Time Complexity: O(n * sqrt(n))
    // Space Complexity: O(1)
    void normalWay(int n) {
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                cout << i << " ";
            }
        }
    }

    // Approach 2: Sieve of Eratosthenes
    // Time Complexity: O(nloglogn)
    // Space Complexity: O(n)
    void sieveOfEratosthenes(int n) {
        vector<bool> prime(n + 1, true);
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                cout << i << " ";
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    Prime().normalWay(n);
    cout << endl;
    Prime().sieveOfEratosthenes(n);
    return 0;
}