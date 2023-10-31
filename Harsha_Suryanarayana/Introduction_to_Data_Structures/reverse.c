// 反转链表：1，迭代；2递归
// 1,每到一个结点就使其指向上一个节点
#include <stdio.h>
#include <stdlib.h>
#if 1

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void Reverse() // 迭代方法实现
{
    /*
    struct Reverse *prev,temp;
    prev = NULL;
    temp = head;
    while(temp != NULL)
    {
        temp->next = prev;//修改以后无法移动到下一个
    }
    */
    struct Node *prev, *current, *next;
    prev = NULL;
    current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void Reverse_recursion(struct Node *temp) // 递归方法实现
{
    if (temp->next == NULL)
    {
        head = temp;
        return;
    }
    Reverse_recursion(temp->next);
    temp->next->next = temp; // 反转指向
    temp->next = NULL;       // 剪掉原来的链接
}

void Insert(int data, int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (x == 1)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        struct Node *temp0 = head;
        for (int i = 0; i < x - 2; i++) // 在第n个插入，在第n-1个下停下
        {
            temp0 = temp0->next;
        }
        temp->next = temp0->next;
        temp0->next = temp;
    }
}

void Print()
{
    struct Node *temp = head;
    printf("list is ");
    while (temp != NULL) // 遍历链表
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Delete(int x)
{
    // 1.fix the links
    // 2.free the space
    struct Node *temp = head;
    if (x == 1)
    {
        head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < x - 2; i++) // 在第n-1个下停下
    {
        temp = temp->next;
    }
    struct Node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2); // delete temp2;
}

int main()
{
    head = NULL;

    int n, i, x, data;
    // scanf("%d", &n);
    // for (i = 0; i < n; i++)
    //{
    //     scanf("%d", &data);
    //     scanf("%d", &x);
    //     Insert(data, x); // data，position
    //     Print(head);
    // }
    Insert(2, 1); // 2
    Insert(3, 2); // 2,3
    Insert(4, 1); // 4,2,3
    Insert(5, 2); // 4,5,2,3
    Print();
    Reverse_recursion(head);
    Print();
    Reverse();
    Print();
    Delete(2);
    Print();
    Delete(3);
    Print();
    Reverse();
    Print();
}

#endif