
#include<stdio.h>
#include<stdlib.h>

// 定义链表节点结构体
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode_t;

// 删除倒数第n个节点的函数声明
ListNode_t *delNode(ListNode_t *head, int n);

// 实现删除倒数第n个节点的函数
ListNode_t *delNode(ListNode_t *head, int n) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    ListNode_t *former = head;
    ListNode_t *latter = head;

    // 将 former 指针向前移动 n+1 步
    while (n--) {
        if (former == NULL) {
            printf("n is larger than length of list\n");
            return head; // 如果 n 大于链表长度，返回 NULL
        }
        former = former->next;
    }

    // 特殊情况处理：删除的是头节点
    if (former == NULL) {
        head = head->next;
        free(latter);
        return head;
    }

    // 一起移动直到 former 到达链表末尾
    while (former->next != NULL) {
        former = former->next;
        latter = latter->next;
    }

    // 删除 latter->next 节点
    ListNode_t *temp = latter->next;
    latter->next = latter->next->next;
    free(temp);

    return head;
}

// 示例用法
int main() {
    // 创建链表：1 -> 2 -> 3 -> 4 -> 5
    ListNode_t *head = malloc(sizeof(ListNode_t));
    head->val = 1;
    head->next = malloc(sizeof(ListNode_t));
    head->next->val = 2;
    head->next->next = malloc(sizeof(ListNode_t));
    head->next->next->val = 3;
    head->next->next->next = malloc(sizeof(ListNode_t));
    head->next->next->next->val = 4;
    head->next->next->next->next = malloc(sizeof(ListNode_t));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    // 删除倒数第2个节点
    int n = 2;
    head = delNode(head, n);

    // 打印链表
    ListNode_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
