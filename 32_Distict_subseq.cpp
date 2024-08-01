// A6
#include <bits/stdc++.h>
using namespace std;

const int prime = 1e9 + 7;

// Function to count the number of distinct subsequences of s2 in s1
int subsequenceCounting(string &s1, string &s2, int n, int m)
{
    // Create an array to store the count of distinct subsequences for each character in s2
    vector<int> prev(m + 1, 0);

    // Initialize the count for an empty string (base case)
    prev[0] = 1;

    // Iterate through s1 and s2 to calculate the counts
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        { // Iterate in reverse direction to avoid overwriting values prematurely
            if (s1[i - 1] == s2[j - 1])
            {
                // If the characters match, we have two options:
                // 1. Match the current characters and add to the previous count (prev[j-1])
                // 2. Leave the current character in s1 and match s2 with the previous characters (prev[j])
                prev[j] = (prev[j - 1] + prev[j]) % prime;
            }
            // No need for an else statement since we can simply leave the previous count as is
        }
    }

    // The value at prev[m] contains the count of distinct subsequences
    return prev[m];
}

int main()
{
    string s1 = "babgbag";
    string s2 = "bag";

    // Call the subsequenceCounting function and print the result
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting(s1, s2, s1.size(), s2.size());
    return 0;
}

// A5

#include <bits/stdc++.h>
int mod = 10e9 + 7;

// dp[i][j] means Count of all distinct subsequences of S2[0...j-1]
// in the string S1[0...i-1].

// prev[0] = 1 means that there is exactly one way to match an empty subsequence (sub) with any prefix of str.
// curr[0] = 1 ensures that this property is carried over as we compute values for each new row.
int distinctSubsequences(string &str, string &sub)
{
    int n = str.size();
    int m = sub.size();
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<int> prev(n + 1, 0), curr(m + 1, 0);

    // for (int i = 0; i <= n; i++) {
    //     dp[i][0] = 1; // An empty sub is a subsequence of any string
    // }
    // for (int j = 1; j <= m; j++) {
    //     dp[0][j] = 0; // Non-empty sub cannot be a subsequence of an empty string
    // }

    prev[0] = curr[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[i - 1] == sub[j - 1])
            {
                curr[j] = (prev[j - 1] + prev[j]) % mod;
            }
            else
            {
                curr[j] = prev[j] % mod;
            }
        }
        prev = curr;
    }

    return prev[m] % mod;
}

// A4
// dp[0][0] should be 1 because an empty string is a subsequence of any string.
#include <bits/stdc++.h>
int mod = 10e9 + 7;

// dp[i][j] means Count of all distinct subsequences of S2[0...j-1]
// in the string S1[0...i-1].
int distinctSubsequences(string &str, string &sub)
{
    int n = str.size();
    int m = sub.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1; // An empty sub is a subsequence of any string
    }
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = 0; // Non-empty sub cannot be a subsequence of an empty string
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[i - 1] == sub[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] % mod;
            }
        }
    }

    return dp[n][m];
}

// A3
//  Converted to 1-based Indexing

#include <bits/stdc++.h>
int mod = 1e9 + 7;
int solve(string &str, string &sub, int i, int j, vector<vector<int>> &dp)
{
    if (j == 0)
        return 1;
    if (i == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j] % mod;

    if (str[i - 1] == sub[j - 1])
    {
        return dp[i][j] = (solve(str, sub, i - 1, j - 1, dp) % mod + solve(str, sub, i - 1, j, dp) % mod) % mod;
    }
    else
    {
        return dp[i][j] = solve(str, sub, i - 1, j, dp) % mod;
    }
}

int distinctSubsequences(string &str, string &sub)
{
    int n = str.size();
    int m = sub.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(str, sub, n, m, dp) % mod;
}

// A2: For memoization

#include <bits/stdc++.h>
int mod = 10e9 + 7;
int solve(string &str, string &sub, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j] % mod;

    if (str[i] == sub[j])
    {
        return dp[i][j] = (solve(str, sub, i - 1, j - 1, dp) % mod + solve(str, sub, i - 1, j, dp) % mod) % mod;
    }
    else
    {
        return dp[i][j] = solve(str, sub, i - 1, j, dp) % mod;
    }
}

int distinctSubsequences(string &str, string &sub)
{
    int n = str.size();
    int m = sub.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(str, sub, n - 1, m - 1, dp) % mod;
}

// A1

#include <bits/stdc++.h>
int mod = 10e9 + 7;
int solve(string &str, string &sub, int i, int j)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (str[i] == sub[j])
    {
        return (solve(str, sub, i - 1, j - 1) % mod + solve(str, sub, i - 1, j) % mod) % mod;
    }
    else
    {
        return solve(str, sub, i - 1, j) % mod;
    }
}

int distinctSubsequences(string &str, string &sub)
{
    int n = str.size();
    int m = sub.size();

    return solve(str, sub, n - 1, m - 1);
}

// Practice
#include <bits/stdc++.h>
// void solve(string &str, int ind, string temp, unordered_map<string, int> &ans)
// {

//     if (ind < 0)
//     {

//         ans[temp]++;
//         return;
//     }

//     solve(str, ind - 1, temp, ans);

//     solve(str, ind - 1, temp + str[ind], ans);
// }

int distinctSubsequences(string &str, string &sub)
{
    int n = str.size();
    unordered_map<string, int> ans;
    string temp = "";
    solve(str, n - 1, temp, ans);

    //  int cnt=0;
    // for(auto v:ans)
    // {
    // 	cout<<v.first<<":"<<v.second<<endl;
    // 	cnt+=v.second;
    // }
    // cout<<cnt<<endl;
    // return -1;

    reverse(sub.begin(), sub.end());
    return ans[sub];
}