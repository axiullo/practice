#pragma once
/*
����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/binary-search
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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