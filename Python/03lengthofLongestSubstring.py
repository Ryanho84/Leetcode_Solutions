#encoding = utf-8

"""
03 给定一个字符串，请找出其中不含有重复字符串的最长字串的长度。

example1:
input: "abcabcbb"
output: 3

example2:
input: "bbbbb"
output: 1

example3:
input: "pwwkew"
output: 3
"""

"""
解决思路：
 利用滑动窗口
"""

class Solution:
    #直接滑动窗口。维护一个滑动窗口，遍历整个s，返回滑动窗口的最大长度
    #缺点，需要维护一个额外的滑动窗口，数据的delete和append比较耗时，并且需要开辟额外的空间
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        
        window = []
        max_length = 0
        for c in s:
            if c not in window:
                window.append(c)
            else:
                window[:] = window[window.index(c)+1:]
                window.append(c)
            max_length = max(len(window), max_length)
        return max_length
    #滑动窗口优化。使用双指针在s上直接进行操作，不需要额外维护一个滑动窗口
    def lengthOfLongestSubstring2(self, s:str) -> int:
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        
        max_length = 0
        right = left = 0

        for c in s:
            #如果不在滑动窗口中，则移动滑动窗口右指针
            if c not in s[left:right]:
                right += 1
            #否则滑动窗口向右整体滑动
            else:
                right += 1
                left = right
            max_length = max((right - left), max_length)
        """
        for c in enumerate(s):
            if c not in s[left:right]:
                right += 1
            else:
                left = s[left:right].index(c) + 1
                right += 1
            max_length = max((right - left), max_length)
        """
        return max_length
    
    def lengthOfLongestSubstring3(self, s:str) -> int:
        """
        :type s: str
        :rtype: int
        """
        """
        1. 遍历字符串
        """
        if not s:
            return 0
        #可抛弃字符串的尾值索引，该索引值及以前的字符串都属于重复字符串的一部分，不再累计计算。
        ignore_str_index_end = -1
        dic = {}
        max_length = 0

        for index, c in enumerate(s):
            #为什么需要dic[c] > ignore_str_index_end 这个条件，请看str4例子
            if c in dic and dic[c] > ignore_str_index_end:
                ignore_str_index_end = dic[c]
                dic[c] = index
                print('if:', dic)
            else:  
                dic[c] = index
                print('else:', dic)
                max_length = max((index - ignore_str_index_end), max_length)
        return max_length


s1 = Solution()
str1 = "abcabcabc"
str2 = "bbbbb"
str3 = "pwwkew"
str4 = "abbcda"

#print(s1.lengthOfLongestSubstring2(str1))
#print(s1.lengthOfLongestSubstring3(str2))
#print(s1.lengthOfLongestSubstring3(str3))
print(s1.lengthOfLongestSubstring3(str4))