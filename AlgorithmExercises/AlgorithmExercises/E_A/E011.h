/*文件名：E011.h
作者：Yzy
说明：盛最多水的容器:
上次修改时间：2019/11/27
*/
#pragma once
namespace E011 {
	class Solution {
	public:
		int maxArea(vector<int>& height) {
			int maxA = 0;
			//for (int i = 0; i < height.size()-1; i++) {//该方法超时
			//	for (int j = i+1; j < height.size(); j++)
			//		maxA = max(min(height[i], height[j])*(j - i), maxA);
			//}
			int l = 0;
			int r = height.size() - 1;
			
			while (r > l)
			{
				maxA = max(min(height[r], height[l])*(r - l), maxA);
				if (height[l] > height[r]) {//只需要算一边，因为往里缩时，当底面长度不变时，取更高的
					r--;
				}
				else {
					l++;
				}
			}
			return maxA;
		}
	};

	void Test() {
		vector<int> v = { 1,8,6,2,5,4,4,8,3,7 };
		Solution s;
		cout << s.maxArea(v) << endl;
	}
}