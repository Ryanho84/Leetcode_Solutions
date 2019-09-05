// two_sum.cpp : �������̨Ӧ�ó������ڵ㡣
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
		vector<pair<int, int>> nums1;        //����pair�����������洢��������
		for (int i = 0; i < nums.size(); ++i)
			nums1.push_back(make_pair(nums[i], i));   //�����������Ԫ�����β���nums1��ͬʱ�洢��ֵ�ͱ��
		sort(nums1.begin(), nums1.end());			//��nums1���� ����������
		int R = 0, L = nums1.size() - 1;            //��������ָ��
		vector<int> ret;                            //����洢����
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
	ʹ�õ�unordered_map�ṹ��unordered_map�ڲ�ʵ����һ����ϣ��Ҳ��ɢ�б�ͨ���ѹؼ���ֵӳ�䵽
	Hash����һ��λ�������ʼ�¼�����ҵ�ʱ�临�ӶȿɴﵽO(1),���ں������ݴ������й㷺��Ӧ�á���ˣ���
	Ԫ�����е�˳��������ġ�
**************************************************************************************/
class Solution2
{
public:
	vector<int> twoSum(vector<int>&nums, int target)
	{
		unordered_map<int, int> m;              //����һ��ɢ�б����洢nums��ִ�в���
		vector<int> res;                        //��������res�洢���
		for (int i = 0; i < nums.size(); i++)
		{
			m[nums[i]] = i;                     //�����������ֵɢ�е�m�С�
		}
		for (int i = 0; i < nums.size(); ++i)
		{
			int t = target - nums[i];               //�����ֵ
			if (m.count(t) && m[t] != i)               //����ɢ�б��ǳ��죩���ҵ���ֵ��Ӧ�ļ�ֵ������ǿգ����Ҳ�����i(Ҫ��ÿ����ֵ����ʹ�����Σ�����target=4������д��2+2)        
			{
				res.push_back(i);                  //��һ�����������ļ�ֵ������
				res.push_back(m[t]);               //�ڶ������������ļ�ֵ������
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

