/*文件名：E012.h
作者：Yzy
说明：整数转罗马数字（取值为1-3999）
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
namespace E012{
	class Solution {
	public:
		string intToRoman(int num) {
			string res;
			vector<int> in = {1000,900,500,400,100,90,50,40,10,9,5,4,1};//关键是写出这个
			vector<string> rom = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
			int index = 0;
			int size = in.size();
			while (index< size)
			{
				while (num>=in[index])
				{
					res.append(rom[index]);
					num -= in[index];
				}
				index++;
			}
			return res;
		}
	};

	void Test() {
		int v = 19;
		Solution s;
		cout << s.intToRoman(v) << endl;
	}
}