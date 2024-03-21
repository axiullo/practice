#pragma once
/************************************************************************/
/*
����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�
������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣

ʾ�� 1��
���룺nums = [100,4,200,1,3,2]
�����4
���ͣ���������������� [1, 2, 3, 4]�����ĳ���Ϊ 4��

ʾ�� 2��
���룺nums = [0,3,7,2,5,8,4,6,0,1]
�����9

��ʾ��
	0 <= nums.length <= 10^5
	-10^9 <= nums[i] <= 10^9

	https://leetcode.cn/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-100-liked

	˼·��
	��һ����
	1. �Ȱ���������
	2. �������飬��ǰֵ����һ��ֵ�Ƿ������� ����������������һ��ֵ���ű����ж�; ��������������ȡ�

	���˼·���ԣ�����Ļ�ʱ�临�ӶȲ�����O(n)������ֻ�ܱ���һ�κ���ҵ�������

	����map�� ��key���б������ҡ�
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

		//��ͨ��map���˵��ظ�Ԫ��
		for (auto v : nums)
		{
			keymap[v]++;
		}

		int len = 0;

		for (const auto& pair : keymap)
		{
			int tmp = 0;
			auto curKey = pair.first;

			//�����ǰ��ֵ��������Ҫ�� Ҫ�ҵ������������
			if (keymap.find(curKey - 1) != keymap.end()) {
				continue;
			}

			tmp++;

			//Ѱ��������
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

	// ʹ�ù�ϣ������������
	int example_longestConsecutive(vector<int>& nums) {
		//���ӣ�https://leetcode.cn/problems/longest-consecutive-sequence/solutions/1/jie-dian-zuo-you-yao-yao-shi-du-li-jie-d-cm93/
		int res = 0;
		unordered_map <int, int>map;
		for (int k : nums) {
			if (map.count(k)) continue;
			// ��һ�µ�ǰ�ڵ�����ҽڵ���������
			int l = map.count(k - 1) ? map[k - 1] : 0;
			int r = map.count(k + 1) ? map[k + 1] : 0;
			// �˵��д��һ������ĳ���
			map[k] = l + r + 1;
			// ������˵����һ������ĳ���
			map[k - l] = map[k];
			map[k + r] = map[k];
			res = max(res, map[k]);
		}
		return res;
	}

	int example_longestConsecutive_2(vector<int>& nums) {
		//���ӣ�https://leetcode.cn/problems/longest-consecutive-sequence/solutions/1/c-128-zui-chang-lian-xu-xu-lie-ha-xi-bia-oy5l/
			//�������� --> ��ϣ��
		unordered_map<int, int> mp;
		for (auto t : nums) {
			mp[t]++;
		}
		int res = 0;
		for (auto t : nums) {
			if (mp[t - 1]) continue; //�������ֱ������ ö�����
			int len = 1;
			while (mp[++t]) len++;
			res = max(res, len);
		}

		return res;
	}
};