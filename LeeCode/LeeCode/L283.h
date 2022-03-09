#pragma once
/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:

输入: nums = [0, 1, 0, 3, 12]
	输出 : [1, 3, 12, 0, 0]

	示例 2 :
	输入 : nums = [0]
	输出 : [0]

	提示 :

	1 <= nums.length <= 10^4
	- 2^31 <= nums[i] <= 2^31 - 1

	进阶：你能尽量减少完成的操作次数吗？

	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/move-zeroes
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	*/

#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		//vector<int> newvec;
		//newvec.reserve(nums.size());

		//int times = 0;

		//for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
		//{
		//	if (*iter == 0)
		//	{
		//		++times;
		//	}
		//	else
		//	{
		//		newvec.emplace_back(*iter);
		//	}
		//}

		//for (int n = 0; n < newvec.size(); ++n)
		//{
		//	nums[n] = newvec[n];
		//}

		//int len = newvec.size();

		//for (int n = 0; n < times; ++n)
		//{
		//	nums[len + n] = 0;
		//}

		int zero_p = 0;

		for (int n = 0; n < nums.size(); ++n)
		{
			if (nums[n] != 0)
			{
				if (zero_p == n)
				{
					++zero_p;
					continue;
				}

				nums[zero_p++] = nums[n];
				nums[n] = 0;
			}
		}
	}
};