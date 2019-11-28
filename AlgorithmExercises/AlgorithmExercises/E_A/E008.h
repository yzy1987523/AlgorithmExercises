/*文件名：E008.h
作者：YZY
说明：将字符串转换成整数
上次修改时间：2019/11/27
*/
#pragma once
namespace E008 {
	//#include <iostream>
//#include <boost/lexical_cast.hpp> 
//#include <boost/lexical_cast.hpp>   
//#include <regex>
//		using namespace std;

	class Solution {
	public:
		int myAtoi(string str) {
			using boost::regex;
			using boost::smatch;			
			regex reg("^[-+]?\\d+");
			smatch match;
			str.erase(0, str.find_first_not_of(" "));//剔除空格
			if (regex_search(str, match, reg)) {				
				stringstream ss;
				ss << match[0];//将数据注入
				long res;
				ss >> res;//将数据输出
				return max(min(res, long(INT_MAX)), long(INT_MIN));
			}
			else {
				return 0;
			}
			
		}
			
		
	};

	void Test() {
		string v = "   +123";
		Solution s;
		//s.myAtoi(v);
		cout <<s.myAtoi(v)<<endl;
	}
	
}
