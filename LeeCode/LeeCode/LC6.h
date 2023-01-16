#pragma once
/*
剑指 Offer 06. 从尾到头打印链表
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：
输入：head = [1,3,2]
输出：[2,3,1]

限制：
0 <= 链表长度 <= 10000

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/5dt66m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

思路:
尾递归, 遍历到链表尾部, 然后依次返回值插入到结果数组中.

其他思路:
链表翻转,然后放回vector返回.  优点:内存消耗小
*/

#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:

	void getvalue(ListNode* node, vector<int>& vecInts)
	{
		if (!node->next) {
			vecInts.push_back(node->val);
			return;
		}

		getvalue(node->next,vecInts);
		vecInts.push_back(node->val);
	}

	vector<int> reversePrint(ListNode* head) {
		vector<int> rtn;

		if (!head)
		{
			return rtn;
		}

		getvalue(head, rtn);
		return rtn;
	}
};