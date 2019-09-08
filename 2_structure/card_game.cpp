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
    struct queue q1,q2;//�ֱ��Ǽ��ҵ����ϵ���
    struct stack s;//�����ϵ���
    int book[10];//��������ϵ���
    int i,t;

    //��ʼ��
    q1.head = 1;q1.tail =1;
    q2.head = 1;q2.tail =1;//��ʾ������������
    s.top = 0;//����Ҳ����
    for (i=1;i<=9;i++)
        book[i]=0;//�����Щ���Ѿ�����������
    
    //�����Ҷ��˷ֱ�������
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
    //������ʼ��˫�����϶����Ƶ�ʱ���ѭ��
    while(q1.head<q1.tail && q2.head<q2.tail)
    {

        t=q1.data[q1.head];//�״��һ����
        //�жϼ��������ܷ�Ӯ
        if(book[t]==0)//������û��������
        {
            //��û��Ӯ��һ��
            q1.head++;//�״���������Ƴ���
            s.top++;
            s.data[s.top]=t;//������Ʒ������ӣ���ջ
            book[t]=1;//��������t����
        }
        else
        {
            //��Ӯ�����
            q1.head++;//�״���������Ƴ���
            q1.data[q1.tail]=t;//�ոմ�������ûض�β
            q1.tail++;
            while(s.data[s.top]!=t)//����Ӯ���Ʒ����β��ֱ�����ϳ�������t��ȵ���
            {
                book[s.data[s.top]]=0;//ȡ�����
                q1.data[q1.tail]=s.data[s.top];//���ϵ������η����β
                q1.tail++;
                s.top--;//ջ����һ����
            }
        }

        t=q2.data[q2.head];//�Ҵ��һ����
        //�ж����������ܷ�Ӯ
        if(book[t]==0)//������û��������
        {
            //��û��Ӯ��һ��
            q2.head++;//�Ҵ���������Ƴ���
            s.top++;
            s.data[s.top]=t;//������Ʒ������ӣ���ջ
            book[t]=1;//��������t����
        }
        else
        {
            //��Ӯ�����
            q2.head++;//�Ҵ���������Ƴ���
            q2.data[q2.tail]=t;//�ոմ�������ûض�β
            q2.tail++;
            while(s.data[s.top]!=t)//����Ӯ���Ʒ����β��ֱ�����ϳ�������t��ȵ���
            {
                book[s.data[s.top]]=0;//ȡ�����
                q2.data[q2.tail]=s.data[s.top];//���ϵ������η����β
                q2.tail++;
                s.top--;//ջ����һ����
            }
        }
    }
    if(q2.head==q2.tail)//�ҵ��ƴ����ˣ��ն���
    {
        printf("��win\n");
        printf("�׵�ǰ���е�����");
        for(i=q1.head;i<=q1.tail-1;i++)
            printf(" %d",q1.data[i]);
        if(s.top>0)//������������ƣ��������
        {
            printf("\n�����ϵ�����");
            for(i=1;i<=s.top;i++)
                printf(" %d",s.data[i]);
        }
        else
            printf("\n����û����");
    }
    else
    {
        printf("��win\n");
        printf("�ҵ�ǰ���е�����");
        for(i=q2.head;i<=q2.tail-1;i++)
            printf(" %d",q2.data[i]);
        if(s.top>0)//������������ƣ��������
        {
            printf("\n�����ϵ�����");
            for(i=1;i<=s.top;i++)
                printf(" %d",s.data[i]);
        }
        else
            printf("\n����û����");
    }
    getchar();getchar();
    return 0;
}