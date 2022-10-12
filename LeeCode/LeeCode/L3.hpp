/************************************************************************/
/* ����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

ʾ�� 1:

����: s = "abcabcbb"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

ʾ�� 2:

����: s = "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��

ʾ�� 3:

����: s = "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
	 ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���

��ʾ��
0 <= s.length <= 5 * 10^4
s ��Ӣ����ĸ�����֡����źͿո����


��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

*/
/************************************************************************/

#include <iostream>
#include <string>
#include<unordered_map>

#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unsigned int len = s.length();

		if (len == 0) 
		{
			return 0;
		}

		int ret_len = 0;
		unordered_map<char, int> map_char;
		//vector< vector<int> > find_list;

		int startindex = 0;
		int endindex = 0;
		int cur_len = 0;

		for (unsigned int index = 0; index < len; ++index)
		{
			auto iter = map_char.find(s[index]);

			if (iter == map_char.end())
			{
				endindex = index;
				++cur_len;
				//map_char.insert({ s[index], index });
				map_char.emplace(s[index], index);
			}
			else
			{
				//vector<int> an;
				//an.push_back(startindex);
				//an.push_back(endindex);
				//find_list.push_back(an);

				if (cur_len > ret_len)
				{
					ret_len = cur_len;
				}

				startindex = iter->second + 1;
				endindex = index;

				cur_len = 0;
				unordered_map<char, int> tmp_map_char;

				for (unsigned int n = startindex; n <= index; ++n)
				{
					//tmp_map_char.insert({ s[n], n });
					tmp_map_char.emplace(s[n], n );
					++cur_len;
				}

				map_char.swap(tmp_map_char);
			}
		}

		if (cur_len > ret_len)
		{
			ret_len = cur_len;
		}


		//cout << "********************* " << endl;
		//for (unsigned int n = 0; n < find_list.size(); ++n)
		//{
		//	vector<int>& t = find_list[n];
		//	cout << t[0] << ", " << t[1] << endl;
		//}
		//cout << "********************* " << endl;

		return ret_len;
	}

	void test()
	{
		string s = "abcabcbb";
		int ret = lengthOfLongestSubstring(s);
		cout << ret << endl;

		/*string s1 = "bbbbb";
		int ret1 = lengthOfLongestSubstring(s1);
		cout << ret1 << endl;


		string s2 = "pwwkew";
		int ret2 = lengthOfLongestSubstring(s2);
		cout << ret2 << endl;

		string s3 = "";
		int ret3 = lengthOfLongestSubstring(s3);
		cout << ret3 << endl;

		string s4 = " ";
		int ret4 = lengthOfLongestSubstring(s4);
		cout << ret4 << endl;*/
	}
};