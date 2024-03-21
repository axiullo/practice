#pragma once
/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出 : [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]

示例 2 :
输入 : strs = [""]
输出 : [[""]]

示例 3 :
输入 : strs = ["a"]
输出 : [["a"]]

提示：
	1 <= strs.length <= 104
	0 <= strs[i].length <= 100
	strs[i] 仅包含小写字母

	https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked


	思路：
	数组遍历
	1，两个单词字符个数要一致
	2.1，先将字符串排序，然后比较两者之间字母是否相同。
	2.2  复制一份B单词，遍历A单词的每个单词，在B的复制体中中找到对应字符，则从复制体中删除。 遍历完A，B的大小大于0 则单词不匹配， 等于0两单词符合条件
*/

#include <list>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> allResultVec;
		list<int> hadFindIndexList;

		for (int n = 0; n < strs.size(); ++n) {
			string an = strs[n];
			bool isFind = false;

			for (list<int>::iterator iter = hadFindIndexList.begin(); iter != hadFindIndexList.end(); ++iter) {
				if (*iter == n) {
					isFind = true;
					break;
				}
			}

			if (isFind) {
				continue;
			}

			vector<string> resultVec;
			resultVec.push_back(an);

			for (int nn = n + 1; nn < strs.size(); ++nn)
			{
				if (an.size() != strs[nn].size())
				{
					continue;
				}

				string strB = strs[nn];
				bool isSame = true;

				for (int i = 0; i < an.size(); ++i) {
					char c = an[i];

					for (int ii = 0; ii < strB.size(); ++ii) {
						if (c == strB[ii]) {
							strB.erase(ii, 1);
							break;
						}
					}
				}

				if (strB.size() > 0) {
					isSame = false;
				}

				if (isSame)
				{
					resultVec.push_back(strs[nn]);
					hadFindIndexList.push_back(nn);
				}
			}

			allResultVec.push_back(resultVec);
		}

		return allResultVec;
	}

	//字母重新排序
	//string charSort(string str) {
	//	string ret;
	//	return ret
	//}

	void test() {
		vector<string> vecStrs = { "eat", "tea", "tan", "ate", "nat", "bat" };
		vector<vector<string>> allresult = groupAnagrams(vecStrs);

		for (vector<vector<string>>::iterator iter = allresult.begin(); iter != allresult.end(); ++iter)
		{
			vector<string> anGroup = *iter;
			cout << " group start" << endl;

			string printStr;
			for (vector<string>::iterator secIter = anGroup.begin(); secIter != anGroup.end(); ++secIter)
			{
				printStr.append(*secIter + " ");
			}

			cout << printStr << endl;
			cout << "group end" << endl;
		}
	}
};
