#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int solveUsingRecursion(string a, string b, int i, int j) {
        // base case
        if (i >= a.length()) {
            return 0;
        }
        if (j >= b.length()) {
            return 0;
        }
        // recursive relation
        int ans = 0;
        if (a[i] == b[j]) {
            ans = 1 + solveUsingRecursion(a, b, i + 1, j + 1);
        } else {
            ans = 0 + max(solveUsingRecursion(a, b, i, j + 1),
                          solveUsingRecursion(a, b, i + 1, j));
        }
        return ans;
    }
    int solveUsingMemoisation(string& a, string& b, int i, int j,
                              vector<vector<int>>& dp) {
        // base case
        if (i >= a.length()) {
            return 0;
        }
        if (j >= b.length()) {
            return 0;
        }
        // already exists
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // recursive relation
        int ans = 0;
        if (a[i] == b[j]) {
            dp[i][j] = 1 + solveUsingMemoisation(a, b, i + 1, j + 1, dp);
        } else {
            dp[i][j] = 0 + max(solveUsingMemoisation(a, b, i, j + 1, dp),
                               solveUsingMemoisation(a, b, i + 1, j, dp));
        }
        return dp[i][j];
    }
    int solveUsingTabulation(string& a, string& b, int i, int j) {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

        for (int i = a.length() - 1; i >= 0; i--) {
            for (int j = b.length() - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    ans = 1 + dp[i + 1][j + 1];
                } else {
                    ans = 0 + max(dp[i][j + 1], dp[i + 1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveUsingSpaceOptimisation(string& a, string& b, int i, int j) {
        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);
        for (int j = b.length() - 1; j >= 0; j--) {
            for (int i = a.length() - 1; i >= 0; i--) {
                
                    int ans = 0;
                    if (a[i] == b[j]) {
                        ans = 1 + next[i + 1];
                    } 
                    else {
                        ans = 0 + max(next[i], curr[i + 1]);
                    }
                    curr[i] = ans;
                }
                // shifting
                next = curr;
            }
            return next[0];
        }
    
        int longestCommonSubsequence(string text1, string text2) {
            int i = 0;
            int j = 0;
            // int ans = solveUsingRecursion(text1, text2, i, j);
            // return ans;

            // vector<vector<int>> dp(text1.length() + 1,
            // vector<int>(text2.length()
            // + 1,-1)); nt ans = solveUsingMemoisation(text1, text2, i, j,dp);
            // return ansi;

            int ans = solveUsingTabulation (text1, text2, i, j);
            return ans;
        }
    
    };