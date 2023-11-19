#include<stdio.h>
#include<string.h>
int main()
{
    char s[200];
    printf("Enter a string:");
    gets(s);
    int length=strlen(s);
    length=length-1;
    int i=0,count=0;
    while(s[length]>i)
    {
        if(s[length]!=s[i])
        {
            count++;
        }
        length--;
        i++;
    }
    if(count>0)
    {
        printf("No");
    }
    else
    {
        printf("Yes");
    }

    return 0;
}
