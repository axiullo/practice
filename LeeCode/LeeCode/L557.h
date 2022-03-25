#pragma once
/************************************************************************/
/*                                                                     
����һ���ַ��� s ������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
ʾ�� 1��

���룺s = "Let's take LeetCode contest"
�����"s'teL ekat edoCteeL tsetnoc"

ʾ�� 2:

���룺 s = "God Ding"
�����"doG gniD"

��ʾ��

	1 <= s.length <= 5 * 10^4
	s �����ɴ�ӡ�� ASCII �ַ���
	s �������κο�ͷ���β�ո�
	s �� ���� ��һ���ʡ�
	s �е����е��ʶ���һ���ո������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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