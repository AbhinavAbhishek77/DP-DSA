// Mem

// f(i,j) → Minimum number of operations required to convert string S1[0...i]
//  to S2[0...j] using three given operations.
class Solution
{
public:
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {

        if (i == 0)
            return j;
        if (j == 0)
            return i;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i - 1] == t[j - 1])
        {
            return dp[i][j] = solve(s, t, i - 1, j - 1, dp);
            // Minimum of three choices:
            // 1. Replace the character at S1[i] with the character at S2[j]
            // 2. Delete the character at S1[i]
            // 3. Insert the character at S2[j] into S1
        }
        else
        {
            // insert
            // delete
            // replace
            return dp[i][j] = min(min(1 + solve(s, t, i, j - 1, dp),
                                      1 + solve(s, t, i - 1, j, dp)),
                                  1 + solve(s, t, i - 1, j - 1, dp));
        }
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(word1, word2, n, m, dp);
    }
};

// Tab

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the edit distance between two strings
int editDistance(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to store edit distances
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row and column
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }

    // Fill in the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                // If the characters match, no additional cost
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                // 2. Delete the character at S1[i-1]
                // 3. Insert the character at S2[j-1] into S1
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    // The value at dp[n][m] contains the edit distance
    return dp[n][m];
}

int main()
{
    string s1 = "horse";
    string s2 = "ros";

    // Call the editDistance function and print the result
    cout << "The minimum number of operations required is: " << editDistance(s1, s2);
    return 0;
}

// Space
class Solution
{
public:
    int tabulation(string &s, string &t)
    {
        int n = s.size(), m = t.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Base Case
        // for (int i = 0; i <= n; i++) {
        //     curr[0] = i;
        // }

        for (int j = 0; j <= m; j++)
        {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++)
        {
            curr[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    // If the characters match, no additional cost
                    curr[j] = prev[j - 1];
                }
                else
                {
                    // Minimum of three choices:
                    // 1. Replace the character at S1[i-1] with S2[j-1]
                    // 2. Delete the character at S1[i-1]
                    // 3. Insert the character at S2[j-1] into S1
                    curr[j] =
                        min(min(1 + curr[j - 1], 1 + prev[j]), 1 + prev[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }
    int minDistance(string word1, string word2)
    {
        return tabulation(word1, word2);
    }
};