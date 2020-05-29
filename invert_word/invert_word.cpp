/*
Question description:
Input: a sentence include space
Ouput: output the inverted sentence

example:
input:
I am a student
output:
student a am I

*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main()
{
    string s;
    while(getline(cin,s)){
        vector<string> vs;
        int i, cnt = 0;
        for(i=0; i<s.size(); i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                cnt++;
            }
            else if(cnt){
                vs.push_back(s.substr(i-cnt, cnt));
                cnt = 0;
            }
        }
        if(cnt){
            vs.push_back(s.substr(i-cnt, cnt));
        }
        
        for(int i = vs.size()-1; i>0; i--){
            cout<<vs[i]<<' ';
        }
        cout<<vs[0]<<endl;
    }
    return 0;
}