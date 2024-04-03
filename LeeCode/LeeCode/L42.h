#pragma once
/*
 https://leetcode.cn/problems/trapping-rain-water/?envType=study-plan-v2&envId=top-100-liked

���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��

ʾ�� 1��
���룺height = [0,1,0,2,1,0,1,3,2,1,2,1]
�����6
���ͣ������������� [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ�ĸ߶�ͼ������������£����Խ� 6 ����λ����ˮ����ɫ���ֱ�ʾ��ˮ����

ʾ�� 2��
���룺height = [4,2,0,3,2,5]
�����9

��ʾ��
	n == height.length
	1 <= n <= 2 * 10^4
	0 <= height[i] <= 10^5

	˼·
	��ͷ������ �ҵ�ĳ�ε������ߵ㣬�м�����++��Ѱ����һ���Ρ�
	������ͷ���ұ�β�ͣ���ͷ�ı�Ϊβ��β�Ӻ�ڵ����Ҹ߽ڵ㡣

	��ÿ�ε������ڵ㣬��ʵ�������ҽڵ����ߵ㡣 �ҽڵ����ڵ���ڵ��ھ���һ�Ρ�����Ҳ��������ҽڵ���ߵĽڵ���ǵ�ǰ�ε��ҽڵ㡣
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height)
	{
		int ret = 0;
		int leftIndex = 0;
		int endIndex = height.size() - 1;
		int curIndex = leftIndex + 1;
		int rightIndex = curIndex + 1;

		while (leftIndex + 1 < endIndex && rightIndex <= endIndex)
		{
			if (height[leftIndex] == 0) {
				++leftIndex;
				curIndex = leftIndex + 1;
				rightIndex = curIndex + 1;
				continue;
			}

			if (height[endIndex] == 0) {
				--endIndex;
				continue;
			}

			int maxv = max(height[leftIndex], height[curIndex]);
			int tmpindex = rightIndex;

			//�ҵ����ε��Ҷ˽ڵ�
			while (maxv > height[tmpindex] && tmpindex < endIndex)
			{
				++tmpindex;

				if (height[tmpindex] >= height[rightIndex]) {
					rightIndex = tmpindex;
				}
			}

			int curValue = 0;

			while (curIndex < rightIndex)
			{
				int minH = min(height[leftIndex], height[rightIndex]);
				curValue = height[curIndex];

				if (minH > curValue) {
					ret += minH - curValue;
					++curIndex;
				}
				else
				{
					break;
				}
			}

			if (curIndex == rightIndex) {
				//�ߵ���һ�ε����
				if (rightIndex == endIndex) {
					break;
				}

				leftIndex = rightIndex;
				curIndex = leftIndex + 1;
				rightIndex = curIndex + 1;
			}
			else
			{
				leftIndex = curIndex;
				curIndex = leftIndex + 1;
				rightIndex = curIndex + 1;
			}
		}

		return ret;
	}

	//��̬�滮��
	int trap_dynamic_planning_example(vector<int>& height) {
		int length = height.size();

		if (length <= 2) {
			return 0;
		}

		//����߿�ʼ ÿ���ڵ���߸߶�
		vector<int> leftMax(length);
		leftMax[0] = height[0];

		for (auto n = 1; n <= length - 1; ++n) {
			leftMax[n] = max(leftMax[n - 1], height[n]);
		}

		//���ұ߿�ʼ  ÿ���ڵ���߸߶�
		vector<int> rightMax(length);
		rightMax[length - 1] = height[length - 1];

		for (auto n = length - 2; n >= 0; --n) {
			rightMax[n] = max(rightMax[n + 1], height[n]);
		}

		int ret = 0;

		for (auto n = 0; n < length; ++n) {
			ret += min(leftMax[n], rightMax[n]) - height[n];
		}

		return ret;
	}

	int trap_example(vector<int>& height)
	{
		int l = 0, r = height.size() - 1, level = 0, water = 0;
		while (l < r)
		{
			int lower = height[height[l] < height[r] ? l++ : r--];
			level = max(level, lower);
			water += level - lower;
		}
		return water;
	}

	void test()
	{
		vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
		int v = trap_example(height);
		cout << v << endl;

		height = { 4, 2, 0, 3, 2, 5 };
		v = trap_dynamic_planning_example(height);
		cout << v << endl;

		vector<int> height2 = { 5, 4, 1, 2 };
		int v2 = trap_dynamic_planning_example(height2);
		cout << v2 << endl;


		height2 = { 1000, 999, 998, 997, 996, 995, 994, 993, 992, 991, 990, 989, 988, 987, 986, 985, 984, 983, 982, 981, 980, 979, 978, 977, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966, 966 };
		v2 = trap_dynamic_planning_example(height2);
		cout << v2 << endl;

		vector<int> height3 = { 4, 9, 4, 5, 3, 2 };
		auto v3 = trap_dynamic_planning_example(height3);
		cout << v3 << endl;
	}
};