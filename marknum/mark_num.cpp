/*
Description: using * mark the ever number of string.

Input:
Jkdi234klowe90a3

Output:
Jkdi*234*klowe*90*a*3*
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    while(cin>>str){
        for(int i=0; i<str.size(); i++)
        {
            if(i==0 && isdigit(str[i])){
                str.insert(i, "*");
            }
            else if(!isdigit(str[i]) && isdigit(str[i+1])){
                str.insert(i+1, "*");
                i++;
            }
            else if(isdigit(str[i]) && !isdigit(str[i+1])){
                str.insert(i+1, "*");
                i++;
            }
        }
        cout<<str<<endl;
    }
    return 0;
}
