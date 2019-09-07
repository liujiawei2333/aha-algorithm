//排序的练习题，去重并排序
//使用桶排序，先去重再排序，去重就是不再计算每个桶插旗子的数量了，只要出现的都赋值为1即可
#include <stdio.h>
int main()
{
    int a[1001],n,i,t;
    for (i=1;i<=1000;i++)
        a[i]=0;//初始化
    scanf("%d",&n);//读入n
    for (i=1;i<=n;i++)//循环读入n个编号
    {
        scanf("%d",&t);//每个编号读入变量t
        a[t]=1;//标记出现过的编号（去重）
    }
    for (i=1;i<=1000;i++)//依次判断1000个桶
    {
        if (a[i]==1)//如果编号出现过则打印出来
            printf("%d ",i);
    }
    getchar();getchar();
    return 0;
}
//时间复杂度O（M+N)