// two_sum_2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void two_sum(vector<int> & num, int target)
{
	sort(num.begin(), num.end());
	int L = 0;
	int R = num.size() - 1;
	while (L < R)
	{
		if ((num[L] + num[R]) > target)
			R--;
		if ((num[L] + num[R]) < target)
			L++;
		if ((num[L]) + num[R] == target)
		{
			cout << L << ' ' << R << endl;
			break;
		}l
	}
	if (L >= R)
		cout << "û���ҵ�" << endl;
}



int main()
{
	vector<int> vi = { 2,7,11,15 };
	int target = 9;
	two_sum(vi, target);
}

