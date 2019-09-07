//冒泡排序:每次比较两个相邻的元素，如果顺序不对就调换
//每一趟只将一个数归位

#include <stdio.h>
int main()
{
    int a[100],i,j,t,n;
    scanf("%d",&n);//需要排列的有n个数
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);//x循环读n个数到数组a中

        //核心部分
        for(i=1;i<=n-1;i++)//n个数排序，进行n-1趟
        {
            for(j=1;j<=n-i;j++)//第一个数开始循环到最后一个还没有归位的数
            {
                if(a[j]<a[j+1])//比较大小并交换，把小的换到前面来
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            }
        }

        for(i=1;i<=n;i++)//输出结果
            printf("%d ",a[i]);
        getchar();getchar();
        return 0;
}