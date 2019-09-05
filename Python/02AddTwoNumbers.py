#encoding = utf-8

"""
02 两数相加：
给出两个 非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且他们的每个节点智能存储一位数字。
如果，我们将这两个数字相加起来，则会返回一个新的链表来表示它们的和。
你可以假设除了数字0之外，这两个数都不会以0开头。

example:
输入：  （2->4->3) + (5->6->4)
输出：  (7->0->8)
原因：  342+465 = 807
"""
"""
解决思路：
遍历两个链表，逐节点相加。注意进位，类似于merge算法
"""
#Definition for singly-linked list.
class listNode:
    def __init__(self,x):
        self.val = x
        self.next = None

class Solution:
    def addTowNumbers(self, l1:listNode, l2:listNode) ->listNode:
        """
        :type l1: listNode
        :type l2: listNode
        :rtype: listNode
        """
        carry = 0
        result = current = listNode(0)
        while l1 or l2:
            val = carry
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            current.next = listNode(val%10)
            current = current.next
            carry = int(val/10)
        if carry > 0:
            current.next = listNode(carry)
        return result.next
    #初始化数据
    def initList(self, data):
        head = listNode(data[0])
        p = head
        for num in data[1:]:
            #print(num)
            node = listNode(num)
            p.next = node
            p = p.next
        return head
    #屏幕打印
    def printList(self, list:listNode):
        link_str = ''
        node = list
        while node is not None:
            if node.next is not None:
                link_str += str(node.val) +'->'
                #print(link_str)
            else:
                link_str += str(node.val)
            node = node.next
        print('the linkList is : ' + link_str)

s1 = Solution()
data1 = [2,4,9]
l1 = s1.initList(data1)
data2 = [5,6,4]
l2 = s1.initList(data2)
#s1.printList(l1)
result = s1.addTowNumbers(l1,l2)
s1.printList(result)
            


    