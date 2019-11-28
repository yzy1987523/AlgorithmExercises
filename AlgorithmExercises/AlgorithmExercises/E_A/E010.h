/*�ļ�����E010.h
���ߣ�Yzy
˵��������һ���ַ��� s ��һ���ַ����� p��������ʵ��һ��֧�� '.' �� '*' ��������ʽƥ�䡣
�ϴ��޸�ʱ�䣺2019/11/27
*/
#pragma once
namespace E010 {
	class Solution {
	public:
		bool isMatch(string s, string p) {			
			if (p.empty())return s.empty();
			if (p[1] == '*') {
				return (!s.empty()
					&&(p[0]==s[0]||p[0]=='.')
					&& isMatch(s.substr(1),p))//��λ��ͬʱ�Ӵ�λ��ʼƥ��
					||
					isMatch(s, p.substr(2)) ;//����*�ſ�ʼƥ��
			}
			else
			{
				return !s.empty()
					&&(s[0] == p[0]||p[0]=='.')
					&&isMatch(s.substr(1),p.substr(1));////��λ��ͬʱ�Ӵ�λ��ʼƥ��
			}
		}
	};

	void Test() {
		string a = "aba";
		string b = "a*..";
		Solution s;
		cout << s.isMatch(a, b) << endl;
	}
}