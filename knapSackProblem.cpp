#include <iostream>
#include <vector>
using namespace std;
int solveUsingRecursion(int capacity, int wt[], int profit[], int index, int n)
{

    // base case
    if (index == n - 1)
    {
        if (wt[index] <= capacity)
        {
            return profit[index];
        }
        else
        {
            return 0;
        }
    }
    // inclusion or exlusion
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingRecursion(capacity - wt[index], wt, profit, index + 1, n);
    }
    int exclude = 0 + solveUsingRecursion(capacity, wt, profit, index + 1, n);
    int ans = max(include, exclude);
    return ans;
}
int solveUsingMemoisation(int capacity, int wt[], int profit[], int index, int n, vector<vector<int>> &dp)
{

    // base case
    if (index == n - 1)
    {
        if (wt[index] <= capacity)
        {
            return profit[index];
        }
        else
        {
            return 0;
        }
    }
    // already exist case
    if (dp[capacity][index] != -1)
    {
        return dp[capacity][index];
    }
    // inclusion or exlusion
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = profit[index] + solveUsingMemoisation(capacity - wt[index], wt, profit, index + 1, n, dp);
    }
    int exclude = 0 + solveUsingMemoisation(capacity, wt, profit, index + 1, n, dp);
    dp[capacity][index] = max(include, exclude);
    return dp[capacity][index];
}
int solveUsingTabulation(int capacity, int wt[], int profit[], int index, int n)
{
    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
    for (int row = 0; row <= capacity; row++)
    {
        dp[capacity][n] = 0;
    }

    for (int i = 0; i <= capacity; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            // inclusion or exlusion
            int include = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + dp[i - wt[j]][j + 1];
            }
            int exclude = 0 + dp[i][j + 1];
            dp[i][j] = max(include, exclude);
        }
    }
    return dp[capacity][0] + 1;
}
int solveUsingSpaceOptimaisation(int capacity, int wt[], int profit[], int n)
{
    vector<int> next(capacity + 1, 0);
    vector<int> curr(capacity + 1, -1);

    for (int i = 0; i <= capacity; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            // inclusion or exlusion
            int include = 0;
            if (wt[j] <= i)
            {
                include = profit[j] + next[i - wt[j]];
            }
            int exclude = 0 + next[i];
            curr[i] = max(include, exclude);
        }
        // shifting
        next = curr;
    }
    return curr[capacity];
}
int main()
{
    int capacity = 50;
    int wt[] = {10, 20, 30};
    int profit[] = {60, 100, 120};
    // int index = 0;
    int n = 3;
    // int ans = solveUsingRecursion(capacity, wt, profit, index, n);
    // cout << "Max profit: " << ans << endl;

    // vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
    // int ans = solveUsingMemoisation(capacity, wt, profit, index, n, dp);
    // cout << "Max profit: " << ans << endl;

    // int ans = solveUsingTabulation(capacity, wt, profit, index, n);
    // cout << "Max profit: " << ans << endl;

    int ans = solveUsingSpaceOptimaisation(capacity, wt, profit, n);
    cout << "Max profit: " << ans << endl;

    return 0;
}