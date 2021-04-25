#pragma once
/*
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false

示例 2:

输入: 1->2->2->1
输出: true

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

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