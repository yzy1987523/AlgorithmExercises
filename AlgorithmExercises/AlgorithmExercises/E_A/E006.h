/*文件名：E006.h
作者：YZY
说明：将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列："LDREOEIIECIHNTSG"
			L     D     R
			E   O E   I I
			E C   I H   N
			T     S     G
上次修改时间：2019/11/21
*/
#pragma once
namespace E006 {
	//	#include <iostream>
	//#include <string>
	//#include <vector>
	using namespace std;
	class Solution {
	public:
		void convert(string s, int numRows) {
			//思路：用二维数组装字符
			int column =s.size()/ numRows+1;//???????????
			int last = 0;//触底时的编号
			int count = 0;//斜线的条数
			vector<vector<char>> v(numRows, vector<char>(column));
			bool vertical = true;//首次以直线记录，触底后变斜线，再次触底变直线;直线总是往下，斜线总是往上
			for (int i = 0; i < s.size(); i++) {
		
				if (vertical) {
					int x = i - last;
					int y = (numRows - 1)*count;
					v[x][y] = s[i];
					//printf("%d,%d\n", x, y);
				}
				else
				{
					int x = (numRows - 1) - (i - last);
					int y = (i - last) + (count)*(numRows - 1);
					v[x][y] = s[i];
					//printf("%d,%d\n",x,y);
				}
				if ((i - last + 1) % numRows == 0) {
					//触底转折
					vertical = !vertical;
					last = i;
					if (vertical)count++;//绘制完一条斜线
				}
			}
			for (int j = 0; j < numRows; j++) {
				for (int i = 0; i < column; i++) {
					if (!v[j][i]) {
						cout << " ";
					}
					else
					{
						cout << v[j][i];
					}
				}
				cout << endl;
			}


		}
	};

	void Test() {
		string v = "123456789ABCDEFGHIJK";
		Solution s;
		s.convert(v, 4);

	}
}