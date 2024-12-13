#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int index) {
        // base case
        if (index >= nums.size()) {
            return 0;
        }
        // recursion relation
        int include = nums[index] + solveUsingRecursion(nums, index + 2);
        int exclude = 0 + solveUsingRecursion(nums, index + 1);
        int ans = max(include, exclude);
        return ans;
    }
    // memoisation
    int solveUsingMemo(vector<int>& nums, int index, vector<int>& dp) {
        // base case
        if (index >= nums.size()) {
            return 0;
        }

        // ans already exists
        if (dp[index] != -1) {
            return dp[index];
        }
        // recursion relation
        int include = nums[index] + solveUsingMemo(nums, index + 2, dp);
        int exclude = 0 + solveUsingMemo(nums, index + 1, dp);
        dp[index] = max(include, exclude);
        return dp[index];
    }
    int solveUsingTabulation(vector<int>& nums) {
        int n = nums.size();
        // step 1:
        vector<int> dp(n, -1);
        // step 2:
        dp[n - 1] = nums[n - 1];
        for (int index = n - 2; index >= 0; index--) {
            int tempAns = 0;
            if (index + 2 < n) {
                tempAns = dp[index + 2];
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + dp[index + 1];
            dp[index] = max(include, exclude);
        }
            return dp[0];
        
    }
    int solveUsingSpaceOpti(vector<int>& nums){
        int n=nums.size();
        int prev=nums[n-1];
        int next=0;
        int curr;
         for (int index = n - 2; index >= 0; index--) {
            int tempAns = 0;
            if (index + 2 < n) {
                tempAns = next;
            }
            int include = nums[index] + tempAns;
            int exclude = 0 + prev;
           curr = max(include, exclude);
           next=prev;
             prev=curr;
         }
             return prev;
    }
        int rob(vector<int> & nums) {
            int index = 0;
            // int ans = solveUsingRecursion(nums, index);
            // return ans;
            int n = nums.size();
            // vector<int>dp(n+1,-1);
            // int ans=solveUsingMemo(nums,index,dp);
            // return ans;
            // int ans = solveUsingTabulation(nums);
            // return ans;
            int ans=solveUsingSpaceOpti(nums);
            return ans;
        }
    };
