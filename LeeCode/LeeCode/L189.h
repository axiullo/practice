#pragma once
/************************************************************************/
/* ����һ�����飬�������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/rotate-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


����: nums = [1,2,3,4,5,6,7], k = 3
���: [5,6,7,1,2,3,4]
����:
������ת 1 ��: [7,1,2,3,4,5,6]
������ת 2 ��: [6,7,1,2,3,4,5]
������ת 3 ��: [5,6,7,1,2,3,4]


��ʾ��

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
		//��ʱ
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