/*�ļ�����E003.h
���ߣ�Yzy
˵��������һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
�ϴ��޸�ʱ�䣺2019/11/20
*/
#pragma once
namespace E003 {
#include <string>
#include <iostream>
#include <map>
	using namespace std;
	class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			if (s=="")return 0;
			//˼·�������α꣬�����α�ָ����ַ���������ĳ���ַ���ͬʱ�����α��������ַ��Ҳ�,

			vector<int>m(256, -1);//ASCii�����256���ַ���ÿ���ַ���Ӧһ��Ψһasc�룬������ֵ��ʾ�ַ����ַ����еı��

			int left = -1;
			int res = 0;
			int len = s.size();
			for (int i = 0; i < len; i++)
			{
				left = max(left, m[s[i]]);//������α��ֵ��С�������α������Ѽ�¼���ַ���λ��
				m[s[i]] = i;//���¸���Ӧ�ַ���ֵ
				res = max(res, i - left);//�������ڵ�ֵΪ���α�����α꣬ȡ�������ֵ
			}
			return res;
		}
	};
	void Test() {		
		string v = "abcabcgjig";
		Solution s;
		auto result = s.lengthOfLongestSubstring(v);
		cout << result << endl;
	}
}