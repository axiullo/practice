#pragma once
/*
��ָ Offer 05. �滻�ո�
��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��

ʾ�� 1��
���룺s = "We are happy."
�����"We%20are%20happy."

���ƣ�
0 <= s �ĳ��� <= 10000

���ߣ�Krahets
���ӣ�https ://leetcode.cn/leetbook/read/illustration-of-algorithm/50ywkd/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

˼·:
�����ַ�����ÿ���ַ���ֵ�����ַ���, ����ǿո�,�����ַ�����ֵ��"%20"
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