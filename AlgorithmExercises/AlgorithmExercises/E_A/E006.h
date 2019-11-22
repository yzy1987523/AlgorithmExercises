/*�ļ�����E006.h
���ߣ�YZY
˵������һ�������ַ������ݸ������������Դ������¡������ҽ��� Z �������У�LEETCOD�����LDEOECT
			L     D     
			E   O 
			E C   
			T     
�ϴ��޸�ʱ�䣺2019/11/22
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
			//˼·���ö�ά����װ�ַ�
			int x0 = s.size() / (2 * (numRows - 1));//��������Ϊһ����λ��x0��ʾ�ж������������
			int x1 = s.size() % (2 * (numRows - 1));//x1��ʾ�����������ۺ��ж����ַ�
			int column = x0 * (1 + (numRows - 2));
			if (x1 <= numRows) {
				column += 1;
			}
			else
			{
				column += (x1 - column);
			}
			printf("column:%d\n", column);
			int last = 0;//����ʱ�ı��
			int count = 0;//б�ߵ�����
			vector<vector<char>> v(numRows, vector<char>(column));
			bool vertical = true;//�״���ֱ�߼�¼�����׺��б�ߣ��ٴδ��ױ�ֱ��;ֱ���������£�б����������
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
					//����ת��
					vertical = !vertical;
					last = i;
					if (vertical)count++;//������һ��б��
				}
			}
			for (int j = 0; j < numRows; j++) {
				for (int i = 0; i < column; i++) {
					if (!v[j][i]) {//δ��ֵʱֵΪ'\0'
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

			vector<string> rows(min(numRows, int(s.size()))); // ��ֹs�ĳ���С������
			int curRow = 0;
			bool goingDown = false;

			for (char c : s) {
				rows[curRow] += c;//��ÿ������ַ�
				if (curRow == 0 || curRow == numRows - 1) {// ��ǰ��curRowΪ0��numRows -1ʱ����ͷ��������ת��
					goingDown = !goingDown;
				}
				curRow += goingDown ? 1 : -1;
			}

			string ret;
			for (string row : rows) {// ���ϵ��±�����
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