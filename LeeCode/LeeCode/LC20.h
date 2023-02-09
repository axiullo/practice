#pragma once
/**
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
数值（按顺序）可以分成以下几个部分：
	若干空格
	一个 小数 或者 整数
	（可选）一个 'e' 或 'E' ，后面跟着一个 整数
	若干空格

小数（按顺序）可以分成以下几个部分：
	（可选）一个符号字符（'+' 或 '-'）
	下述格式之一：
		至少一位数字，后面跟着一个点 '.'
		至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
		一个点 '.' ，后面跟着至少一位数字

整数（按顺序）可以分成以下几个部分：
	（可选）一个符号字符（'+' 或 '-'）
	至少一位数字

部分数值列举如下：
	["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]

部分非数值列举如下：
	["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]

示例 1：
输入：s = "0"
输出：true

示例 2：
输入：s = "e"
输出：false

示例 3：
输入：s = "."
输出：false

示例 4：
输入：s = "    .1  "
输出：true

提示：
	1 <= s.length <= 20
	s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，空格 ' ' 或者点 '.' 。

作者：Krahets
链接：https://leetcode.cn/leetbook/read/illustration-of-algorithm/5d6vi6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

解题思路:
有限状态机
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
		S0, //初始态
		S1,
		S2,
		S3,
		S4,
		S5,
		S6,
		S7,
		S8,
		S9,
		SE //错误状态
	};

	unordered_set<State> validStates{S2, S4, S6, S7, S8};

	//字符对应一个符号标识
	unordered_map<char, int> mapChar2Sign
	{
		{' ', 0},
		{'+', 1}, {'-',1},
		{'0',2},{'1',2},{'2',2},{'3',2},{'4',2},{'5',2},{'6',2},{'7',2},{'8',2},{'9',2},
		{'e',3},{'E',3},
		{'.', 4}
	};

	//本状态下, 输入的符号标识转到下一个状态
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