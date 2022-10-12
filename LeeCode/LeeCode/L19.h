#pragma once
/************************************************************************/
/*                                                                   
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：
输入：head = [1], n = 1
输出：[]

示例 3：
输入：head = [1,2], n = 1
输出：[1]

提示：

	链表中结点的数目为 sz
	1 <= sz <= 30
	0 <= Node.val <= 100
	1 <= n <= sz

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*看了题解, 双指针, 头指针比第二个指针多n个位置, 当头指针到了末尾, 第二个指针就是要删除的节点*/
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