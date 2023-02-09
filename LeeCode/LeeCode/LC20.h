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

����˼·:
����״̬��
*/

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	enum State
	{
		S0, //��ʼ̬
		S1,
		S2,
		S3,
		S4,
		S5,
		S6,
		S7,
		S8,
		S9,
		SE //����״̬
	};

	unordered_set<State> validStates{S2, S4, S6, S7, S8};

	//�ַ���Ӧһ�����ű�ʶ
	unordered_map<char, int> mapChar2Sign
	{
		{' ', 0},
		{'+', 1}, {'-',1},
		{'0',2},{'1',2},{'2',2},{'3',2},{'4',2},{'5',2},{'6',2},{'7',2},{'8',2},{'9',2},
		{'e',3},{'E',3},
		{'.', 4}
	};

	//��״̬��, ����ķ��ű�ʶת����һ��״̬
	unordered_map<State, unordered_map<int, State>> mapStates
	{
		{S0, {{0, S0}, {1, S1}, {2, S2},{4, S3}}},
		{S1, {{4, S3}, {2, S2}}},
		{S2, {{2, S2},{4, S4},{0, S7},{3, S5}}},
		{S3, {{2, S6},}},
		{S4, {{2, S6},{0, S7},{3, S5}}},
		{S5, {{2, S8}, {1, S9}}},
		{S6, {{2, S6}, {3, S5},{0, S7}}},
		{S7, {{0, S7}}},
		{S8, {{2, S8},{0, S7}}},
		{S9, {{2, S8}}},
	};
	 
	bool isNumber(string s) {
		if (s.length() == 0)
		{
			return false;
		}

		State curState = S0;
		int index = 0;
		char c = s[index];

		while (c != '\0') {
			unordered_map<State, unordered_map<int, State>>::iterator curInput = mapStates.find(curState);

			if (curInput == mapStates.end()) {
				return false;
			}

			unordered_map<char, int>::iterator iterSign = mapChar2Sign.find(c);

			if (iterSign == mapChar2Sign.end()) {
				return false;
			}

			unordered_map<int, State>::iterator iterSign2State = curInput->second.find(iterSign->second);

			if (iterSign2State == curInput->second.end()) {
				return false;
			}

			curState = iterSign2State->second;
			c = s[++index];
		}

		if (validStates.find(curState) != validStates.end()) {
			return true;
		}

		return false;
	}

	void test()
	{
		string str = "12.";
		bool result = isNumber(str);
		cout << result << endl;
	}
};