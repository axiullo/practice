#pragma once
/*
 https://leetcode.cn/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-100-liked

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

示例 2：
输入：height = [4,2,0,3,2,5]
输出：9

提示：
	n == height.length
	1 <= n <= 2 * 10^4
	0 <= height[i] <= 10^5

	思路
	从头遍历， 找到某段的两个高点，中间容量++，寻找下一个段。
	如果左边头比右边尾低，则头改变为尾，尾从后节点再找高节点。

	找每段的两个节点，其实就是找右节点的最高点。 右节点比左节点大于等于就是一段。如果找不到，则右节点最高的节点就是当前段的右节点。
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height)
	{
		int ret = 0;
		int leftIndex = 0;
		int endIndex = height.size() - 1;
		int curIndex = leftIndex + 1;
		int rightIndex = curIndex + 1;

		while (leftIndex + 1 < endIndex && rightIndex <= endIndex)
		{
			if (height[leftIndex] == 0) {
				++leftIndex;
				curIndex = leftIndex + 1;
				rightIndex = curIndex + 1;
				continue;
			}

			if (height[endIndex] == 0) {
				--endIndex;
				continue;
			}

			int maxv = max(height[leftIndex], height[curIndex]);
			int tmpindex = rightIndex;

			//找到本段的右端节点
			while (maxv > height[tmpindex] && tmpindex < endIndex)
			{
				++tmpindex;

				if (height[tmpindex] >= height[rightIndex]) {
					rightIndex = tmpindex;
				}
			}

			int curValue = 0;

			while (curIndex < rightIndex)
			{
				int minH = min(height[leftIndex], height[rightIndex]);
				curValue = height[curIndex];

				if (minH > curValue) {
					ret += minH - curValue;
					++curIndex;
				}
				else
				{
					break;
				}
			}

			if (curIndex == rightIndex) {
				//走到了一段的最后
				if (rightIndex == endIndex) {
					break;
				}

				leftIndex = rightIndex;
				curIndex = leftIndex + 1;
				rightIndex = curIndex + 1;
			}
			else
			{
				leftIndex = curIndex;
				curIndex = leftIndex + 1;
				rightIndex = curIndex + 1;
			}
		}

		return ret;
	}

	//动态规划版
	int trap_dynamic_planning_example(vector<int>& height) {
		int length = height.size();

		if (length <= 2) {
			return 0;
		}

		//从左边开始 每个节点最高高度
		vector<int> leftMax(length);
		leftMax[0] = height[0];

		for (auto n = 1; n <= length - 1; ++n) {
			leftMax[n] = max(leftMax[n - 1], height[n]);
		}

		//从右边开始  每个节点最高高度
		vector<int> rightMax(length);
		rightMax[length - 1] = height[length - 1];

		for (auto n = length - 2; n >= 0; --n) {
			rightMax[n] = max(rightMax[n + 1], height[n]);
		}

		int ret = 0;

		for (auto n = 0; n < length; ++n) {
			ret += min(leftMax[n], rightMax[n]) - height[n];
		}

		return ret;
	}

	int trap_example(vector<int>& height)
	{
		int l = 0, r = height.size() - 1, level = 0, water = 0;
		while (l < r)
		{
			int lower = height[height[l] < height[r] ? l++ : r--];
			level = max(level, lower);
			water += level - lower;
		}
		return water;
	}

	void test()
	{
		vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
		int v = trap_example(height);
		cout << v << endl;

		height = { 4, 2, 0, 3, 2, 5 };
		v = trap_dynamic_planning_example(height);
		cout << v << endl;

		vector<int> height2 = { 5, 4, 1, 2 };
		int v2 = trap_dynamic_planning_example(height2);
		cout << v2 << endl;


		height2 = { 1000, 999, 998, 997, 996, 995, 994, 993, 992, 991, 990, 989, 988, 987, 986, 985, 984, 983, 982, 981, 980, 979, 978, 977, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966 };
		v2 = trap_dynamic_planning_example(height2);
		cout << v2 << endl;

		vector<int> height3 = { 4, 9, 4, 5, 3, 2 };
		auto v3 = trap_dynamic_planning_example(height3);
		cout << v3 << endl;
	}
};