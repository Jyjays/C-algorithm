#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;
// class SqList {
//     public:
//         void CreateList(SqList *L, ElemType a[], int n);
//     private:
//         int length;

// };
// void SqList::CreateList(SqList *L, ElemType a[], int n) {
//     int i=0,k=0;
//     L = (SqList *)malloc(sizeof(SqList));
//     L->length = n;
// };

struct LNode {
    ElemType data;
    struct LNode *next;
};

typedef struct LNode LNode;        // 定义 LNode 类型
typedef struct LNode *LinkList;    // 定义 LinkList 为指向 LNode 的指针类型
void createList(LinkList &L, int n) {
    // L = (LinkList)malloc(sizeof(LNode));
    // L->next = NULL;
    // for (int i=0; i<n; i++) {
    //     LinkList p = (LinkList)malloc(sizeof(LNode));
    //     p->data = i;
    //     p->next = L->next;
    //     L->next = p;
    // }
}
