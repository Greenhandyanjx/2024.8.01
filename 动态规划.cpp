#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int change(int amount, vector<int>& coins) {
    vector<int>dp(10001, 0);
    int res = 0;
    dp[0] = 1;
    //for (int i = 0; i < coins.size(); i++) {
    //    for (int j = coins[i]; j <= amount; j++) {
    //        dp[j] += dp[j - coins[i]];
    //    }
    //}
    for (int j = 0; j <= amount; j++) {
        for (int i = 0; i < coins.size(); i++) {
            if(j>=coins[i])
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}
int main() {
    vector<int>coins{ 1,2,5 };
    int a = 5;
    int p = change(a, coins);
    return 0;
}
//class Solution {
//public:
//    int change(int amount, vector<int>& coins) {
//        vector<int>dp(10001, 0);
//        int res = 0;
//        dp[0] = 1;
//        for (int i = 0; i < coins.size(); i++) {
//            for (int j = coins[i]; j <= amount; j++) {
//                dp[j] += dp[j - coins[i]];
//                if (dp[j] == amount)res++;
//            }
//        }
//        return res;
//    }
//};
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
//        for (auto str : strs) {
//            int x = 0, y = 0;
//            for (char a : str) {
//                if (a == 'x')x++;
//                else y++;
//            }
//            for (int i = m; i >= x; i--) {
//                for (int j = n; j >= y; j--) {
//                    dp[i][j] = max(dp[i - x][j - y] + 1, dp[i][j]);
//                }
//            }
//        }
//        return dp[m][n];
//    }
//};