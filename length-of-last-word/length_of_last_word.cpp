/*
https://leetcode-cn.com/problems/length-of-last-word/
https://leetcode.com/problems/length-of-last-word/

*/

#include <iostream>
using namespace std;

int lengthOfLastWord(string s) {
    int len = 0;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i] != ' '){
            len++;
        }
        else{
            if(len!=0) return len;
        }
    }
    return len;
}

int main()
{
    string str;
    getline(cin, str);
    cout<<lengthOfLastWord(str);
    return 0;
}