/*文件名：E013.h
作者：Yzy
说明：罗马数字转整数（取值为1-3999）
I=1
V=5
X=10
L=50
C=100
D=500
M=1000
放在左边表示减，放在右边表示加
19:XIX
上次修改时间：2019/11/27
*/
#pragma once
namespace E013 {
	class Solution {
	public:
		int romanToInt(string s) {
			map<char, int> romMap = {
				{'M',1000},
				//{'CM',900},
				{'D',500},
				//{'CD',400},
				{'C',100},
				//{'XC',90},
				{'L',50},
				//{'XL',40},
				{'X',10},
				//{'IX',9},
				{'V',5},
				//{'IV',4},
				{'I',1},
			};
			int res = romMap[s[0]];
			int size = s.size();
			for (int i = 1; i < size; i++) {
				if (romMap[s[i]] >= romMap[s[i - 1]]) {
					res += romMap[s[i]];
				}
				else
				{
					res -= (romMap[s[i]]);
				}
			}
			return  res;
		}
	};

	void Test() {
		string v = "IV";
		Solution s;
		cout << s.romanToInt(v) << endl;
	}
}