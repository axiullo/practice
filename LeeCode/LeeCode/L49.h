#pragma once
/*
����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�
��ĸ��λ�� ������������Դ���ʵ�������ĸ�õ���һ���µ��ʡ�

ʾ�� 1:
����: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
��� : [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]

ʾ�� 2 :
���� : strs = [""]
��� : [[""]]

ʾ�� 3 :
���� : strs = ["a"]
��� : [["a"]]

��ʾ��
	1 <= strs.length <= 104
	0 <= strs[i].length <= 100
	strs[i] ������Сд��ĸ

	https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked


	˼·��
	�������
	1�����������ַ�����Ҫһ��
	2.1���Ƚ��ַ�������Ȼ��Ƚ�����֮����ĸ�Ƿ���ͬ��
	2.2  ����һ��B���ʣ�����A���ʵ�ÿ�����ʣ���B�ĸ����������ҵ���Ӧ�ַ�����Ӹ�������ɾ���� ������A��B�Ĵ�С����0 �򵥴ʲ�ƥ�䣬 ����0�����ʷ�������
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

	//��ĸ��������
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
