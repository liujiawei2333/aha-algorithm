#include <stdio.h>
#include <stdlib.h>
//创建结构体表示链表的结点类型，往链表里插入数
struct node
{
    int data;
    struct node *next;//后继指针，表示下一个结点的地址；下一个结点的类型也是struct node
};

int main()
{
    struct node *head,*p,*q,*t;//p为临时指针，q为最终指针
    int i,n,a;
    scanf("%d",&n);
    head =NULL;//头指针初始为空
    for(i=1;i<=n;i++)//循环读入n个数
    {
        scanf("%d",&a);
        //动态申请一个空间，存放结点，临时指针p指向这个结点
        p = (struct node *)malloc(sizeof(struct node));
        p->data =a;//数据存到当前结点的data域，->为结构体指针运算符，用来访问结构体内部成员
        p->next =NULL;//当前结点的后继指针指向空，即下一个节点为空
        if(head==NULL)//头指针的作用是方便从头遍历整个链表
            head=p;//如果是第一个创建的结点，则头指针指向这个结点
        else
            q->next=p;//如果不是，则上个结点的后继指针指向当前结点
        
        q=p;//q也指向当前结点p，每次循环指针p将指向新创立的结点
    }

    scanf("%d",&a);//读入要插入的数
    t=head;//从链表头部开始遍历
    while(t!=NULL)//没有达到链表尾部的时候循环
    {
        if(t->next->data>a)//如果当前结点的下一个结点的值大于待插入的数，将其插入中间
        {
            p=(struct node *)malloc(sizeof(struct node));//申请用来存放新结点的空间
            p->data=a;
            p->next=t->next;//新增结点的后继指针指向新增结点
            t->next=p;//当前结点的后继指针指向新增结点
            break;
        }
        t=t->next;//继续下一个结点
    }
    
    //输出链表的所有数
    t=head;
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;//继续下一个结点
    }
    getchar();getchar();
    return 0;
}