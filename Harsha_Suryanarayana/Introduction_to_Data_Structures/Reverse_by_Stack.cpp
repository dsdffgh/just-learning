#include <iostream>
#include <string.h>
#include "stdio.h"
#include <stack> //����ջ�Ŀ⺯��
using namespace std;

/*class Stack
{
private:
    char A[101];
    int top;
public:
    void Push(int x);
    void Pop();
    int Top();
    bool IsEmpty();
};
���ഴ��һ��ջ
*/

#if 1
// reverse string by stack

void Reverse(char *C, int n)
{
    stack<char> S;
    // loop for push
    for (int i = 0; i < n; i++)
    {
        S.push(C[i]);
    }
    // loop for pop
    for (int i = 0; i < n; i++)
    {
        C[i] = S.top();
        S.pop();
    }
}

int main()
{
    char C[51];
    printf("Enter the string:");
    //gets(C);�ú�����c++���Ѿ���֧����
    cin.getline(C,51) ;
    Reverse(C, strlen(C));
    printf("Output is :%s\n", C);
}
#endif

#if 0
//��������
//��������ʱ�临�Ӷ���O(n),�ռ临�Ӷ���O(1)
//�ݹ鶼��o(n),��ʽ��ʹ����ջ
void Reverse()
{
    if(head == NULL) return;
    stack<struct Node*> S;
    Node* temp = head;
    while(temp != NULL){
        S.push(temp);
        temp = temp->next;
    }
    temp = S.pop();
    head = temp;
    S.pop();
    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp = temp -> next;
    }
}
#endif