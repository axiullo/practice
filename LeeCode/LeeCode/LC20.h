#pragma once
/**
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
��ֵ����˳�򣩿��Էֳ����¼������֣�
	���ɿո�
	һ�� С�� ���� ����
	����ѡ��һ�� 'e' �� 'E' ���������һ�� ����
	���ɿո�

С������˳�򣩿��Էֳ����¼������֣�
	����ѡ��һ�������ַ���'+' �� '-'��
	������ʽ֮һ��
		����һλ���֣��������һ���� '.'
		����һλ���֣��������һ���� '.' �������ٸ�������һλ����
		һ���� '.' �������������һλ����

��������˳�򣩿��Էֳ����¼������֣�
	����ѡ��һ�������ַ���'+' �� '-'��
	����һλ����

������ֵ�о����£�
	["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]

���ַ���ֵ�о����£�
	["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]

ʾ�� 1��
���룺s = "0"
�����true

ʾ�� 2��
���룺s = "e"
�����false

ʾ�� 3��
���룺s = "."
�����false

ʾ�� 4��
���룺s = "    .1  "
�����true

��ʾ��
	1 <= s.length <= 20
	s ����Ӣ����ĸ����д��Сд�������֣�0-9�����Ӻ� '+' ������ '-' ���ո� ' ' ���ߵ� '.' ��

���ߣ�Krahets
���ӣ�https://leetcode.cn/leetbook/read/illustration-of-algorithm/5d6vi6/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

class Solution {
public:
	bool isNumber(char* s) {
		while (s != "\0") {
			if (s == ' ') {
				continue;
			}


		}
	}
};