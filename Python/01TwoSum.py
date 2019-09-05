"""
01. Two Sum
给定一个整数数组nums和一个目标值，请在该数组中找出和为目标值的那两个证书，并返回他们的索引下标
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中的同样的元素

example:
nums = [2,7,11,15]  target = 9
return [0,1]
"""

"""
解决思路：
1. 暴力解决法，遍历整个数组：对数组的中的每一个数值计算target - nums[index]，然后再遍历查找是否存在该数。时间复杂度是O(nlgn)

2. 使用哈希表。遍历整个数组，建立哈希映射。直接查找是否存在target - nums[index]。存在就返回[hashmap[num],index]。时间复杂度为O(n)


"""
#encoding = utf-8



class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashmap = {}
        for index, num in enumerate(nums):
            another_num = target - num
            if another_num in hashmap:
                return [hashmap[another_num], index]
            hashmap[num] = index
            #print(hashmap)
        return None

s1 = Solution()
nums = [2,7,11,15]
target = 26
print(s1.twoSum(nums,target))



