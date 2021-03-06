#pragma once
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

#include <vector>
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
	ListNode* deleteDuplicates(ListNode* head) {
		vector<ListNode*> vec_node;
		ListNode* node = head;

		while (node)
		{
			bool ishas = false;

			for (auto val : vec_node)
			{
				if (val->val == node->val) {
					ishas = true;
					break;
				}
			}

			ListNode* del = nullptr;

			if (!ishas) {
				vec_node.push_back(node);
			}
			else {
				del = node;
			}

			node = node->next;

			if (del) {
				delete(del);
			}
		}

		ListNode* newhead = nullptr;
		ListNode* newnode = nullptr;

		for (auto val : vec_node)
		{
			if (!newnode) {
				newnode = val;
				newhead = newnode;
			}
			else
			{
				newnode->next = val;
				newnode = val;
			}
		}

		if (newnode) {
			newnode->next = nullptr;
		}

		return newhead;
	}

	ListNode* deleteDuplicates_1(ListNode* head) {
		ListNode* iter_node = head;


		while (iter_node) {
			if (!iter_node->next) {
				break;
			}

			if (iter_node->val == iter_node->next->val) {
				ListNode* del = iter_node->next;
				iter_node->next = del->next;
				delete(del);
				continue;;
			}

			iter_node = iter_node->next;
		}

		return head;
	}
};