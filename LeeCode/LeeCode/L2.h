#pragma once
/**
�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/add-two-numbers
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

��ʾ��

	ÿ�������еĽڵ����ڷ�Χ [1, 100] ��
	0 <= Node.val <= 9
	��Ŀ���ݱ�֤�б��ʾ�����ֲ���ǰ����


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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int addnum = 0;
		int yunum = 0;
		ListNode* node = new ListNode();
		ListNode* rtn = node;
		ListNode* cur_node = nullptr;

		while (l1 && l2)
		{
			if (cur_node)
			{
				cur_node = node;
				node = new ListNode();
				cur_node->next = node;
			}

			int sum = l1->val + l2->val + addnum;
			addnum = 0;
			addnum = int(sum / 10);
			yunum = sum % 10;
			node->val = yunum;
			l1 = l1->next;
			l2 = l2->next;
			cur_node = node;
		}

		while (l1) {
			if (cur_node)
			{
				cur_node = node;
				node = new ListNode();
				cur_node->next = node;
			}

			addNumber(l1, node, &addnum);

			l1 = l1->next;
			cur_node = node;
		}

		while (l2)
		{
			if (cur_node)
			{
				cur_node = node;
				node = new ListNode();
				cur_node->next = node;
			}

			addNumber(l2, node, &addnum);


			l2 = l2->next;
			cur_node = node;
		}

		if (addnum > 0)
		{
			if (cur_node)
			{
				cur_node = node;
				node = new ListNode();
				cur_node->next = node;
			}

			node->val = addnum;
		}

		return rtn;
	}

	void addNumber(ListNode* l, ListNode* node, int* addnum)
	{
		int sum = l->val + *addnum;
		*addnum = int(sum / 10);
		int yunum = sum % 10;
		node->val = yunum;
	}

	void test()
	{
		ListNode* l1_1 = new ListNode(2);
		ListNode* l1_2 = new ListNode(4);
		ListNode* l1_3 = new ListNode(3);
		l1_1->next = l1_2;
		l1_2->next = l1_3;

		ListNode* l2_1 = new ListNode(5);
		ListNode* l2_2 = new ListNode(6);
		ListNode* l2_3 = new ListNode(4);
		l2_1->next = l2_2;
		l2_2->next = l2_3;

		ListNode* rtn = addTwoNumbers(l1_1, l2_1);
		do_print(rtn);
 	}

	void test1()
	{
		ListNode* l1 = new ListNode(0);
		ListNode* l2 = new ListNode(0);

		ListNode* rtn = addTwoNumbers(l1,l2);
		do_print(rtn);
	}

	void test2()
	{
		ListNode* l1 = new ListNode(1);
		ListNode* l1_2 = new ListNode(9);
		l1->next = l1_2;

		ListNode* l2 = new ListNode(9);

		ListNode* rtn = addTwoNumbers(l1, l2);
		do_print(rtn);
	}

	void do_print(ListNode* rtn)
	{
		while (rtn)
		{
			cout << rtn->val << endl;
			rtn = rtn->next;
		}
	}
};