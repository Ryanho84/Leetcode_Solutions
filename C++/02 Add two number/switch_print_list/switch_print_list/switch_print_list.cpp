// switch_print_list.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

void PrintList(ListNode * n)
{
	while (n)
	{
		cout << n->val;
		if (n->next)
			cout << "->";
		n = n->next;
	}
	cout << endl;
}

void AddTwoNums(ListNode * num1, ListNode *num2)
{
	ListNode * head = NULL;
	ListNode * prev = NULL;
	int carry = 0;
	while (num1 || num2)
	{
		int val1 = num1 ? num1->val : 0;
		int val2 = num2 ? num2->val : 0;
		int temp = val1 + val2 + carry;
		carry = temp / 10;
		ListNode *current = new ListNode(temp % 10);
		if (!head) head = current;
		if (prev) prev->next = current;
		prev = current;
		num1 = num1 ? num1->next : NULL;
		num2 = num2 ? num2->next : NULL;
	}
	if (carry)
	{
		ListNode *temp = new ListNode(carry);
		prev->next = temp;
		prev = temp;
	}
	PrintList(head);
}

int main()
{
	int num1[] = { 2,3,4,5 };
	int num2[] = { 5,6,7,8 };
	int num1_length = sizeof(num1) / sizeof(int);
	int num2_length = sizeof(num2) / sizeof(int);

	ListNode * n1= new ListNode(0);
	ListNode * p1 = n1;
	for(int i = 0; i < num1_length; i++)
	{
		p1->val = num1[i];
		if (i < num1_length - 1)
		{
			ListNode * temp = new ListNode(0);
			p1->next = temp;
			p1= temp;
		}
	}
	p1->next = 0;
	PrintList(n1);

	ListNode * n2 = new ListNode(0);
	ListNode * p2 = n2;
	for (int i = 0; i < num2_length; i++)
	{
		p2->val = num2[i];
		if (i < num2_length - 1)
		{
			ListNode * temp = new ListNode(0);
			p2->next = temp;
			p2 = temp;
		}
	}
	p2->next = 0;
	PrintList(n2);
	AddTwoNums(n1, n2);
    return 0;
}

