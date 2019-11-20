/*文件名：E003.h
作者：Yzy
说明：给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
上次修改时间：2019/11/20
*/
#pragma once
namespace E003 {
#include <string>
#include <iostream>
#include <map>
	using namespace std;
	class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			if (s=="")return 0;
			//思路：两个游标，当右游标指向的字符与区间内某个字符相同时，左游标移至该字符右侧,

			vector<int>m(256, -1);//ASCii表最多256个字符，每种字符对应一个唯一asc码，向量的值表示字符在字符串中的编号

			int left = -1;
			int res = 0;
			int len = s.size();
			for (int i = 0; i < len; i++)
			{
				left = max(left, m[s[i]]);//如果左游标的值更小，则将左游标移至已记录的字符的位置
				m[s[i]] = i;//重新给对应字符赋值
				res = max(res, i - left);//滑动窗口的值为右游标减左游标，取其中最大值
			}
			return res;
		}
	};
	void Test() {		
		string v = "abcabcgjig";
		Solution s;
		auto result = s.lengthOfLongestSubstring(v);
		cout << result << endl;
	}
}