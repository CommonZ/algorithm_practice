/*
https://leetcode-cn.com/problems/longest-common-subsequence/
https://leetcode.com/problems/longest-common-subsequence/
*/

#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();
    vector<vector<int> > dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    int maxlen = 0;
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(text1[i] == text2[j]){
                dp[i+1][j+1] = dp[i][j]+1;
            }
            else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
            maxlen = max(maxlen, dp[i+1][j+1]);
        }
    }
    return maxlen;
}

int main()
{
    string s1, s2;
    while(cin>>s1>>s2){
        cout<<longestCommonSubsequence(s1, s2)<<endl;
    }

    return 0;
}