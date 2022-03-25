#pragma once
/************************************************************************/
/*                                                                     
给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
示例 1：

输入：s = "Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"

示例 2:

输入： s = "God Ding"
输出："doG gniD"

提示：

	1 <= s.length <= 5 * 10^4
	s 包含可打印的 ASCII 字符。
	s 不包含任何开头或结尾空格。
	s 里 至少 有一个词。
	s 中的所有单词都用一个空格隔开。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/************************************************************************/

#include <string.h>
#include <iostream>
using namespace std;

class Solution {
public:
	void word_swap(const string& s, string& str_ret, int startpos, int endpos) {
		while (startpos <= endpos) {
			str_ret += s[endpos--];
		}
	}

	string reverseWords(string s) {
		string str_ret = "";
		int startpos = 0;
		int endpos = 0;

		for (int i = 0; i <s.length(); ++i)
		{
			if (s[i] == ' ')
			{
				endpos = i - 1;
				word_swap(s, str_ret, startpos, endpos);
				str_ret += s[i];
				startpos = i + 1;				
			}
		}

		word_swap(s, str_ret, startpos, s.length() - 1);

		return str_ret;
	}

	void test() {
		string t = "hello world";
		string ret = reverseWords(t);

		cout << ret.c_str() << endl;
	}
};