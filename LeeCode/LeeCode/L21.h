#pragma once
/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

链接：https ://leetcode-cn.com/problems/merge-two-sorted-lists
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1 && !l2)
			return nullptr;

		ListNode* head = nullptr;
		ListNode* cur = nullptr;

		while (l1 && l2)
		{
			ListNode* f;

			if (l1->val < l2->val)
			{
				f = l1;
				l1 = l1->next;
			}
			else
			{
				f = l2;
				l2 = l2->next;
			}


			if (cur)
			{
				cur->next = f;
				cur = f;
			}
			else
			{
				head = f;
				cur = f;
			}
		}

		if (!head)
		{
			head = l1 ? l1 : l2;
		}
		else
		{
			cur->next = l1 ? l1 : l2;
		}

		return head;
	}
};