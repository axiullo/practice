#pragma once
/*
��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�

ʾ����

���룺1->2->4, 1->3->4
�����1->1->2->3->4->4

���ӣ�https ://leetcode-cn.com/problems/merge-two-sorted-lists
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