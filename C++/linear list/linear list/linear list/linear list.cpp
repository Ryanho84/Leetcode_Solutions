// linear list.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
���Ա�
	ȫ���й����Ա����Ŀ��������Ŀ�������Ա�Ĳ������������顢������˫������ȡ�
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


/*
The 1st:Remove Duplicates from Sorted Array
Description:
	Given a sorted array, remove the duplicates in place such that each 
	element appear only once and return the new length.
	Do not allocate extra space for another array, you must do this in 
	place with constant memory.
	For example, Given input array A = [1,1,2].
	Your function should return length = 2, and A is now [1,2]
*/

//Leetcode�� Remove Duplicates from Sorted Array
class Solution_1st{
public:
	//ʱ�临�Ӷ�O(n), �ռ临�Ӷ�O(1)
	int removeDuplicates_1(vector<int> &nums) {
		if (nums.empty())
			return 0;
		int index = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[index] != nums[i])
				nums[++index] = nums[i];
		}
		return index + 1;
	}
	//ʹ��STL��ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
	int removeDuplicates_2(vector<int> &nums) {
		//STL unique()������һ��ȥ�غ��� unique�Ĺ�����ȥ�����ڵ��ظ�Ԫ��(ֻ����һ��),
		//��ʵ�������������ظ���Ԫ��ɾ�����ǰ��ظ���Ԫ���Ƶ�����ȥ�ˣ�Ȼ����Ȼ���浽��ԭ
		//�����У�Ȼ�� ����ȥ�غ����һ��Ԫ�صĵ�ַ
		vector<int>::iterator it = unique(nums.begin(), nums.end());
		//nums.erase(it, nums.end());
		//for (int i = 0; i < nums.size(); i++)
		//{
			//cout << nums[i] << ' ';
		//}
		return distance(nums.begin(), it);
	}
};

/*
The 2nd: Remove Duplicates from Sorted Array II
Description:
	Follow up for "Remove Duplicates" : What if duplicates are allowed at most twice?
	For example, Given sorted array A = [1,1,1,2,2,3]
	Your function should return length = 5,and A is now [1,1,2,2,3]
*/
/*
������
	��һ��������¼��һ��Ԫ�س��ֵĴ�������
*/
//Leetcode, Remove Duplicates from Sorted Array II 
class Solution_2nd {
public:
	int removeDuplicates(vector<int> &nums) {
		int index = 0;
		//�ǳ����indexʼ�ձ�iС����λ�ã��л������ڵ�˼�룬�̶���Ȼ�������
		for (int i = 0; i < nums.size(); i++)
		{
			if (index < 2 || nums[i] > nums[index - 2])
				nums[index++] = nums[i];
		}

		return index;
	}

	int removeDuplicates(vector<int> &nums, int n) {
		int index = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (index < n || nums[i] > nums[index - n])
				nums[index++] = nums[i];
		}
		return index;
	}
};
/*
The 3rd: Search in Rotated Sorted Array
Description:
	Supporse a sorted array is rotated at some pivot unknown to you beforehand.
	(i.e.,0 1 2 3 4 5 6 7 8 9 10 might become 7 8 9 10 0 1 2 3 4 5 6����
	You are given a target value to search. If found in the array return its index, otherwise return -1.
	You may assume no duplicate exists in the array.
*/
/*
������
	ƽʱ���Ƕ��ַ���ʱ��ֱ���ж����е��Ŀ��Ĺ�ϵ���Ϳ���֪��Ŀ������벿�ֻ����Ұ벿���ˣ��ⱳ����ʵ����һ�����裬
	�Ǿ��Ǵ���㵽�յ���һ����������С��������У�������ǻ�����������ַ����������Ͳ������ˣ���Ϊ����㵽�յ��п�
	���и���Ƭ����������ת����������һ���ص㣬���豾���Ǹ��������У��������ҡ������ߵĵ���ұߵĵ�С��˵����������
	֮��������ģ���������ת�㡣�����ߵĵ���ұߵĴ�˵����������֮����һ����ת�㣬�����˲���������Ϊֻ��һ����
	ת�㣬����һ��Ϊ���󣬿϶���һ��������ġ����ԣ����ǻ��ǿ����ö��ַ�������Ҫ���ж������������Ұ���������
	����������ֱ�ӽ�Ŀ������ߵı߽�Ƚϣ���֪��Ŀ���ڲ��������ˣ�����������߿϶����Ұ�ߡ�ͬ������Ұ�
	��������ֱ�ӽ�Ŀ����Ұ�ߵı߽�Ƚϣ���֪��Ŀ���ڲ����Ұ���ˣ���������Ұ�߿϶������ߡ�����������˶��֡�
	���ǲ����ܰ�����������Ķ��ַ����жϣ�
	if(target < array[mid])
		target in [first, mid - 1]
		last = mid - 1
	else
		target in [mid + 1, last]
		first = mid + 1

	���Ǹ���mid��target�Ĺ�ϵ����������������array[first] <= array[mid],˵��ǰ���������ģ���ô���Ǿ�ֱ���ж�
	target����ǰ��ػ��Ǻ����ˣ����array[first] > array[mid],˵������������ģ���ô���Ǿ�ֱ���ж�target����
	���ػ���ǰ����ˣ���֮��targetһ�����ն���һ�����������еģ����������ַ��Ϳ����ˡ�
*/

