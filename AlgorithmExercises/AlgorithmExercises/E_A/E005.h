/*文件名：E005.h
作者：YZY
说明：给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
上次修改时间：2019/11/21
*/
#pragma once
namespace E005 {
//#include <iostream>
//#include <string>
//
//	using namespace std;
	class Solution {
	public:
		string longestPalindrome(string s) {
			int len = s.size();
			if (len <= 1)return s;
			int maxLength = 1;
			int start = 0;

			//思路：动态规划法
			vector<vector<bool>> dp(len, vector<bool>(len));//用来存放区间是否回文的判断，从小到大记录，从大到小判断，当外围回文时，内围必然也回文，才满足条件

			//l->r
			//l->l->r
			//l->l->l->r
			//l->l->l->l->r
			//l->l->l->l->l->r
			for (int r = 1; r < len; r++) {
				for (int l = 0; l < r; l++) {
					if (s[l] == s[r]&&(r - l <= 2 || dp[l + 1][r - 1])) {//用到短路法，当区间尺寸不大于2时，只需要判断首尾就行；当区间变大时，内部的dp判断已有了，额外判断下首尾就行
						dp[l][r] = true;
						if (maxLength < r - l+1) {
							maxLength = r - l+1;
							start = l;
						}
					}
				}
			}
			return s.substr(start, maxLength);//后面的参数表示取几位，
		}
	};

	void Test() {
		string v="123222313124121";
		Solution s;
		auto result = s.longestPalindrome(v);
		cout << result << endl;
	}

}