//排序的练习题，去重并排序
//先排序再去重，冒泡排序
#include <stdio.h>
int main() 
{
    int a[101],n,i,j,t;
    scanf("%d",&n);//读入n
    for(i=1;i<=n;i++)//循环读入n个编号
    {
        scanf("%d",&a[i]);
    }
    //冒泡排序
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("%d ",a[1]);//输出第一个数
    for(i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1])//是这个数第一次出现的时候则打印
        printf("%d ",a[i]);
    }
}