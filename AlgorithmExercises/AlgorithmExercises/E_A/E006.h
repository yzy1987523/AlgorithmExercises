/*文件名：E006.h
作者：YZY
说明：将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列：LEETCOD，输出LDEOECT
			L     D     
			E   O 
			E C   
			T     
上次修改时间：2019/11/22
*/
#pragma once
namespace E006 {
	//	#include <iostream>
	//#include <string>
	//#include <vector>
	using namespace std;
	class Solution {
	public:
		void showConvert(string s, int numRows) {
			if (numRows == 1)return;
			//思路：用二维数组装字符
			int x0 = s.size() / (2 * (numRows - 1));//将竖折作为一个单位，x0表示有多个完整的竖折
			int x1 = s.size() % (2 * (numRows - 1));//x1表示不完整的竖折含有多少字符
			int column = x0 * (1 + (numRows - 2));
			if (x1 <= numRows) {
				column += 1;
			}
			else
			{
				column += (x1 - column);
			}
			printf("column:%d\n", column);
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
					if (!v[j][i]) {//未赋值时值为'\0'
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

		string convert(string s, int numRows) {
			if (numRows == 1) return s;

			vector<string> rows(min(numRows, int(s.size()))); // 防止s的长度小于行数
			int curRow = 0;
			bool goingDown = false;

			for (char c : s) {
				rows[curRow] += c;//给每行添加字符
				if (curRow == 0 || curRow == numRows - 1) {// 当前行curRow为0或numRows -1时，箭头发生反向转折
					goingDown = !goingDown;
				}
				curRow += goingDown ? 1 : -1;
			}

			string ret;
			for (string row : rows) {// 从上到下遍历行
				ret += row;
			}

			return ret;
		}
	};

	void Test() {
		string v = "123456789ABCDEFGHIJKLMNOPQ";
		Solution s;
		int numRow = 2;
		s.showConvert(v, numRow);
		cout << s.convert(v, numRow) << endl;
	}
}