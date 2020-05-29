/*
Input a string.
Output max sub-number-string of the string, and length of the sub-string.

Input:
abcd12345ed125ss123058789

Output:
123058789,9
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/* basic dynamic programming */
int main()
{
    string s;
    while(cin>>s){
        
        int dp[100] = {0}; 
        int m = 0;
        for(int i=0; i<s.size(); i++){
            if(i==0 && isdigit(s[i])){
                dp[i] = 1;
            }
            else if(isdigit(s[i])){
                dp[i] = dp[i-1]+1;
            }
            else{
                dp[i] = 0;
            }
            m = max(m, dp[i]);
        }
        for(int i=0; i<s.size(); i++){
            //cout<<dp[i];
            
            if(dp[i]==m){
                string s2;
                s2 = s.substr(i+1-m, m);
                cout<<s2;
            }
        }
        cout<<","<<m<<endl;
    }
}