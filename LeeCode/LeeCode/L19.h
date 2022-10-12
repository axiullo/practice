#pragma once
/************************************************************************/
/*                                                                   
����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣

���룺head = [1,2,3,4,5], n = 2
�����[1,2,3,5]

ʾ�� 2��
���룺head = [1], n = 1
�����[]

ʾ�� 3��
���룺head = [1,2], n = 1
�����[1]

��ʾ��

	�����н�����ĿΪ sz
	1 <= sz <= 30
	0 <= Node.val <= 100
	1 <= n <= sz

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/*�������, ˫ָ��, ͷָ��ȵڶ���ָ���n��λ��, ��ͷָ�뵽��ĩβ, �ڶ���ָ�����Ҫɾ���Ľڵ�*/
/************************************************************************/

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
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int first = 1;
		ListNode* first_node = head;
		ListNode* second_node = head;
		ListNode* second_front_node = nullptr;

		while (first <= n && first_node)
		{
			first_node = first_node->next;
			++first;
		}

		while (first_node)
		{
			first_node = first_node->next;
			second_front_node = second_node;
			second_node = second_node->next;
		}

		if (!second_front_node) {
			head = second_node->next;
		}
		else
		{
			second_front_node->next = second_node->next;
		}

		return head;
	}
};