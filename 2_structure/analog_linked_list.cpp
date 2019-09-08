//使用数组来实现模拟链表
#include <stdio.h>
int main()
{
    int data[101],right[101];//right存放每个元素右边的元素在data中的位置
    int i,n,t,len;
    scanf("%d",&n);//读入已经有的数
    for (i =1; i <=n;i++)
        scanf("%d",&data[i]);
    len =n;
    //初始化数组right
    for (i =1;i<=n;i++)
    {
        if(i!=n)
            right[i]=i+1;
        else
        right[i]=0;//最后一个元素右边没有元素，设为0
    }
    //直接在数组data尾部增加数
    len++;
    scanf("%d",&data[len]);
    //从链表头部开始遍历
    t=1;
    while(t!=0)
    {
        if(data[right[t]]>data[len])//如果当前结点的下一结点的值大于被插入的数，则插入
        {
            right[len]=right[t];//新插入数的下一结点标号=当前结点的下一结点
            right[t]=len;//
            break;
        }
        t=right[t];
    }
    //输出链表所有内容
    t=1;
    while(t!=0)
    {
        printf("%d ",data[t]);
        t=right[t];
    }
    getchar();getchar();
    return 0;
}