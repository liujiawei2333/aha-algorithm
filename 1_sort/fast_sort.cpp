//快速排序：“二分法”，每次排序的时候设置一个基准点，使得左边的比它小，右边的比它大。跳跃式的交换
#include <stdio.h>
int a[101],n;//全局变量
void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right)
        return;
    
    temp = a[left];//temp保存的是基准数，基准数取左边第一个
    i=left;
    j=right;
    while(i!=j)//当i和j在中间相遇时跳出循环
    {
        while(a[j]>=temp && i<j)//与，从右往左找
            j--;
        while(a[i]<=temp && i<j)//从左往右找
            i++;

        //交换两个数在数组中的位置
        if(i<j)//哨兵i和j没有相遇时
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    //将基准数归位
    a[left]=a[i];//把现在的最中间的数放到最左边
    a[i]=temp;//把原来最左边的数（基准数）放到中间

    quicksort(left,i-1);//继续处理左边的，递归
    quicksort(i+1,right);//继续处理右边的，递归
}

int main()
{
    int i,j,t;
    scanf("%d",&n);//读入数据
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    quicksort(1,n);//快速排序调用

    //输出排序结果
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    getchar();getchar();
    return 0;
}

//时间复杂度O(NlogN)