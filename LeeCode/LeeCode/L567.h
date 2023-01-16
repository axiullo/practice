#pragma once
/************************************************************************/
/* 
还没提交!!!

给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。
换句话说，s1 的排列之一是 s2 的 子串 。

示例 1：
输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").

示例 2：
输入：s1= "ab" s2 = "eidboaoo"
输出：false

测试用例:
1 输入:
"adc"
"dcda"
输出:
true

2 输入:
"abc"
"ccccbbbbaaaa"
输出:
false

3 输入:
"abcdxabcde"
"abcdeabcdx"
输出:
true


提示：
	1 <= s1.length, s2.length <= 10^4
	s1 和 s2 仅包含小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
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