#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int solveUsingRecursion(int n) {
        // base case
        if (n == 0 || n == 1) {
            return n;
        }
        // recursive ralation
        int ans = solveUsingRecursion(n - 1) + solveUsingRecursion(n - 2);
        return ans;
    }

    int solveUsingMemoisation(int n, vector<int>& dp) {
        // base case
        if (n == 0 || n == 1) {
            return n;
        }

        // step 3: if ans already exist then return ans
        if (dp[n] != -1) {
            return dp[n];
        }
        // recursive ralation
        // Step 2: store and return using dp array
        dp[n] =
            solveUsingMemoisation(n - 1, dp) + solveUsingMemoisation(n - 2, dp);
        return dp[n];
    }
    int solveUsingTabulation(int n) {
        // step 1: create dp aarray
        vector<int> dp(n + 1, -1);
        // step 2: analyse base case and fill dp array
        dp[0] = 0;
        if (n == 0) {
            return dp[0];
        }
        dp[1] = 1;
        //   step 3: fill the ramainig dp array
        // size n+1;
        // index ->0 to n
        // index fill ho chuka hai -> 0 and 1
        // bacha hua index 2 to n tah jayega
        for (int i = 2; i <= n; i++) {
            // copy paste recursive logic and make sure loping varivale
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        // ans return
        return dp[n];
    }
    int solveUsingSpaceOptimasion(int n) {

        int prev = 0;
        if (n == 0) {
            return 0;
        }
        int curr = 1;
        int next;
        for (int index = 2; index <= n; index++) {
            next = curr + prev;
            prev = curr;
            curr = next;
        }

        return next;
    }
    int fib(int n) {
        // int ans = solveUsingRecursion(n);
        // return ans;

        // Step 1: create a dp array
        // vector<int> dp(n + 1, -1);
        // int ans = solveUsingMemoisation(n, dp);
        // return ans;

        //     int ans =solveUsingTabulation(n);
        //     return ans;

        int ans = solveUsingSpaceOptimasion(n);
        return ans;
    }
};

