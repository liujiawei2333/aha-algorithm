#include <stdio.h>
struct queue
{
    int data[1000];
    int head;
    int tail;
};
struct stack
{
    int data[10];
    int top;
};

int main()
{
    struct queue q1,q2;//分别是甲乙的手上的牌
    struct stack s;//桌子上的牌
    int book[10];//标记桌子上的牌
    int i,t;

    //初始化
    q1.head = 1;q1.tail =1;
    q2.head = 1;q2.tail =1;//表示二人手中无牌
    s.top = 0;//桌上也无牌
    for (i=1;i<=9;i++)
        book[i]=0;//标记哪些牌已经在桌子上了
    
    //给甲乙二人分别六个牌
    for (i=1;i<=6;i++)
    {
        scanf("%d",&q1.data[q1.tail]);
        q1.tail++;
    }
    for (i=1;i<=6;i++)
    {
        scanf("%d",&q2.data[q2.tail]);
        q2.tail++;
    }
    //比赛开始，双方手上都有牌的时候才循环
    while(q1.head<q1.tail && q2.head<q2.tail)
    {

        t=q1.data[q1.head];//甲打出一张牌
        //判断甲这张牌能否赢
        if(book[t]==0)//桌子上没有这张牌
        {
            //甲没有赢这一轮
            q1.head++;//甲打出的这张牌出队
            s.top++;
            s.data[s.top]=t;//打出的牌放入桌子，入栈
            book[t]=1;//桌上有了t的牌
        }
        else
        {
            //甲赢了这局
            q1.head++;//甲打出的这张牌出队
            q1.data[q1.tail]=t;//刚刚打出的牌拿回队尾
            q1.tail++;
            while(s.data[s.top]!=t)//桌上赢的牌放入队尾，直到桌上出现了与t相等的牌
            {
                book[s.data[s.top]]=0;//取消标记
                q1.data[q1.tail]=s.data[s.top];//桌上的牌依次放入队尾
                q1.tail++;
                s.top--;//栈少了一张牌
            }
        }

        t=q2.data[q2.head];//乙打出一张牌
        //判断乙这张牌能否赢
        if(book[t]==0)//桌子上没有这张牌
        {
            //乙没有赢这一轮
            q2.head++;//乙打出的这张牌出队
            s.top++;
            s.data[s.top]=t;//打出的牌放入桌子，入栈
            book[t]=1;//桌上有了t的牌
        }
        else
        {
            //乙赢了这局
            q2.head++;//乙打出的这张牌出队
            q2.data[q2.tail]=t;//刚刚打出的牌拿回队尾
            q2.tail++;
            while(s.data[s.top]!=t)//桌上赢的牌放入队尾，直到桌上出现了与t相等的牌
            {
                book[s.data[s.top]]=0;//取消标记
                q2.data[q2.tail]=s.data[s.top];//桌上的牌依次放入队尾
                q2.tail++;
                s.top--;//栈少了一张牌
            }
        }
    }
    if(q2.head==q2.tail)//乙的牌打完了，空队列
    {
        printf("甲win\n");
        printf("甲当前手中的牌是");
        for(i=q1.head;i<=q1.tail-1;i++)
            printf(" %d",q1.data[i]);
        if(s.top>0)//如果桌子上有牌，将其输出
        {
            printf("\n桌子上的牌是");
            for(i=1;i<=s.top;i++)
                printf(" %d",s.data[i]);
        }
        else
            printf("\n桌上没有牌");
    }
    else
    {
        printf("乙win\n");
        printf("乙当前手中的牌是");
        for(i=q2.head;i<=q2.tail-1;i++)
            printf(" %d",q2.data[i]);
        if(s.top>0)//如果桌子上有牌，将其输出
        {
            printf("\n桌子上的牌是");
            for(i=1;i<=s.top;i++)
                printf(" %d",s.data[i]);
        }
        else
            printf("\n桌上没有牌");
    }
    getchar();getchar();
    return 0;
}