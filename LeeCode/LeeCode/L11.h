#pragma once
/*
* https://leetcode.cn/problems/container-with-most-water/?envType=study-plan-v2&envId=top-100-liked
* 当前的最大水量
* 起始索引 终点索引
*
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int ret = 0;
		int startIndex = 0;
		int endIndex = height.size() - 1;

		while (startIndex != endIndex)
		{
			int n = endIndex - startIndex;
			int minHeight = height[endIndex] >= height[startIndex] ? height[startIndex++] : height[endIndex--];
			auto tmp = minHeight * n;

			if (tmp > ret) {
				ret = tmp;
			}
		}

		return ret;
	}

	void test()
	{
		vector<int> height = { 1,8,6,2,5,4,8,3,7 };
		int r = maxArea(height);
		cout << r << endl;

		height = { 1,1 };
		r = maxArea(height);
		cout << r << endl;
	}
};