/*文件名：E009.h
作者：Yzy
说明：判断一个整数是否是回文数
上次修改时间：2019/11/27 
*/
#pragma once
namespace E009 {
	class Solution {
	public:
		bool isPalindrome(int x) {
			if (x < 0)return false;
			string temp = to_string(x);
			int start = 0;
			int end = temp.size() - 1;
			while (start<end)
			{
				if (temp[start] != temp[end]) {
					return false;
				}
				start++;
				end--;
			}
			return true;
		}
	};

	void Test() {
		int v =232;
		Solution s;
		//s.myAtoi(v);
		cout << s.isPalindrome(v) << endl;
	}
}