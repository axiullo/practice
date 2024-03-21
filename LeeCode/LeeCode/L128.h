#pragma once
/************************************************************************/
/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

示例 2：
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9

提示：
	0 <= nums.length <= 10^5
	-10^9 <= nums[i] <= 10^9

	https://leetcode.cn/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-100-liked

	思路：
	第一个：
	1. 先把数组排序
	2. 遍历数组，当前值和下一个值是否连续， 如果不连续，则从下一个值接着遍历判断; 如果连续计数长度。

	这个思路不对，排序的话时间复杂度不会是O(n)，所以只能遍历一次后就找到连续数

	利用map， 对key进行遍历查找。
*/
/************************************************************************/

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		bubble(nums);

		int result = 0;
		int len = 0;

		for (int n = 0; n < (int)nums.size() - 1; ++n) {
			if (nums[n + 1] == nums[n]) {
				continue;
			}

			if (abs(nums[n + 1] - nums[n]) == 1) {
				len++;
			}
			else {
				if (len > result) {
					result = len;
				}

				len = 0;
			}
		}

		if (len > result) {
			result = len;
		}

		if (result > 0) {
			result += 1;
		}
		else {
			if (nums.size() > 0) {
				result = 1;
			}
		}

		return result;
	}

	void bubble(vector<int>& nums)
	{
		for (int n = 0; n < ((int)nums.size() - 1); ++n) {
			for (int m = n + 1; m < (int)nums.size(); ++m) {
				if (nums[n] > nums[m]) {
					int t = nums[m];
					nums[m] = nums[n];
					nums[n] = t;
				}
			}
		}
	}

	int longestConsecutive2(vector<int>& nums) {
		if (nums.size() == 1) {
			return 1;
		}

		unordered_map<int, int> keymap;

		//先通过map过滤掉重复元素
		for (auto v : nums)
		{
			keymap[v]++;
		}

		int len = 0;

		for (const auto& pair : keymap)
		{
			int tmp = 0;
			auto curKey = pair.first;

			//如果有前置值，不符合要求。 要找到连续数的起点
			if (keymap.find(curKey - 1) != keymap.end()) {
				continue;
			}

			tmp++;

			//寻找连续数
			while (keymap.find(++curKey) != keymap.end()) {
				tmp++;
			}

			len = max(tmp, len);
		}

		return len;
	}

	void test()
	{
		vector<int> nums = { 100,4,200,1,3,2 };
		int len = longestConsecutive2(nums);
		cout << len << endl;

		nums = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
		len = longestConsecutive2(nums);
		cout << len << endl;

		nums = {};
		len = longestConsecutive2(nums);
		cout << len << endl;
	}

	// 使用哈希表来构造区间
	int example_longestConsecutive(vector<int>& nums) {
		//链接：https://leetcode.cn/problems/longest-consecutive-sequence/solutions/1/jie-dian-zuo-you-yao-yao-shi-du-li-jie-d-cm93/
		int res = 0;
		unordered_map <int, int>map;
		for (int k : nums) {
			if (map.count(k)) continue;
			// 看一下当前节点的左右节点是区间吗
			int l = map.count(k - 1) ? map[k - 1] : 0;
			int r = map.count(k + 1) ? map[k + 1] : 0;
			// 端点中存放一个区间的长度
			map[k] = l + r + 1;
			// 在区间端点更新一下区间的长度
			map[k - l] = map[k];
			map[k + r] = map[k];
			res = max(res, map[k]);
		}
		return res;
	}

	int example_longestConsecutive_2(vector<int>& nums) {
		//链接：https://leetcode.cn/problems/longest-consecutive-sequence/solutions/1/c-128-zui-chang-lian-xu-xu-lie-ha-xi-bia-oy5l/
			//特征归类 --> 哈希表
		unordered_map<int, int> mp;
		for (auto t : nums) {
			mp[t]++;
		}
		int res = 0;
		for (auto t : nums) {
			if (mp[t - 1]) continue; //不是起点直接跳过 枚举起点
			int len = 1;
			while (mp[++t]) len++;
			res = max(res, len);
		}

		return res;
	}
};