#include<bits/stdc++.h>
using namespace std;

// function to find the lcs of two string
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            dp[i][j] = max(dp[i][j-1], dp[i][j]);
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
        }
    }
    return dp[m][n];
}

int main(){

    string text1 = "abcde", text2 = "axce";
    int lcs = longestCommonSubsequence(text1, text2);
    cout << "lcs: " << lcs <<"\n";

    return 0;
}   