//ʱ�临�Ӷ�O(logn),�ռ临�Ӷ�O(1)
class Solution_3rd {
public:
	int search(const vector<int> & nums, int target)
	{
		int first = 0, last = nums.size() - 1;
		//cout << last << endl;
		while(first <= last){
			int mid = (int)(first + last) / 2;
			//cout << mid << endl;
			if (nums[mid] == target)
				return mid;
			//�����벿���������
			if (nums[first] <= nums[mid])
			{
				if (nums[first] <= target && target < nums[mid])
					last = mid - 1;
				else
					first = mid + 1;
			}
			//����Ұ벿���������
			else {
				if (nums[mid] < target && target <= nums[last])
					first = mid + 1;
				else
					last = mid - 1;
			}
		}
		return -1;
	}
};
/*
The 4th: Median of two Sorted Arrays
Description: There are two sorted arrays A and B size m and n respectively.
             Find the median of the two sorted arrays. The overall run time
			 complexity should be O(log(m+n))
*/
/*
����������һ���ǳ��������Ŀ�������ͨ�õ���ʽ�ǣ����������Ѿ��źõ����飬�ҵ���������Ԫ����K���Ԫ�ء�
1. merge�������飬Ȼ�����k���Ԫ�أ���ʱ�临�Ӷ���O(m+n);
2. ʹ��һ������������¼��ǰ�Ѿ��ҵ��ĵ�m���Ԫ�ء�ͬʱʹ������ָ��pa,pb, �ֱ�ָ��A��B�ĵ�һ��Ԫ�ء����
   ����A��ǰԪ��С����ôpa++��ͬʱm++���������B��ǰԪ��С����ôpb++��ͬʱm++�����յ�m����K��ʱ�򣬾�
   �õ����ǵĴ��ˣ�ʱ�临�Ӷ���O(k), O��1���ռ临�Ӷȡ�����k�ӽ�m+nʱ��ʱ�临�ӶȻ���O(m+n).
3. ����A��B��Ԫ�ظ���������k/2�����ǽ�A�ĵ�k/2��Ԫ�أ���A[k/2 - 1]��B�ĵ�k/2��Ԫ�أ���B[k/2 - 1]����
   �Ƚϣ������������
   1�� A[k/2 - 1] == B[K/2 - 1]��˵�����ֵ���Ǿ�������Ҫ�ҵ�Kֵ
   2�� A[K/2 - 1] > B[k/2 - 1]��˵������Ҫ�ҵ�Kֵһ������B��ǰk/2�У���ô��B��ǰK/2��̭������B����ʼ
	   λ������ƶ�K/2������K��ֵ����Ϊk/2��
   3�� A[k/2 - 1] < B[k/2 -1]:˵������Ҫ�ҵ�Kֵһ������A��ǰk/2�У���ô��A��ǰK/2��̭������B����ʼ
	   λ������ƶ�K/2������K��ֵ����Ϊk/2��
*/
#define INT_MAX 100000
class Solution_4th {
public:
	//merge:ʱ�临�Ӷ�ΪO(m+n)���ռ临�Ӷ���O(m+n)
	int findtheKthNum_1(vector<int> &a, vector<int> &b, int k)
	{
		if (k > a.size() + b.size())
		{
			cout << "Error" << endl;
			return -1;
		}
		vector<int> merged;
		merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(merged));
		return merged[k - 1];
	}

	//˫ָ�뷨�����ʱ�临�Ӷ�ΪO(m+n), �ռ临�Ӷ�ΪO(1)
	int findtheKthNum_2(vector<int> &a, vector<int> &b, int k)
	{
		if (k > a.size() + b.size())
		{
			cout << "Error";
			return -1;
		}
		int pa = 0;
		int pb = 0;
		int m = 0;
		int i = 1;
		while (pa < a.size() && pb < b.size())
		{
			if (a[pa] <= b[pb])
			{
				cout <<"�� " << i <<"��ѭ�� " << "pa : " << pa << " " << m << endl;
				pa++;
				m++;
			}
			else
			{
				cout << "�� " << i << "��ѭ�� " << "pb : " << pb << ' ' << m << endl;
				pb++;
				m++;
			}
			i++;
			if (m == k)
				return pa >= pb ? a[pa - 1] : b[pb - 1];
		}
		while (pa < a.size())
		{
			m++;
			pa++;
			if (m == k)
				return a[pa - 1];
		}
		while (pb < b.size())
		{
			m++;
			pb++;
			if (m == k)
				return b[pb - 1];
		}
	}
	//���ַ���ʱ�临�Ӷ�ΪO(log(m+n))���ռ临�Ӷ�ΪO(1)
	//��ʵ���������Kֵ�ö��ַ���
	int findtheKthNum_3(vector<int> &a, int i, vector<int> &b, int j, int k)
	{
		//i����ʾa����ĵ�ǰ��ʼλ�ã�j����ʾb����ĵ�ǰ��ʼλ�ã�k��ʾ��K���ֵ����Щ�����ڲ��ϵ���
		if (i >= a.size()) return b[j + k - 1];  //��ǰa�����Ѿ���ȫ����̭������a�����ǿյģ���K���ֵһ����b�ϣ�ֱ�ӷ���
		if (j >= b.size()) return a[i + k - 1];  //��ǰb�����Ѿ���ȫ����̭������b�����ǿյģ���K���ֵһ����a�ϣ�ֱ�ӷ���
		if (k == 1) return min(a[i], b[j]); //���KֵΪ1����������ͷ��С���Ǹ��Ϳ����ˡ�
		//һ�����������a,b�����k/2λ�õ�ֵ��������鲻������û��k/2λ�ã��򸳸����������
		int midVal1 = (i + k / 2 - 1 < a.size()) ? a[i + k / 2 - 1] : INT_MAX;
		int midVal2 = (j + k / 2 - 1 < b.size()) ? b[j + k / 2 - 1] : INT_MAX;
		if (midVal1 < midVal2) {
			//˵����Kֵλ��һ������a�����ǰk/2�У�a������ʼλ�ú���k/2����Kֵ����
			return findtheKthNum_3(a, i + k / 2, b, j, k - k / 2);
		}
		else {
			return findtheKthNum_3(a, i, b, j + k / 2, k - k / 2);
		}
	}
};
/*
the 5th:Longest Consecutive Sequence
Description:
Given an unsorted array of integers, find the length of the longest 
consecutive elements sequence.For example, Given [100,4,200,1,3,2]��
The longest consecutive elements sequence is [1,2,3,4].Return 4.
ur algorithm should run in O(n) complexity
*/
/*�������������O(nlogn)��ʱ�临�Ӷȣ����ǻ������򣬿��������ʱ�临�Ӷ���O(nlogn)
���������������Ԫ��������ģ���ҪҪ��O(n),�����뵽�ù�ϣ��
��һ����ϣ��unordered_map<int,bool> used��¼ÿһ��Ԫ����ʹ�ã���ÿһ��Ԫ�أ��Ը�
Ԫ��Ϊ���ģ�����������֪��������Ϊֹ����¼����ĳ��ȡ�
*/
class Solution_5th {
public:

};
int main()
{
	vector<int> vec = { 1,2,3,3,3,3,5,6,7,8,9,9,9,10,11,12,14,14,14,14,15 };
	vector<int> vec2 = { 1,2,3,3,3,3,5,6,7,8,9,9,9,10,11,12,14,14,14,14,15 };
	vector<int> vec3 = { 5,6,7,8,9,10,11,12,13,0,1,2,3,4 };
	vector<int> vec4 = { 1,3,5,7,9,11,13,15,17,19 };
	vector<int> vec5 = { 2,4,6,8,10,12,14,16,18,20 };
	vector<int> vec6 = { 1,2,3,4,5 };
	vector<int> vec7 = { 10,11,12,13,14,15,16,17,18,19 };
	//Solution_1st solution;
	//cout << solution.removeDuplicates_1(vec) << endl;
	//cout << solution.removeDuplicates_2(vec2) << endl;
	//Solution_2nd solution;
	//Solution_3rd solution;
	//cout << solution.removeDuplicates(vec) << endl;
	//cout << solution.removeDuplicates(vec2, 3) << endl;
	//cout << solution.search(vec3, 4) << endl;
	Solution_4th solution;
	//cout << solution.findtheKthNum_1(vec4, vec5, 17);
	cout << solution.findtheKthNum_2(vec4, vec5, 17) << endl;
	cout << "-------------------------------------------------" << endl;
	cout << solution.findtheKthNum_2(vec6, vec7, 10) << endl;
	cout << "-------------------------------------------------" << endl;
	cout << solution.findtheKthNum_3(vec6, 0, vec7, 0, 10) << endl;
    return 0;
}

