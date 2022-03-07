#pragma once
/************************************************************************/
/* ����һ���� �ǵݼ�˳�� ������������� nums������ ÿ�����ֵ�ƽ�� ��ɵ������飬Ҫ��Ҳ�� �ǵݼ�˳�� ����
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/squares-of-a-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

��ʾ��
	1 <= nums.length <= 10^4
	-10^4 <= nums[i] <= 10^4
	nums �Ѱ� �ǵݼ�˳�� ����
*/
/************************************************************************/

#include <vector>
#include <list>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> result_squ;
		result_squ.reserve(nums.size());
		list<int> list_fushu;

		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
		{
			int v = (*iter) * (*iter);

			if (*iter >= 0)
			{	
				while (!list_fushu.empty())
				{
					int fushuv = list_fushu.front();

					if (fushuv <= v)
					{
						result_squ.emplace_back(fushuv);
						list_fushu.pop_front();
					}
					else
					{
						break;
					}
				}

				result_squ.emplace_back(v);
			}
			else
			{
				list_fushu.emplace_front(v);
			}
		}

		for (list<int>::iterator iter = list_fushu.begin(); iter != list_fushu.end(); ++iter)
		{
			result_squ.emplace_back(*iter);
		}

		return result_squ;
	}

	void test()
	{
		vector<int> nums = {-4,-1,0,3,10};
		vector<int> rtn = sortedSquares(nums);

		for (vector<int>::iterator iter = rtn.begin(); iter != rtn.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
};