/*�ļ�����E013.h
���ߣ�Yzy
˵������������ת������ȡֵΪ1-3999��
I=1
V=5
X=10
L=50
C=100
D=500
M=1000
������߱�ʾ���������ұ߱�ʾ��
19:XIX
�ϴ��޸�ʱ�䣺2019/11/27
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