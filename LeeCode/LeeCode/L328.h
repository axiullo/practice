#pragma once

/**
https://leetcode-cn.com/problems/odd-even-linked-list/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next || !head->next->next)
		{
			return head;
		}

		int index = 0;
		ListNode* oddnodes = nullptr;
		ListNode* evennodes = nullptr;
		ListNode* evenhead = nullptr;
		ListNode* curnode = head;

		if (head) {
			evenhead = head->next;
		}

		while (curnode)
		{
			index = index + 1;
			ListNode** tmpnode = index % 2 == 1 ? &oddnodes : &evennodes;

			if (!*tmpnode) {
				*tmpnode = curnode;
			}
			else {
				(*tmpnode)->next = curnode;
				*tmpnode = curnode;
			}

			curnode = curnode->next;
		}

		if (oddnodes) {
			oddnodes->next = evenhead;
		}

		if (evennodes) {
			evennodes->next = nullptr;
		}

		return head;
	}
};