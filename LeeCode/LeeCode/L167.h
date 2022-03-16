#pragma once
/*
给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。
如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。
以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。
你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
你所设计的解决方案必须只使用常量级的额外空间。

提示：
	2 <= numbers.length <= 3 * 104
	-1000 <= numbers[i] <= 1000
	numbers 按 非递减顺序 排列
	-1000 <= target <= 1000
	仅存在一个有效答案

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
	//寻找索引
	int findIndex(vector<int>& numbers, int find_num, int start_pos, int end_pos)
	{
		while (start_pos <= end_pos)
		{
			int middle = (end_pos + start_pos) / 2;

			if (numbers[middle] == find_num) {
				return middle;
			}

			if (numbers[middle] > find_num)
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

	vector<int> twoSum(vector<int>& numbers, int target) {
		int len = numbers.size();

		for (int n = 0; n < len - 1; ++n)
		{
			int find_num = target - numbers[n];
			int idx = findIndex(numbers, find_num, n + 1, len - 1);

			if (idx > 0)
			{
				return vector<int>({ n +1, idx+ 1 });
			}
		}

		return vector<int>({ 0, 0 });
	}

	void test()
	{

	}
};