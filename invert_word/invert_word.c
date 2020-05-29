#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char a[5000];
    int len=0, last,i;
    while(gets(a)!=NULL)
    {
        len = strlen(a);
        for(i=len-1; i>0; i--)
        {
            if(a[i]==' ')
            {
                last = i+1;
                while(a[last]!=' ')
                {
                    if(last==len)
                    {
                        break;
                    }
                    //if(isupper(a[last]) || islower(a[last]))
                    {
                        printf("%c", a[last]);
                    }
                    last++;
                }
                printf(" ");
            }
        }
        
        i=0;
        //while(isupper(a[i]) || islower(a[i]))
        while((a[i]>='a' && a[i]<='z') ||(a[i]>='A' && a[i]<='Z'))
        {
            printf("%c", a[i]);
            i++;
        }
    }
    return 0;
}
