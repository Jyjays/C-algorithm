#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
typedef struct ListNode ListNode;
ListNode* CreateNode(int x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	assert(node);
	node->val = x;
	node->next = NULL;
	return node;
}
ListNode* ll;
struct ListNode* meigeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}
	//�����µ�����
	ListNode* newHead = NULL, * newTail = NULL;
	ListNode* l1 = list1;
	ListNode* l2 = list2;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			if (newHead == NULL)
			{
				newHead = newTail = l1;
			}
			else
			{
				newTail->next = l1;
				newTail = newTail->next;
			}
			l1 = l1->next;
		}
		else
		{
			if (newHead == NULL)
			{
				newHead = newTail = l2;
			}
			else
			{
				newTail->next = l1;
				newTail = newTail->next;
			}
			l2 = l2->next;
		}
	}
	//����ѭ��
	if (l1)
	{
		newTail->next = l1;
	}
	if (l2)
	{
		newTail->next = l2;
	}
	ll = newHead;
	return newHead;
}
int main()
{
	int arr[30] = { 0 };
	for (int i = 0; i < 30; i++)
	{
		scanf("%d", &arr[i]);
	}
	ListNode* a[30];
	for (int j = 0; j < 30; j++)
	{
		a[j] = CreateNode(arr[j]);
	}
	a[0]->next = a[1];
	a[1]->next = a[2];
	a[2]->next = a[3];
	a[3]->next = a[4];
	a[4]->next = a[5];
	a[5]->next = a[6];
	a[6]->next = a[7];
	a[7]->next = a[8];
	a[8]->next = a[9];
	a[9]->next = a[10];
	a[10]->next = a[11];
	a[11]->next = a[12];
	a[12]->next = a[13];
	a[13]->next = a[14];
	a[14]->next = NULL;
	a[15]->next = a[16];
	a[16]->next = a[17];
	a[17]->next = a[18];
	a[18]->next = a[19];
	a[19]->next = a[20];
	a[20]->next = a[21];
	a[21]->next = a[22];
	a[22]->next = a[23];
	a[23]->next = a[24];
	a[24]->next = a[25];
	a[25]->next = a[26];
	a[26]->next = a[27];
	a[27]->next = a[28];
	a[28]->next = a[29];
	a[29]->next = NULL;

	meigeTwoLists(a[0], a[15]);
	while (ll != NULL)
	{
		printf("%d ", ll->val);
		ll = ll->next;
	}

	return 0;
}
//int main()
//{
//	//���������
//	int n = 0;
//	scanf("%d", &n);
//	//���뾰�������
//	int arr[1000];  
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &(arr[i]));
//	}
//	//�ܵ�˼·�ǰ�ÿһ�ֿ��ܶ��ų�����Ȼ����һ������������
//	int number[1000] = { 0 };
//
//
//	return 0;
//}