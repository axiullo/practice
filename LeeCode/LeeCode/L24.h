#pragma once
/*
����һ���������������������ڵĽڵ㣬�����ؽ����������
�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻����

ʾ�� 1��

���룺head = [1,2,3,4]
�����[2,1,4,3]

ʾ�� 2��

���룺head = []
�����[]

ʾ�� 3��

���룺head = [1]
�����[1]



��ʾ��

	�����нڵ����Ŀ�ڷ�Χ [0, 100] ��
	0 <= Node.val <= 100

���ӣ�https://leetcode-cn.com/problems/swap-nodes-in-pairs
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