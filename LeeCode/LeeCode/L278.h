#pragma once
/*
���ǲ�Ʒ����Ŀǰ���ڴ���һ���Ŷӿ����µĲ�Ʒ�����ҵ��ǣ���Ĳ�Ʒ�����°汾û��ͨ��������⡣����ÿ���汾���ǻ���֮ǰ�İ汾�����ģ�
���Դ���İ汾֮������а汾���Ǵ�ġ�

�������� n ���汾[1, 2, ..., n]�������ҳ�����֮�����а汾����ĵ�һ������İ汾��

�����ͨ������ bool isBadVersion(version) �ӿ����жϰ汾�� version �Ƿ��ڵ�Ԫ�����г���ʵ��һ�����������ҵ�һ������İ汾��
��Ӧ�þ������ٶԵ��� API �Ĵ�����
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
//��ʾ��
//1 <= bad <= n <= 2^31 - 1


bool isBadVersion(int version)
{
	return true;
}

class Solution {
public:
	int firstBadVersion(int n) {
		//int failv = n + 1; --��������intԽ��
		int failv = n;
		int startv = 1;
		int endv = n;

		while (startv <= endv)
		{
			int middle = (endv - startv) / 2 + startv;

			if (isBadVersion(middle))
			{
				if (failv >= middle)
				{
					failv = middle;
					endv = middle - 1;
					continue;
				}
			}

			startv = middle + 1;
		}

		return failv;
	}
};