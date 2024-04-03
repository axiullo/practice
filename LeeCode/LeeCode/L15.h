#pragma once
/*
* ����һ����������nums���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k ��ͬʱ������ nums[i] + nums[j] + nums[k] == 0 ��
���㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣
ע�⣺���в����԰����ظ�����Ԫ�顣

ʾ�� 1��
���룺nums = [-1,0,1,2,-1,-4]
�����[[-1,-1,2],[-1,0,1]]
���ͣ�
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 ��
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 ��
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 ��
��ͬ����Ԫ���� [-1,0,1] �� [-1,-1,2] ��
ע�⣬�����˳�����Ԫ���˳�򲢲���Ҫ��

ʾ�� 2��
���룺nums = [0,1,1]
�����[]
���ͣ�Ψһ���ܵ���Ԫ��Ͳ�Ϊ 0 ��

ʾ�� 3��
���룺nums = [0,0,0]
�����[[0,0,0]]
���ͣ�Ψһ���ܵ���Ԫ���Ϊ 0 ��


��ʾ��
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
		sort(nums.begin(), nums.end());// ����Ĭ�ϵ�����

		for (auto n = 0; n < nums.size() - 2; ++n) {
			if (nums[n] > 0) {
				//����ȫ����ֵ�������Ϊ0��
				break;
			}

			if (n != 0 && nums[n] == nums[n - 1]) {
				//��������ظ���
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
		sort(nums.begin(), nums.end());// ����Ĭ�ϵ�����

		for (auto s1 = 0; s1 < nums.size() - 2; ++s1)
		{
			if (nums[s1] > 0) {
				//����ȫ����ֵ�������Ϊ0��
				break;
			}

			if (s1 != 0 && nums[s1] == nums[s1 - 1]) {
				//��������ظ���
				continue;
			}

			int off = 0;

			for (auto s2 = s1 + 1; s2 < nums.size() - 1; ++s2)
			{
				if (s2 != (s1 + 1) && nums[s2] == nums[s2 - 1]) {
					//��������ظ���
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
		// ö�� a
		for (int first = 0; first < n; ++first) {
			// ��Ҫ����һ��ö�ٵ�������ͬ
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			// c ��Ӧ��ָ���ʼָ����������Ҷ�
			int third = n - 1;
			int target = -nums[first];
			// ö�� b
			for (int second = first + 1; second < n; ++second) {
				// ��Ҫ����һ��ö�ٵ�������ͬ
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}
				// ��Ҫ��֤ b ��ָ���� c ��ָ������
				while (second < third && nums[second] + nums[third] > target) {
					--third;
				}
				// ���ָ���غϣ����� b ����������
				// �Ͳ��������� a+b+c=0 ���� b<c �� c �ˣ������˳�ѭ��
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