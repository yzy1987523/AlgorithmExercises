/*文件名：E010.h
作者：Yzy
说明：给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
上次修改时间：2019/11/27
*/
#pragma once
namespace E010 {
	class Solution {
	public:
		bool isMatch(string s, string p) {			
			if (p.empty())return s.empty();
			if (p[1] == '*') {
				return (!s.empty()
					&&(p[0]==s[0]||p[0]=='.')
					&& isMatch(s.substr(1),p))//首位相同时从次位开始匹配
					||
					isMatch(s, p.substr(2)) ;//跳过*号开始匹配
			}
			else
			{
				return !s.empty()
					&&(s[0] == p[0]||p[0]=='.')
					&&isMatch(s.substr(1),p.substr(1));////首位相同时从次位开始匹配
			}
		}
	};

	void Test() {
		string a = "aba";
		string b = "a*..";
		Solution s;
		cout << s.isMatch(a, b) << endl;
	}
}