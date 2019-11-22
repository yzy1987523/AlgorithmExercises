/*�ļ�����E007.h
���ߣ�YZY
˵��������һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��
�ϴ��޸�ʱ�䣺2019/11/22 
*/
#pragma once
namespace E007 {
//#include <iostream>
//	using namespace std;
	class Solution {
	public:
		int reverse(int x) {
			//˼·��������10��������Ϊ��һλ������10��Ȼ���ۼ���һλ
			long temp = 0;

			while (x != 0) {
				int pop = x % 10;
				temp = temp * 10 + pop;

				if (temp > INT_MAX || temp < INT_MIN) {
					return 0;
				}
				x /= 10;
			}
			return (int)temp;
		}
	};
	void Test() {
		int v=-234;
		Solution s;
		auto result = s.reverse(v);
		cout << result << endl;
	}
}