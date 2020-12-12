#pragma once
/*
��תһ��������

ʾ�� :

	����: 1->2->3->4->5->NULL
	��� : 5->4->3->2->1->NULL

	���� :
	����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿

	���ӣ�https ://leetcode-cn.com/problems/reverse-linked-list
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
};

