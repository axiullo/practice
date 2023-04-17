#pragma once
/*
反转一个单链表。

示例 :

	输入: 1->2->3->4->5->NULL
	输出 : 5->4->3->2->1->NULL

	进阶 :
	你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

	链接：https ://leetcode-cn.com/problems/reverse-linked-list

	相同: 剑指 Offer 24. 反转链表  https://leetcode.cn/leetbook/read/illustration-of-algorithm/9pdjbm/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseList1(ListNode* head) {
		ListNode* temp = nullptr;
		ListNode* front = nullptr;
		ListNode* cur = head;

		while (cur)
		{
			temp = cur->next;
			cur->next = front;
			front = cur;
			cur = temp;
		}

		return front;
	}

	ListNode* reverseList(ListNode* head) {
		if (head == nullptr or head->next == nullptr)
		{
			return head;
		}

		ListNode* p = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return p;
	}

	void test()
	{
		ListNode* head = NULL;
		ListNode* curNode = nullptr;

		for (int n = 0; n < 5; n++)
		{
			ListNode* node = new ListNode(n + 1);

			if (!head) {
				head = node;
			}

			if (curNode) {
				curNode->next = node;
			}

			curNode = node;
		}

		ListNode* resultNode = reverseList(head);

		while (resultNode)
		{
			cout << resultNode->val << endl;
			resultNode = resultNode->next;
		}
	}
};

