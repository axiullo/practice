#pragma once
/*
���ж�һ�������Ƿ�Ϊ��������

ʾ�� 1:

����: 1->2
���: false

ʾ�� 2:

����: 1->2->2->1
���: true

���ף�
���ܷ��� O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿

https://leetcode-cn.com/problems/palindrome-linked-list/
*/
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
private:
	ListNode *firstnode;

public:
	bool recursionNode(ListNode* node) {
		if (node != nullptr) {
			if (!recursionNode(node->next)) {
				return false;
			}

			if (firstnode->val != node->val) {
				return false;
			}

			firstnode = firstnode->next;
		}

		return true;
	}
		
	bool isPalindrome(ListNode* head) {
		firstnode = head;
		return recursionNode(head);
	}
};