#include <stdio.h>
int main()
{
    int q[102]={0,6,3,1,7,5,8,9,2,4},head,tail;//0只是用来填充q[0]的
    int i;
    head =1;//初始化队列，head记录第一位的数字
    tail =10;//tail指向队尾最后一个位置，即最后一个有效数字的下一位
    while (head < tail)//队列不为空时循环
    {
        printf("%d ",q[head]);//打印队首
        head++;//队首的数字移出，下一位成为新的队首
        q[tail]=q[head];//新队首添加到队尾
        tail++;
        head++;//新队首在移动中被去除
    }
    getchar();getchar();
    return 0;
}

//队列：特殊的线性结构，只能在首部（head）删除“出队”，在尾部（tail）插入“入队”，先进先出（FIFO）
//head=tail时，空队列