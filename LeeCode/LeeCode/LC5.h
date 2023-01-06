#pragma once
/*
剑指 Offer 05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."

限制：
0 <= s 的长度 <= 10000

作者：Krahets
链接：https ://leetcode.cn/leetbook/read/illustration-of-algorithm/50ywkd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

思路:
遍历字符串的每个字符赋值给新字符串, 如果是空格,给新字符串赋值成"%20"
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		string str_ret;

		for (int i = 0; i < s.length(); ++i) {
			char c = s.at(i);

			if (c == ' ') {
				str_ret += "%20";
			}
			else
			{
				str_ret += c;
			}
		}

		return str_ret;
	}

	void test()
	{
		string str_orign = "We are happy.";
		string str_result = replaceSpace(str_orign);
		cout << str_result << endl;
	}
};