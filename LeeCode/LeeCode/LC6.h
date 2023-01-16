#pragma once
/*
��ָ Offer 06. ��β��ͷ��ӡ����
����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���

ʾ�� 1��
���룺head = [1,3,2]
�����[2,3,1]

���ƣ�
0 <= ������ <= 10000

���ߣ�Krahets
���ӣ�https://leetcode.cn/leetbook/read/illustration-of-algorithm/5dt66m/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

˼·:
β�ݹ�, ����������β��, Ȼ�����η���ֵ���뵽���������.

����˼·:
����ת,Ȼ��Ż�vector����.  �ŵ�:�ڴ�����С
*/

#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:

	void getvalue(ListNode* node, vector<int>& vecInts)
	{
		if (!node->next) {
			vecInts.push_back(node->val);
			return;
		}

		getvalue(node->next,vecInts);
		vecInts.push_back(node->val);
	}

	vector<int> reversePrint(ListNode* head) {
		vector<int> rtn;

		if (!head)
		{
			return rtn;
		}

		getvalue(head, rtn);
		return rtn;
	}
};