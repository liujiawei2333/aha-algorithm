#include <stdio.h>
struct student
{
    char name[21];
    char score;
};//创建结构体来存储姓名和分数
int main()
{
    struct student a[100],t;
    int i,j,n;
    scanf("%d",&n);//输入数n
    for(i=1;i<=n;i++)//循环读入n个人名和分数
        scanf("%s %d",a[i].name,&a[i].score);
        //分数从高到低排序
        for(i=1;i<=n-1;i++)
        {
            for(j=1;j<=n-i;j++)
            {
                if(a[j].score < a[j+1].score)//比较分数
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            }
        }
        for (i=1;i<=n;i++)
            printf("%s\n",a[i].name);//输出人名
        getchar();getchar();
        return 0;
}

//核心是双重嵌套循环，时间复杂度O（N^2)，速度太慢