#pragma once
//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//
//�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/search-insert-position
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
/*
��ʾ:

1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums Ϊ���ظ�Ԫ�ص�������������
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