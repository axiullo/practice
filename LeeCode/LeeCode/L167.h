#pragma once
/*
����һ���±�� 1 ��ʼ���������� numbers ���������Ѱ� �ǵݼ�˳������  ��������������ҳ��������֮�͵���Ŀ���� target ����������
��������������ֱ��� numbers[index1] �� numbers[index2] ���� 1 <= index1 < index2 <= numbers.length ��
�Գ���Ϊ 2 ���������� [index1, index2] ����ʽ�����������������±� index1 �� index2��
����Լ���ÿ������ ֻ��ӦΨһ�Ĵ� �������� ������ �ظ�ʹ����ͬ��Ԫ�ء�
������ƵĽ����������ֻʹ�ó������Ķ���ռ䡣

��ʾ��
	2 <= numbers.length <= 3 * 104
	-1000 <= numbers[i] <= 1000
	numbers �� �ǵݼ�˳�� ����
	-1000 <= target <= 1000
	������һ����Ч��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <vector>
using namespace std;

class Solution {
public:
	//Ѱ������
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