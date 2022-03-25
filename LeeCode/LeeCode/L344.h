#pragma once
/************************************************************************/
/* ��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������

��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣

��ʾ��

	1 <= s.length <= 10^5
	s[i] ���� ASCII ����еĿɴ�ӡ�ַ�


��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/reverse-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
/************************************************************************/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int leftpos = 0;
		int rightpos = s.size() - 1;

		while (leftpos < rightpos)
		{
			int t = s[leftpos];
			s[leftpos] = s[rightpos];
			s[rightpos] = t;
			++leftpos;
			--rightpos;
		}
	}

	void test() {
		vector<char> s = { 'a', 'b','c','d' };
		reverseString(s);

		for (int i  =0 ; i <s.size(); ++i)
		{
			cout << s[i] << "  ";
		}
	}
};