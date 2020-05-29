/*
calclate max continue 1 of a number in binary.
0x3 == b0000_0011

Input: 3
Output: 2
*/

#include<stdio.h>

int continuebit(int num){
    int max =0;
    int cnt=0;
    while(num>0){
        if((num&0x1)==0x1){
           cnt++;
           if(cnt>max) {
               max = cnt;
           }
        }
        else{
            if(cnt > max){
                max = cnt;
            }
            cnt = 0;
        }
        num = num>>1;
    }
    return max;
}

int main()
{
    while(scanf("%d",&num)!=EOF)
    {
        printf("%d\n", continuebit(num));
    }
    return 0;
}
