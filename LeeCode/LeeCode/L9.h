#pragma once
/*********************************************************************
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

	例如，121 是回文，而 123 不是。


示例 1：

输入：x = 121
输出：true

示例 2：

输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

示例 3：

输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。

提示：

	-231 <= x <= 231 - 1


进阶：你能不将整数转为字符串来解决这个问题吗？

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/palindrome-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

##思路:
1. 负数肯定不是回文数
2. 将数字的每个数字转化为数组, 然后再将数组倒着组回成数, 判断两个数是否一样. 也可以判断数组前后数字是否一致.

漏点:
1.所有个位是0的数字都不可能是回文数
2.为什么不考虑只反转int数字的一半？
现在的问题是，我们如何知道反转数字的位数已经达到原始数字位数的一半？
由于整个过程我们不断将原始数字除以 10，然后给反转后的数字乘上 10，
所以，当原始数字小于或等于反转后的数字时，就意味着我们已经处理了一半位数的数字了。
当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
*/

//#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x %10 ==0 && x != 0))  //漏掉了个位数是0的情况
		{
			return false;
		}

		//vector<int> vec_nums;
		int a_nums[10] = {};
		int len = 0;
		int tx = x;

		while (tx >= 10)
		{
			a_nums[len++] = tx % 10;
			tx = tx / 10;
		}

		if (tx > 0)
		{
			a_nums[len++] = tx;
		}

		int head = 0;
		int tail = len - 1;

		while (head < tail)
		{
			if (a_nums[head] != a_nums[tail])
			{
				return false;
			}

			++head;
			--tail;
		}

		return true;
	}

	void test()
	{
		cout << isPalindrome(1) << endl;
		cout << isPalindrome(10) <<endl;
		cout << isPalindrome(11) << endl;
		cout << isPalindrome(12) << endl;
		cout << isPalindrome(121) << endl;
	}
};