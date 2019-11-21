/*�ļ�����E006.h
���ߣ�YZY
˵������һ�������ַ������ݸ������������Դ������¡������ҽ��� Z �������У�"LDREOEIIECIHNTSG"
			L     D     R
			E   O E   I I
			E C   I H   N
			T     S     G
�ϴ��޸�ʱ�䣺2019/11/21
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
			//˼·���ö�ά����װ�ַ�
			int column =s.size()/ numRows+1;//???????????
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