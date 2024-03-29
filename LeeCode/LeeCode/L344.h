#pragma once
/************************************************************************/
/* 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

提示：

	1 <= s.length <= 10^5
	s[i] 都是 ASCII 码表中的可打印字符


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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