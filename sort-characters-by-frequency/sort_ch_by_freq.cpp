/*
Description:
Given a string, sort it in decreasing order based on the frequency of characters.

https://leetcode-cn.com/problems/sort-characters-by-frequency
https://leetcode.com/problems/sort-characters-by-frequency/

*/

#include<iostream>
using namespace std;
string frequencySort(string s) {
    int hash[128]={0};
    int max=0;
    string out;
    for(int i=0; i<s.size(); i++){
        hash[s[i]]++;
        if(max<hash[s[i]]){
            max = hash[s[i]];
        }
    }
    while(max){
        for(int i=0; i<128; i++){
            if(max == hash[i]){
                for(int j=0; j<max; j++){
                    out+=char(i);
                }
            }
        }
        max--;
    }
    return out;
}

int main(){
    string str;
    while(cin>>str){
        cout<<frequencySort(str)<<endl;
    }    
    return 0;
}