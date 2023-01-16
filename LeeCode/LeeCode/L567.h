#pragma once
/************************************************************************/
/* 
��û�ύ!!!

���������ַ��� s1 �� s2 ��дһ���������ж� s2 �Ƿ���� s1 �����С�����ǣ����� true �����򣬷��� false ��
���仰˵��s1 ������֮һ�� s2 �� �Ӵ� ��

ʾ�� 1��
���룺s1 = "ab" s2 = "eidbaooo"
�����true
���ͣ�s2 ���� s1 ������֮һ ("ba").

ʾ�� 2��
���룺s1= "ab" s2 = "eidboaoo"
�����false

��������:
1 ����:
"adc"
"dcda"
���:
true

2 ����:
"abc"
"ccccbbbbaaaa"
���:
false

3 ����:
"abcdxabcde"
"abcdeabcdx"
���:
true


��ʾ��
	1 <= s1.length, s2.length <= 10^4
	s1 �� s2 ������Сд��ĸ

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/permutation-in-string
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������*/
/************************************************************************/

#include <string>
#include <unordered_set>

#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2)
	{
		unordered_set<int> s1_index_set;

		for (unsigned int index = 0; index < s2.length(); ++index)
		{
			bool isfind = false;
			const char& cur_char = s2[index];

			for (unsigned int idx = 0; idx < s1.length(); ++idx)
			{
				if (s1[idx] == cur_char && s1_index_set.find(idx) == s1_index_set.end())
				{
					s1_index_set.emplace(idx);
					isfind = true;
				}
			}

			if (!isfind)
			{
				s1_index_set.clear();
			}
			else
			{
				if (s1_index_set.size() == s1.length())
				{
					return true;
				}
			}
		}

		return false;
	}

	void test()
	{

	}
};