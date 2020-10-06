#Edit Distance Problem
#Problem platform: LeetCode
#Problem Link: https://leetcode.com/problems/edit-distance/
/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

    1.Insert a character
    2.Delete a character
    3.Replace a character

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1));
       
        for(int i=0;i<=word1.length();i++){
            for(int j=0;j<=word2.length();j++){
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[word1.length()][word2.length()];
        
    }
};
