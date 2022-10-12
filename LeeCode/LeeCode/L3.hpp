/************************************************************************/
/* 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
	 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

提示：
0 <= s.length <= 5 * 10^4
s 由英文字母、数字、符号和空格组成


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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