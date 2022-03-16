#pragma once
/************************************************************************/
/* 给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]


提示：

	1 <= nums.length <= 10^5
	-2^31 <= nums[i] <= 2^31 - 1
	0 <= k <= 10^5
*/
/************************************************************************/

#include <vector>
#include <list>
#include <iostream>
using namespace std;

class Solution {
public:
	void swap(vector<int>& nums, int start_idx, int end_idx)
	{
		if (start_idx >= nums.size() || end_idx >= nums.size()) {
			return;
		}

		while (start_idx < end_idx)
		{
			int t = nums[start_idx];
			nums[start_idx] = nums[end_idx];
			nums[end_idx] = t;
			++start_idx;
			--end_idx;
		}
	}

	void rotate(vector<int>& nums, int k)
	{
		//超时
		//for (int i = 0; i < k; ++i)
		//{
		//	int v = nums[nums.size() - 1];

		//	for (int pos = 0; pos < nums.size(); ++pos)
		//	{
		//		int tmpv = nums[pos];
		//		nums[pos] = v;
		//		v = tmpv;
		//	}
		//}
		k %= nums.size();
		swap(nums, 0, nums.size() - 1);
		swap(nums, 0, k -1);
		swap(nums, k, nums.size() -1);
	}

	void test()
	{
		vector<int> nums;
		nums = { 1,2,3,4,5,6,7 };
		rotate(nums, 3);

		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
		{
			cout << *iter << " ";
		}

		cout << endl;

		nums = { -1,-100,3,99 };
		rotate(nums, 2);

		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
		{
			cout << *iter << " ";
		}

		cout << endl;

		nums = { -1 };
		rotate(nums, 3);

		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
		{
			cout << *iter << " ";
		}

		cout << endl;
	}
};