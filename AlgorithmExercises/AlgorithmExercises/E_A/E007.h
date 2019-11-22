/*文件名：E007.h
作者：YZY
说明：给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
上次修改时间：2019/11/22 
*/
#pragma once
namespace E007 {
//#include <iostream>
//	using namespace std;
	class Solution {
	public:
		int reverse(int x) {
			//思路：将除以10的余数作为上一位，乘以10，然后累加下一位
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