#pragma once
/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
��ע�� �������ڲ���������������ԭ�ض�������в�����

ʾ�� 1:

����: nums = [0, 1, 0, 3, 12]
	��� : [1, 3, 12, 0, 0]

	ʾ�� 2 :
	���� : nums = [0]
	��� : [0]

	��ʾ :

	1 <= nums.length <= 10^4
	- 2^31 <= nums[i] <= 2^31 - 1

	���ף����ܾ���������ɵĲ���������

	��Դ�����ۣ�LeetCode��
	���ӣ�https ://leetcode-cn.com/problems/move-zeroes
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
	*/

#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		//vector<int> newvec;
		//newvec.reserve(nums.size());

		//int times = 0;

		//for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
		//{
		//	if (*iter == 0)
		//	{
		//		++times;
		//	}
		//	else
		//	{
		//		newvec.emplace_back(*iter);
		//	}
		//}

		//for (int n = 0; n < newvec.size(); ++n)
		//{
		//	nums[n] = newvec[n];
		//}

		//int len = newvec.size();

		//for (int n = 0; n < times; ++n)
		//{
		//	nums[len + n] = 0;
		//}

		int zero_p = 0;

		for (int n = 0; n < nums.size(); ++n)
		{
			if (nums[n] != 0)
			{
				if (zero_p == n)
				{
					++zero_p;
					continue;
				}

				nums[zero_p++] = nums[n];
				nums[n] = 0;
			}
		}
	}
};