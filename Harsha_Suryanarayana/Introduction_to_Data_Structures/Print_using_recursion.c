#include <stdio.h>
#include <stdlib.h>
#if 1

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Insert(struct Node *head, int data, int x)
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
        for (int i = 0; i < x - 2; i++) // 在第n个插入，在第n-1个下停下
        {
            head = head->next;
        }
        temp->next = head->next;
        head->next = temp;
    }

    return head;
}

void Delete(struct Node *head, int x)
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

void Print_using_recursion(struct Node *head)
{
    // 先打印再递归
    if (head != NULL)
    {
        printf("%d ", head->data);
        Print_using_recursion(head->next);
    }
    else
        printf("\n");
}

void ReversePrint_using_recursion(struct Node *head)
{
    // 先递归再打印，也即反向输出
    // 递归会让函数叠在栈里, 打印的时候, 出栈的返回值会倒叙送给print函数去打印
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    ReversePrint_using_recursion(head->next);
    printf("%d ", head->data);
}

int main()
{
    struct Node *head = NULL; // 在系统编程里尽量避免全局变量

    head = Insert(head, 2, 1); // 2
    head = Insert(head, 3, 2); // 2,3
    head = Insert(head, 4, 1); // 4,2,3
    head = Insert(head, 5, 2); // 4,5,2,3
    Print_using_recursion(head);
    ReversePrint_using_recursion(head);
    printf("\n");
    Delete(head, 2);
    Print_using_recursion(head);
    ReversePrint_using_recursion(head);
    printf("\n");
    Delete(head, 3);
    Print_using_recursion(head);
    ReversePrint_using_recursion(head);
    printf("\n");
}
#endif