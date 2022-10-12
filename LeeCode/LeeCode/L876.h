#pragma once

/*
给定一个头结点为 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

提示：

	给定链表的结点数介于 1 和 100 之间。

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* onenode = head;
		ListNode* twonode = head->next ? (head->next->next ? head->next->next : head->next) : nullptr;

		while (twonode)
		{
			onenode = onenode->next;
			twonode = twonode->next ? (twonode->next->next ? twonode->next->next : twonode->next) : nullptr;
		}

		return onenode;
	}

	void test()
	{
		//ListNode node4(4);
		//ListNode node3(3, &node4);
		//ListNode node2(2, &node3);
		//ListNode node(1, &node2);

		//ListNode* n = middleNode(&node);
		//cout << n->val << endl;

		ListNode node2(2);
		ListNode node(1, &node2);
		ListNode* n = middleNode(&node);
		cout << n->val << endl;
	}
};