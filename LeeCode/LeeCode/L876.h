#pragma once

/*
����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣

����������м��㣬�򷵻صڶ����м��㡣

��ʾ��

	��������Ľ�������� 1 �� 100 ֮�䡣

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