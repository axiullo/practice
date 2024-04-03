#pragma once
/*
* 给你一个整数数组nums，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。


提示：
3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum_example(vector<int>& nums) {
		vector<vector<int>> allVecs;
		sort(nums.begin(), nums.end());// 排序（默认递增）

		for (auto n = 0; n < nums.size() - 2; ++n) {
			if (nums[n] > 0) {
				//后面全是正值，不会和为0。
				break;
			}

			if (n != 0 && nums[n] == nums[n - 1]) {
				//结果不能重复。
				continue;
			}

			twoSum(nums[n], n + 1, nums.size() - 1, nums, allVecs);
		}

		return allVecs;
	}

	void twoSum(int targetNum, int start, int end, vector<int>& nums, vector<vector<int>>& allVecs)
	{
		while (start < end)
		{
			if (-targetNum == nums[start] + nums[end])
			{
				allVecs.push_back({ targetNum, nums[start], nums[end] });

				while (start < end && nums[start] == nums[start + 1])
				{
					++start;
				}
				++start;

				while (start < end && nums[end] == nums[end - 1])
				{
					--end;
				}
				--end;
			}
			else if (-targetNum > nums[start] + nums[end]) {
				++start;
			}
			else
			{
				--end;
			}
		}
	}

	vector<vector<int>> threeSum_(vector<int>& nums) {
		vector<vector<int>> allVecs;
		sort(nums.begin(), nums.end());// 排序（默认递增）

		for (auto s1 = 0; s1 < nums.size() - 2; ++s1)
		{
			if (nums[s1] > 0) {
				//后面全是正值，不会和为0。
				break;
			}

			if (s1 != 0 && nums[s1] == nums[s1 - 1]) {
				//结果不能重复。
				continue;
			}

			int off = 0;

			for (auto s2 = s1 + 1; s2 < nums.size() - 1; ++s2)
			{
				if (s2 != (s1 + 1) && nums[s2] == nums[s2 - 1]) {
					//结果不能重复。
					continue;
				}

				for (auto s3 = s2 + 1; s3 < nums.size() - off; ++s3)
				{
					if (nums[s1] + nums[s2] + nums[s3] == 0)
					{
						++off;
						allVecs.push_back({ nums[s1] , nums[s2] , nums[s3] });
					}
				}
			}
		}

		return allVecs;
	}

	vector<vector<int>> threeSum1(vector<int>& nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		// 枚举 a
		for (int first = 0; first < n; ++first) {
			// 需要和上一次枚举的数不相同
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			// c 对应的指针初始指向数组的最右端
			int third = n - 1;
			int target = -nums[first];
			// 枚举 b
			for (int second = first + 1; second < n; ++second) {
				// 需要和上一次枚举的数不相同
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}
				// 需要保证 b 的指针在 c 的指针的左侧
				while (second < third && nums[second] + nums[third] > target) {
					--third;
				}
				// 如果指针重合，随着 b 后续的增加
				// 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
				if (second == third) {
					break;
				}
				if (nums[second] + nums[third] == target) {
					ans.push_back({ nums[first], nums[second], nums[third] });
				}
			}
		}
		return ans;
	}

	void test()
	{
		//vector<int> nums = { -1,0,1,2,-1,-4 };  //[[-1,-1,2],[-1,0,1]]
		//vector<int> nums = { 0,1,1 }; //[]
		//vector<int> nums = { 0,0,0 };  //[[0,0,0]]
		//vector<int> nums = { 0, 0, 0, 0 };//[[0,0,0]]
		vector<int> nums = { -1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4 }; //[[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]

		auto retVecs = threeSum1(nums);

		for (auto an : retVecs)
		{
			cout << "*******************" << endl;
			for (auto v : an)
			{
				cout << v << " ";
			}

			cout << endl;
		}
	}
};