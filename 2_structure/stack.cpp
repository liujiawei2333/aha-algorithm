#include <stdio.h>
#include <string.h>
int main()
{
    char a[101],s[101];
    int i,len,mid,next,top;

    gets(a);//读入字符串
    len=strlen(a);//字符串的长度
    mid=len/2-1;//字符串的中点

    top=0;//栈初始化,top是指向栈顶的变量
    for(i=0;i<=mid;i++)//mid前面的字符写入栈
        s[++top]=a[i];//i++先使用i的值再计算，++i是先计算后使用i的值

    //判断字符串的长度的奇偶，找出进行匹配的起始下标
    if(len%2==0)
        next = mid+1;
    else
        next =mid+2;
    //匹配
    for(i=next;i<=len-1;i++)
    {
        if(a[i]!=s[top])
            break;
        top--;
    }
    if(top==0)//说明栈内所有字符都被匹配了
        printf("YES");
    else
    printf("NO");
    getchar();getchar();
    return 0;
}