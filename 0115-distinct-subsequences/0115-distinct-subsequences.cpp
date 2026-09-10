class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        for (int i = 0; i <= m; i++) dp[i][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};




// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int m = t.size();

//         vector<int> dp(m + 1, 0);
//         dp[0] = 1;

//         for (char c : s) {
//             // Go backwards so dp[j-1] is still from the previous row
//             for (int j = m; j >= 1; j--) {
//                 if (c == t[j - 1]) {
//                     dp[j] += dp[j - 1];
//                 }
//             }
//         }

//         return dp[m];
//     }
// };
