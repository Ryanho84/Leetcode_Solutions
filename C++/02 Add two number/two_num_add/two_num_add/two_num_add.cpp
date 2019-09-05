// two_num_add.cpp : 定义控制台应用程序的入口点。
//
/*问题描述：
	给出两个非空的链表用来表示两个非负的整数。其中，他们各自的位数是按照逆序的方式存储的，并且他们的每个
	节点只能存储一位数字。
	如果，我们将这两个数加起来，则会返回一个新的链表表示他们的和。
	您可以假设除了数字0之外，这两个数都不会以0开头

	示例：输入： （2->4->3) + （5->6->4)
	     输出：7->0->8
		 原因：342+465=807
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
//思路一：直接在链表上进行处理，由于链表是逆序数位存储，相当于整数右对齐加法，相加时注意进位及
//两数位数不相同的情况
//算法思路：
/*
1. 定义两个节点指针，一个指向结果链表的头节点，一个指向当前结果链表的尾节点
2. 初始化进位值为0
3. 计算对应位数合的值 = v1 + v2 + 进位值（0/1）
4. 计算和的值的余数，就是和之后改新节点的值
5. 计算和的值/10，就是进位值，存储起来
6. 创建新节点
7. 如果表头为空，说明刚刚计算第一个，是结果链表的头节点，head = cur
8. 如果表尾为空，说明当前结果中只有一个节点，next还是空；如果非空，说明后面要接新节点了
9. 表尾更新
10. l1、l2更新，判断是否为空，如果为空，就设还设为空；否则为next
*/
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
	ListNode *head = NULL, *prev = NULL;  //head为结果数链表的表头，prev为结果数链表的表尾节点
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

//思路2：将两个链表转换为整数，相加后再转换为链表返回，
//需要注意int型表示的范围，必要时需要使用long int或longlong
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
	//cout << n3 << endl;   测试n3的正确性
	ListNode *res = new ListNode(n3 % 10);
	n3 /= 10;
	p = res;
	for (; n3>0; n3 /= 10) {
		ListNode *tmp = new ListNode(n3 % 10);
		//cout << tmp->val<<' ';    测试链表建立的正确性
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
		if (i < sizeof(num1) / sizeof(int) - 1)     //防止最后一个数后面建立一个没用的节点
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
		if (i < sizeof(num2) / sizeof(int) - 1)   //防止最后一个数后面有建立一个没用的节点
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

