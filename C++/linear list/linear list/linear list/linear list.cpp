// linear list.cpp : 定义控制台应用程序的入口点。
//
/*
线性表：
	全部有关线性表的题目，这类题目考察线性表的操作，例如数组、单链表、双向链表等。
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

//Leetcode， Remove Duplicates from Sorted Array
class Solution_1st{
public:
	//时间复杂度O(n), 空间复杂度O(1)
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
	//使用STL，时间复杂度O(n),空间复杂度O(1)
	int removeDuplicates_2(vector<int> &nums) {
		//STL unique()函数是一个去重函数 unique的功能是去除相邻的重复元素(只保留一个),
		//其实它并不真正把重复的元素删除，是把重复的元素移到后面去了，然后依然保存到了原
		//数组中，然后 返回去重后最后一个元素的地址
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
分析：
	加一个变量记录下一个元素出现的次数即可
*/
//Leetcode, Remove Duplicates from Sorted Array II 
class Solution_2nd {
public:
	int removeDuplicates(vector<int> &nums) {
		int index = 0;
		//非常巧妙，index始终比i小两个位置，有滑动窗口的思想，固定宽度滑动窗口
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
	(i.e.,0 1 2 3 4 5 6 7 8 9 10 might become 7 8 9 10 0 1 2 3 4 5 6）。
	You are given a target value to search. If found in the array return its index, otherwise return -1.
	You may assume no duplicate exists in the array.
*/
/*
分析：
	平时我们二分法的时候，直接判断下中点和目标的关系，就可以知道目标在左半部分还是右半部份了，这背后其实隐含一个假设，
	那就是从起点到终点是一段有序的序列。而本题中，如果我们还想继续做二分法，这个假设就不存在了，因为从起点到终点有可
	能有个断片！不过，旋转有序数组有一个特点，假设本身是个升序序列，从左向右。如果左边的点比右边的点小，说明这两个点
	之间是有序的，不存在旋转点。如果左边的点比右边的大，说明这两个点之间有一个旋转点，导致了不再有序。因为只有一个旋
	转点，所以一分为二后，肯定有一半是有序的。所以，我们还是可以用二分法，不过要先判断左半边有序还是右半边有序。如果
	左半边有序，则直接将目标和左半边的边界比较，就知道目标在不在左半边了，如果不在左半边肯定在右半边。同理，如果右半
	边有序，则直接将目标和右半边的边界比较，就知道目标在不在右半边了，如果不在右半边肯定在左半边。这样就完成了二分。
	我们并不能按照有序数组的二分法来判断：
	if(target < array[mid])
		target in [first, mid - 1]
		last = mid - 1
	else
		target in [mid + 1, last]
		first = mid + 1

	而是根据mid、target的关系，有四种情况，如果array[first] <= array[mid],说明前半截是有序的，那么我们就直接判断
	target是在前半截还是后半截了；如果array[first] > array[mid],说明后半截是有序的，那么我们就直接判断target是在
	后半截还是前半截了；总之，target一定最终定在一个有序数组中的，持续做二分法就可以了。
*/

//时间复杂度O(logn),空间复杂度O(1)
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
			//如果左半部分是有序的
			if (nums[first] <= nums[mid])
			{
				if (nums[first] <= target && target < nums[mid])
					last = mid - 1;
				else
					first = mid + 1;
			}
			//如果右半部分是有序的
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
分析：这是一道非常经典的题目。这题更通用的形式是，给定两个已经排好的数组，找到二者所有元素中K大的元素。
1. merge两个数组，然后求第k大的元素，但时间复杂度是O(m+n);
2. 使用一个计数器，记录当前已经找到的第m大的元素。同时使用两个指针pa,pb, 分别指向A和B的第一个元素。如果
   数组A当前元素小，那么pa++，同时m++；如果数组B当前元素小，那么pb++，同时m++。最终当m等于K的时候，就
   得到我们的答案了，时间复杂度是O(k), O（1）空间复杂度。但当k接近m+n时，时间复杂度还是O(m+n).
3. 假设A和B的元素个数都大于k/2，我们将A的第k/2个元素，即A[k/2 - 1]和B的第k/2个元素，即B[k/2 - 1]进行
   比较，有三种情况：
   1） A[k/2 - 1] == B[K/2 - 1]：说明这个值就是就是我们要找得K值
   2） A[K/2 - 1] > B[k/2 - 1]：说明我们要找的K值一定不在B的前k/2中，那么将B的前K/2淘汰掉，即B的起始
	   位置向后移动K/2，并且K的值调整为k/2。
   3） A[k/2 - 1] < B[k/2 -1]:说明我们要找的K值一定不在A的前k/2中，那么将A的前K/2淘汰掉，即B的起始
	   位置向后移动K/2，并且K的值调整为k/2。
*/
#define INT_MAX 100000
class Solution_4th {
public:
	//merge:时间复杂度为O(m+n)，空间复杂度是O(m+n)
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

	//双指针法：最差时间复杂度为O(m+n), 空间复杂度为O(1)
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
				cout <<"第 " << i <<"次循环 " << "pa : " << pa << " " << m << endl;
				pa++;
				m++;
			}
			else
			{
				cout << "第 " << i << "次循环 " << "pb : " << pb << ' ' << m << endl;
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
	//二分法：时间复杂度为O(log(m+n))，空间复杂度为O(1)
	//其实，这是针对K值得二分法：
	int findtheKthNum_3(vector<int> &a, int i, vector<int> &b, int j, int k)
	{
		//i，表示a数组的当前起始位置；j，表示b数组的当前起始位置；k表示第K大的值。这些数字在不断调整
		if (i >= a.size()) return b[j + k - 1];  //当前a数组已经被全部淘汰，或者a数组是空的，第K大的值一定在b上，直接返回
		if (j >= b.size()) return a[i + k - 1];  //当前b数组已经被全部淘汰，或者b数组是空的，第K大的值一定在a上，直接返回
		if (k == 1) return min(a[i], b[j]); //如何K值为1，返回数组头较小的那个就可以了。
		//一般情况，计算a,b数组的k/2位置的值。如果数组不够长，没有k/2位置，则赋给它最大整数
		int midVal1 = (i + k / 2 - 1 < a.size()) ? a[i + k / 2 - 1] : INT_MAX;
		int midVal2 = (j + k / 2 - 1 < b.size()) ? b[j + k / 2 - 1] : INT_MAX;
		if (midVal1 < midVal2) {
			//说明第K值位置一定不在a数组的前k/2中，a数组起始位置后移k/2个，K值减半
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
consecutive elements sequence.For example, Given [100,4,200,1,3,2]，
The longest consecutive elements sequence is [1,2,3,4].Return 4.
ur algorithm should run in O(n) complexity
*/
/*分析：如果允许O(nlogn)的时间复杂度，我们会先排序，快速排序的时间复杂度是O(nlogn)
但是由于序列里的元素是无序的，又要要求O(n),首先想到用哈希表。
用一个哈希表unordered_map<int,bool> used记录每一个元素是使用，对每一个元素，以该
元素为中心，往左右扩张知道不连续为止，记录下最长的长度。
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

