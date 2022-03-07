#pragma once
/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/binary-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int start_pos = 0;
		int end_pos = nums.size() - 1;

		while (start_pos <= end_pos)
		{
			int middle = (end_pos - start_pos) / 2 + start_pos;

			if (nums[middle] == target)
			{
				return middle;
			}

			if (nums[middle] > target)
			{
				end_pos = middle - 1;
			}				
			else
			{
				start_pos = middle + 1;
			}

		}

		return -1;
	}

	void test()
	{
		vector<int> nums = { 1,4,6,7,10,15,20 };
		cout << search(nums, 0) << endl;
	}
};