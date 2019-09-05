// two_num_add.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*����������
	���������ǿյ�����������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ�������ķ�ʽ�洢�ģ��������ǵ�ÿ��
	�ڵ�ֻ�ܴ洢һλ���֡�
	��������ǽ�������������������᷵��һ���µ������ʾ���ǵĺ͡�
	�����Լ����������0֮�⣬����������������0��ͷ

	ʾ�������룺 ��2->4->3) + ��5->6->4)
	     �����7->0->8
		 ԭ��342+465=807
*/
#include "stdafx.h"
#include <iostream>

using namespace std;



//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
//˼·һ��ֱ���������Ͻ��д�������������������λ�洢���൱�������Ҷ���ӷ������ʱע���λ��
//����λ������ͬ�����
//�㷨˼·��
/*
1. ���������ڵ�ָ�룬һ��ָ���������ͷ�ڵ㣬һ��ָ��ǰ��������β�ڵ�
2. ��ʼ����λֵΪ0
3. �����Ӧλ���ϵ�ֵ = v1 + v2 + ��λֵ��0/1��
4. ����͵�ֵ�����������Ǻ�֮����½ڵ��ֵ
5. ����͵�ֵ/10�����ǽ�λֵ���洢����
6. �����½ڵ�
7. �����ͷΪ�գ�˵���ոռ����һ�����ǽ�������ͷ�ڵ㣬head = cur
8. �����βΪ�գ�˵����ǰ�����ֻ��һ���ڵ㣬next���ǿգ�����ǿգ�˵������Ҫ���½ڵ���
9. ��β����
10. l1��l2���£��ж��Ƿ�Ϊ�գ����Ϊ�գ����軹��Ϊ�գ�����Ϊnext
*/
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
	ListNode *head = NULL, *prev = NULL;  //headΪ���������ı�ͷ��prevΪ���������ı�β�ڵ�
	int carry = 0;
	while (l1 || l2) {
		int v1 = l1 ? l1->val : 0;
		int v2 = l2 ? l2->val : 0;
		int tmp = v1 + v2 + carry;
		carry = tmp / 10;
		int val = tmp % 10;
		ListNode* cur = new ListNode(val);
		if (!head) head = cur;
		if (prev) prev->next = cur;
		prev = cur;
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
	}
	if (carry > 0) {
		ListNode* l = new ListNode(carry);
		prev->next = l;
	}
	return head;
}

//˼·2������������ת��Ϊ��������Ӻ���ת��Ϊ�����أ�
//��Ҫע��int�ͱ�ʾ�ķ�Χ����Ҫʱ��Ҫʹ��long int��longlong
ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
	//if (!l1 || !l2)  return(!l1) ? l2 : l1;

	long int n1 = 0, n2 = 0, n3 = 0, digit = 0, count = 1;
	ListNode *p = l1;
	while (p) {
		digit = p->val;
		n1 = n1 + digit*count;
		p = p->next;
		count *= 10;
	}
	p = l2;
	count = 1;
	while (p) {
		digit = p->val;
		n2 = n2 + digit*count;
		p = p->next;
		count *= 10;
	}

	n3 = n1 + n2;
	//cout << n3 << endl;   ����n3����ȷ��
	ListNode *res = new ListNode(n3 % 10);
	n3 /= 10;
	p = res;
	for (; n3>0; n3 /= 10) {
		ListNode *tmp = new ListNode(n3 % 10);
		//cout << tmp->val<<' ';    ��������������ȷ��
		p->next = tmp;
		p = tmp;
	}
	p->next = nullptr;
	return res;
}

void printNum(ListNode * num)
{
	while (num)
	{
		cout << num->val;
		if (num->next)
			cout << "->";
		num = num->next;
	}
	cout << endl;
}

int main()
{
	int num1[4] = { 2,4,3,8 };
	int num2[3] = { 5,6,4 };

	ListNode *n1 = new ListNode(0);
	ListNode *node1 = n1;

	for (int i = 0; i < sizeof(num1) / sizeof(int); i++)
	{
		node1->val = num1[i];
		if (i < sizeof(num1) / sizeof(int) - 1)     //��ֹ���һ�������潨��һ��û�õĽڵ�
		{
			ListNode *new_node1 = new ListNode(0);
			node1->next = new_node1;
			node1 = new_node1;
		}
	}
	node1->next = 0;
	printNum(n1);

	ListNode *n2 = new ListNode(0);
	ListNode *node2 = n2;


	for (int i = 0; i < sizeof(num2) / sizeof(int); i++)
	{
		node2->val = num2[i];
		if (i < sizeof(num2) / sizeof(int) - 1)   //��ֹ���һ���������н���һ��û�õĽڵ�
		{
			ListNode *new_node2 = new ListNode(0);
			node2->next = new_node2;
			node2 = new_node2;
		}
	}
	node2->next = 0;
	printNum(n2);

	ListNode *result = addTwoNumbers1(n1, n2);
	printNum(result);
	ListNode *result2 = addTwoNumbers2(n1, n2);
	printNum(result2);
}

