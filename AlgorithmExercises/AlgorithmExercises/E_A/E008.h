/*�ļ�����E008.h
���ߣ�YZY
˵�������ַ���ת��������
�ϴ��޸�ʱ�䣺2019/11/27
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
			str.erase(0, str.find_first_not_of(" "));//�޳��ո�
			if (regex_search(str, match, reg)) {				
				stringstream ss;
				ss << match[0];//������ע��
				long res;
				ss >> res;//���������
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
