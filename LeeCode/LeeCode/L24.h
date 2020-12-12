#pragma once
/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1：

输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：

输入：head = []
输出：[]

示例 3：

输入：head = [1]
输出：[1]



提示：

	链表中节点的数目在范围 [0, 100] 内
	0 <= Node.val <= 100

链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)
			return head;

		ListNode* ret = head->next;
		head->next = head->next->next;
		ret->next = head;

		while (head->next && head->next->next)
		{
			ListNode* t = head->next->next;
			head->next->next = t->next;
			t->next = head->next;
			head->next = t;
			head = t->next;
		}

		return ret;
	}
};