// two_sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution1
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<pair<int, int>> nums1;        //定义pair类型向量，存储输入数组
		for (int i = 0; i < nums.size(); ++i)
			nums1.push_back(make_pair(nums[i], i));   //将输入数组各元素依次插入nums1，同时存储键值和编号
		sort(nums1.begin(), nums1.end());			//对nums1排序 （快速排序）
		int R = 0, L = nums1.size() - 1;            //设置左右指针
		vector<int> ret;                            //结果存储向量
		while (R < L)
		{
			if ((nums1[R].first + nums1[L].first) == target)
			{
				ret.push_back(nums1[R].second);
				ret.push_back(nums1[L].second);
				return ret;
			}
			nums1[R].first + nums1[L].first < target ? ++R : --L;
		}
	}
};

/*************************************************************************************
	使用到unordered_map结构。unordered_map内部实现了一个哈希表，也叫散列表，通过把关键字值映射到
	Hash表中一个位置来访问记录，查找的时间复杂度可达到O(1),其在海量数据处理中有广泛的应用。因此，其
	元素排列的顺序是无序的。
**************************************************************************************/
class Solution2
{
public:
	vector<int> twoSum(vector<int>&nums, int target)
	{
		unordered_map<int, int> m;              //定义一个散列表，来存储nums并执行操作
		vector<int> res;                        //定义向量res存储结果
		for (int i = 0; i < nums.size(); i++)
		{
			m[nums[i]] = i;                     //将输入数组键值散列到m中。
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			int t = target - nums[i];               //计算差值
			if (m.count(t) && m[t] != i)               //遍历散列表（非常快），找到差值对应的键值如果不是空，并且不等于i(要求每个键值不能使用两次，比如target=4，不能写成2+2)        
			{
				res.push_back(i);                  //第一个满足条件的键值的索引
				res.push_back(m[t]);               //第二个满足条件的键值的索引
				break;
			}
		}
		return res;
	}
};

int main()
{
	Solution1 solution1;
	Solution2 solution2;
	vector<int> A = {2,7,11,15},B,C;
	int target = 9;
	B = solution1.twoSum(A, target);
	C = solution2.twoSum(A, target);
	for (int i = 0; i < B.size(); i++)
		cout << B[i] << ",";
	cout << endl;
	for (int j = 0; j < C.size(); j++)
		cout << C[j] << ",";
	cout << endl;
    return 0;
}

