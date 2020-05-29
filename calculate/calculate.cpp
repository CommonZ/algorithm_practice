/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, /, {, }, (, ), [, ]

input: string  "3+2*{1+2*[-4/(8-6)+7]}"
output: result of expression string

*/

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void preProcess(string &str){
    for(int i=0; i<str.size(); i++){
        if(str[i] == '[' || str[i]=='{'){
            str[i] = '(';
        }
        else if(str[i] == ']' || str[i] == '}'){
            str[i] = ')';
        }
        else if(str[i] == '-'){
            // add zero for minus 
            if(i==0 || str[i-1] == '(')
                str.insert(i, 1, '0');
        }
    }
}

bool cmpPriority(char top, char cur){
    /* return true if top >= cur */
    bool ret = false;
    if((top=='+'||top == '-') && (cur=='+' || cur=='-'))
        ret = true;
    if((top=='*'||top == '/') && (cur=='+' || cur=='-'))
        ret = true;
    if(cur==')')
        ret = true;
    return ret;
}

vector<string> mid2post(string &str)
{
    vector<string> vstr;
    stack<char> cstack;
    for(int i=0; i<str.size(); ++i)
    {
        string temp = "";
        if(isdigit(str[i]))
        {
            temp+=str[i];
            while(i+1<str.size() && isdigit(str[i+1]))
            {
                temp+=str[i+1];
                i++;
            }
            vstr.push_back(temp);
        }
        else if(cstack.empty() || str[i]=='(')
        {
            cstack.push(str[i]);
        }
        else if(cmpPriority(cstack.top(), str[i]))
        {
            if(str[i]==')')
            {
                temp = "";
                while(!cstack.empty() && cstack.top()!='(')
                {
                    temp+=cstack.top();
                    cstack.pop();
                    vstr.push_back(temp);
                    temp="";
                }
                cstack.pop();
            }
            else
            {
                while(!cstack.empty() && cmpPriority(cstack.top(), str[i]))
                {
                    temp+=cstack.top();
                    cstack.pop();
                    vstr.push_back(temp);
                    temp="";                    
                }
                cstack.push(str[i]);
            }
        }
        else
        {
            cstack.push(str[i]);
        }      
    }
    
    while(!cstack.empty())
    {
        string temp="";
        temp+=cstack.top();
        cstack.pop();
        vstr.push_back(temp);
    }  

    return vstr;
}

int calc(vector<string> & vstr)
{
    int num=0, op1, op2;
    stack<int> op;
    for(int i=0; i<vstr.size();i++){
        string temp=vstr[i];
        //if(isdigit(temp[0]))
        if(temp[0]>='0' && temp[0]<='9')
        {
            for(int j=0;j<temp.size();j++)
            {
                num=num*10+temp[j]-'0';
            }
            op.push(num);
            //cout<<"num:"<<num;
            num=0;
        }
        else if(vstr[i] == "+"){
            op2 = op.top();
            op.pop();
            op1 = op.top();
            op.pop();
            op.push(op1+op2);
        }
        else if(vstr[i] == "-"){
            op2 = op.top();
            op.pop();
            op1 = op.top();
            op.pop();
            op.push(op1-op2);
        }
        else if(vstr[i] == "*"){
            op2 = op.top();
            op.pop();
            op1 = op.top();
            op.pop();
            op.push(op1*op2);
        }
        else if(vstr[i] == "/"){
            op2 = op.top();
            op.pop();
            op1 = op.top();
            op.pop();
            op.push(op1/op2);
        }
    }
    return op.top();
}

int main(int argc, char** argv) {
    string exp;
    
    while(getline(cin, exp)){
        vector<string> vstr1,vstr2;
        
        preProcess(exp);
        vstr1 = mid2post(exp);
        int res = calc(vstr1);
        cout<<res<<endl;
        
    }
    return 0;
}