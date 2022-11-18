#pragma once
/*********************************************************************
����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��

��������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

	���磬121 �ǻ��ģ��� 123 ���ǡ�


ʾ�� 1��

���룺x = 121
�����true

ʾ�� 2��

���룺x = -121
�����false
���ͣ��������Ҷ�, Ϊ -121 �� ���������, Ϊ 121- �����������һ����������

ʾ�� 3��

���룺x = 10
�����false
���ͣ����������, Ϊ 01 �����������һ����������

��ʾ��

	-231 <= x <= 231 - 1


���ף����ܲ�������תΪ�ַ�����������������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/palindrome-number
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

##˼·:
1. �����϶����ǻ�����
2. �����ֵ�ÿ������ת��Ϊ����, Ȼ���ٽ����鵹����س���, �ж��������Ƿ�һ��. Ҳ�����ж�����ǰ�������Ƿ�һ��.

©��:
1.���и�λ��0�����ֶ��������ǻ�����
2.Ϊʲô������ֻ��תint���ֵ�һ�룿
���ڵ������ǣ��������֪����ת���ֵ�λ���Ѿ��ﵽԭʼ����λ����һ�룿
���������������ǲ��Ͻ�ԭʼ���ֳ��� 10��Ȼ�����ת������ֳ��� 10��
���ԣ���ԭʼ����С�ڻ���ڷ�ת�������ʱ������ζ�������Ѿ�������һ��λ���������ˡ�
�����ֳ���Ϊ����ʱ�����ǿ���ͨ�� revertedNumber/10 ȥ��������λ�����֡�
*/

//#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x %10 ==0 && x != 0))  //©���˸�λ����0�����
		{
			return false;
		}

		//vector<int> vec_nums;
		int a_nums[10] = {};
		int len = 0;
		int tx = x;

		while (tx >= 10)
		{
			a_nums[len++] = tx % 10;
			tx = tx / 10;
		}

		if (tx > 0)
		{
			a_nums[len++] = tx;
		}

		int head = 0;
		int tail = len - 1;

		while (head < tail)
		{
			if (a_nums[head] != a_nums[tail])
			{
				return false;
			}

			++head;
			--tail;
		}

		return true;
	}

	void test()
	{
		cout << isPalindrome(1) << endl;
		cout << isPalindrome(10) <<endl;
		cout << isPalindrome(11) << endl;
		cout << isPalindrome(12) << endl;
		cout << isPalindrome(121) << endl;
	}
};