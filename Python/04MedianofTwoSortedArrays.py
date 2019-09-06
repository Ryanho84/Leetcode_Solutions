#encoding = utf-8
"""
04 寻找两个有序数组中的中位数
给定两个大小分别为m和n的有序数组nums1和nums2
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为O(log(m+n))

你可以假设两个数组不会同时为空

example1: 
nums1 = [1,3]
nums2 = [2]
output = 2

example2:
nums1 = [1,2]
nums2 = [3,4]
output = 2.5
"""
"""
解决思路：
第一眼看到首先想到归并，但是时间复杂度要求O(log(m+n)).
看到O(logn)的时间复杂度，我们首先想到折半查找法。因此我们在思考，如果我们查找中位数，那么如果能够像折半查找法一样，每次删除nums1或nums2集合的一般元素，那么最终我们就能在O(log(m+n))的时间量级内找到想要的元素

比如我们想要查找All elements内的第k大元素，那么：
假设nums1和nums2的元素个数都大于k/2, 我们将nums1的第k/2元素(nums1[k/2-1])和nums2的第k/2元素(nums2[k/2-1])进行比较，有以下三种情况;
    1. nums1[k/2 - 1] == nums2[k/2 - 1]
    2. nums1[k/2 - 1] > nums2[k/2 - 1]
    3. nums1[k/2 - 1] < nums2[k/2 - 1]
如果是1情况，则找到了第k大元素；如果是2，则第k大元素不可能∈ nums2[0:k/2], 可以删除其前k/2个元素；如果是3，则同理可以删除nums1的前k/2个元素。通过递归，最终找到1情况即找到第k大元素

中止条件
1. 当nums1或者nums2 is None， 返回num2[k-1]或者nums1[k-1]
2. 当k = 1, 返回min(num1[0], nums2[0])
3. 当nums1[k/2-1] == nums2[k/2-1]， 返回nums1[k/2-1]或者nums2[k/2-1]
"""

class Solution:
    def findMedianSortedArrays(self, nums1, nums2) -> float:
        """
        :type nums1 : List[int]
        :type nums2 : List[int]
        :rtype : float
        """
        m = len(nums1)
        n = len(nums2)
        total = m + n
        
        return 0
    


