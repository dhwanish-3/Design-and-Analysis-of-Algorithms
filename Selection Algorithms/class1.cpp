// Q. Given an array of size n + 1 with numbers in the range 1 to n
// With one number repeating more than once but all other numbers are occcuring only once
// return the repeating number without modifying the array and in O(1) space and O(n) time

#include <bits/stdc++.h>
using namespace std;

class RepeatingNumber {
public:
    // Approach 1: Brute force - No mutation
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    int BruteForce(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
    }

    // Approach 2: Sorting - Mutation
    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
    int Sorting(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
    }

    // Approach 3: HashMap - No Mutation
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int HashMap(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n - 1, 0);
        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (hash[i] >= 2) {
                return i;
            }
        }
    }

    // Approach 4: Sum till N - Works only if number is repeating only twice and Won't work if the number is too large
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int sumTillN(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int  i = 0; i < n; i++) {
            sum += nums[i];
        }
        int sumTillN = (n * (n + 1)) / 2;
        return sumTillN - sum;
    }

    // Approach 5: XOR Property - Works only if number is repeating only twice
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int XORproperty(vector<int>& nums) {
        int n = nums.size();
        int xorOfNums = 0;
        int xortillN = 0;
        for (int i = 0; i < n; i++) {
            xorOfNums ^= nums[i];
            xortillN ^= i + 1; 
        }
        return xortillN ^ xorOfNums;
    }

    // Approach 6: HashMap Optimisation - Using the Given Array as HashMap - Mutation
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int HashOptimized(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[abs(nums[i])] < 0) {
                return i;
            }
            nums[i] = (-nums[i]);
        }
    }

    // Approach 7: Linked List Cycle Detection - No Mutation
    // Every condition in the question is satisfied by the given array
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int LinkedList(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int n = nums.size();
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << RepeatingNumber().LinkedList(nums) << endl;
    return 0;
}