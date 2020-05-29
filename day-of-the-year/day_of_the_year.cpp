/*
Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, 
return the day number of the year.

https://leetcode-cn.com/problems/day-of-the-year
https://leetcode.com/problems/day-of-the-year

*/


#include<iostream>
using namespace std;

bool isLeap(int year){
    if(year % 100 == 0 && year % 400 == 0){
        return true;
    }
    else if(year % 100 !=0 && year % 4== 0){
        return true;
    }
    else{
        return false;
    }
}

int dayOfYear(string date) {
    int Mday[13]={0, 31,28,31,30,31,30,31,31,30,31,30,31};
    int year=(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
    int month=(date[5]-'0')*10+(date[6]-'0');
    int cnt = 0;
    for(int i=1; i<month; i++){
        if(i==2){
            if(isLeap(year)){
                cnt += Mday[2]+1;
            }
            else{
                cnt += Mday[2];
            }
        }
        else{
            cnt += Mday[i];
        }
    }
    cnt += (date[8]-'0')*10 + (date[9]-'0');
    return cnt;
}

int main()
{
    string s;
    while(cin>>s){
        cout<<dayOfYear(date)<<endl;
    }
    return 0;
}