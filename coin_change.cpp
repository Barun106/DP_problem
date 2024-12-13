#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class Solution {
public:
    int solveUsingRecursion(vector<int>& coins, int amount) {
        // base case
        if (amount == 0) {
            return 0;
        }

        // recursive relation
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int recursionkaAns = 0;
            if (amount - coins[i] >= 0) {
                recursionkaAns = solveUsingRecursion(coins, amount - coins[i]);
                // if a valid ans
                if (recursionkaAns != INT_MAX) {

                    int ans = 1 + recursionkaAns;
                    mini = min(mini, ans);
                }
            }
        }
        return mini;
    }

    int solveUsingMem(vector<int>& coins, int amount, vector<int>& dp) {
        // base case
        if (amount == 0) {
            return 0;
        }
        // already exists
        if (dp[amount] != -1) {
            return dp[amount];
        }

        // recursive relation
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int recursionkaAns = 0;
            if (amount - coins[i] >= 0) {
                recursionkaAns = solveUsingMem(coins, amount - coins[i], dp);
                // if a valid ans
                if (recursionkaAns != INT_MAX) {

                    int ans = 1 + recursionkaAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }
    int solveUsingTabulation(vector<int>& coins, int amount) {
        // step 1:
        int n = amount;
        vector<int> dp(n + 1, INT_MAX);
        // step 2:
        dp[0] = 0;

        for (int value = 1; value <= amount; value++) {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
                int recursionkaAns = 0;
                if (value - coins[i] >= 0) {
                    recursionkaAns = dp[value - coins[i]];
                    // if a valid ans
                    if (recursionkaAns != INT_MAX) {

                        int ans = 1 + recursionkaAns;
                        mini = min(mini, ans);
                    }
                }
            }

            dp[value] = mini;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveUsingRecursion(coins, amount);
        int n = amount;
        vector<int> dp(n + 1, -1);
        int ans = solveUsingTabulation(coins, amount);
        if (ans == INT_MAX) {
            return -1;
        } else {
            return ans;
        }
    }
};