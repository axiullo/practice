#pragma once
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//请必须使用时间复杂度为 O(log n) 的算法。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/search-insert-position
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/*
提示:

1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums 为无重复元素的升序排列数组
-10^4 <= target <= 10^4
*/

#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int start_pos = 0;
		int end_pos = nums.size() - 1;

		while (start_pos <= end_pos)
		{
			int middle = (end_pos - start_pos) / 2 + start_pos;

			if(nums[middle] == target)
			{
				return  middle;
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

		return start_pos;
	}
};