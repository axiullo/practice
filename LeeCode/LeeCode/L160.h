#pragma once

// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* a = headA;
		ListNode* b = headB;
		ListNode* ret = nullptr;

		if (!a || !b)
			return nullptr;

		int a_pos = 0;
		int b_pos = 0;

		while (a)
		{
			b = headB;
			b_pos = 0;

			while (b)
			{
				if (a == b)
				{
					ret = a;
					break;
				}

				b = b->next;
				++b_pos;
			}

			if (ret)
				break;


			a = a->next;
			++a_pos;
		}

		return ret;
	}

	ListNode *getIntersectionNode_other(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return nullptr;

		ListNode *a = headA, *b = headB;

		while (a != b) {
			a = a ? a->next : headB;
			b = b ? b->next : headA;
		}
		return a;
	}
};