#include <stdio.h>
#include <stdlib.h>//malloc函数需要
int main()
{
    int *p;//定义指向整型变量的指针p
    p = (int *)malloc(sizeof(int));//指针p获取动态分配的内存空间地址，malloc返回的是void*类型(未确定类型），强制转换为整型的指针
    *p=10;
    // p=&a;//指针p获取a的地址,&为取地址符
    printf("%d",*p);//输出指针p指向的内存的值，*为间接运算符
    getchar();getchar();
    return 0;
}