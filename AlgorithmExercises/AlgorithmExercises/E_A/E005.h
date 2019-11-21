/*�ļ�����E005.h
���ߣ�YZY
˵��������һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��
�ϴ��޸�ʱ�䣺2019/11/21
*/
#pragma once
namespace E005 {
//#include <iostream>
//#include <string>
//
//	using namespace std;
	class Solution {
	public:
		string longestPalindrome(string s) {
			int len = s.size();
			if (len <= 1)return s;
			int maxLength = 1;
			int start = 0;

			//˼·����̬�滮��
			vector<vector<bool>> dp(len, vector<bool>(len));//������������Ƿ���ĵ��жϣ���С�����¼���Ӵ�С�жϣ�����Χ����ʱ����Χ��ȻҲ���ģ�����������

			//l->r
			//l->l->r
			//l->l->l->r
			//l->l->l->l->r
			//l->l->l->l->l->r
			for (int r = 1; r < len; r++) {
				for (int l = 0; l < r; l++) {
					if (s[l] == s[r]&&(r - l <= 2 || dp[l + 1][r - 1])) {//�õ���·����������ߴ粻����2ʱ��ֻ��Ҫ�ж���β���У���������ʱ���ڲ���dp�ж������ˣ������ж�����β����
						dp[l][r] = true;
						if (maxLength < r - l+1) {
							maxLength = r - l+1;
							start = l;
						}
					}
				}
			}
			return s.substr(start, maxLength);//����Ĳ�����ʾȡ��λ��
		}
	};

	void Test() {
		string v="123222313124121";
		Solution s;
		auto result = s.longestPalindrome(v);
		cout << result << endl;
	}

}