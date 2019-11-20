/*文件名：E004.h
作者：Yzy
说明：给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
上次修改时间：2019/11/20
*/
#pragma once
namespace E004 {
//#include <vector>
//#include <iostream>
//	using namespace std;
	class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {	
#pragma region 错误的写法：复杂度需要加上sort的时间；未处理nums长度小于2的情况
			//vector<int> nums;
			//vector<int>::iterator it;
			//for (it = nums1.begin(); it != nums1.end(); it++) {
			//	nums.push_back(*it);
			//}
			//for (it = nums2.begin(); it != nums2.end(); it++) {
			//	nums.push_back(*it);
			//}
			//sort(nums.begin(), nums.end());
			//int mid = nums.size() / 2;
			//return mid == 1 ? nums[mid] : (double)(nums[mid - 1] + nums[mid]) / 2;
#pragma endregion

			int n = nums1.size();
			int m = nums2.size();

			if (n > m)  //保证数组1一定最短
			{
				return findMedianSortedArrays(nums2, nums1);
			}

			// Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
			int LMax1, LMax2, RMin1, RMin2, c1, c2, start = 0, end = n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

			while (start <= end)   //二分
			{
				c1 = (start + end) / 2;  //c1是二分的结果
				c2 = (m + n+1)/2 - c1;//原理：i+j=(m+n+1)/2 ；需要满足i左侧的值都小于等于j，

				LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
				RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
				LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
				RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

				if (LMax1 > RMin2)
					end = c1 - 1;
				else if (LMax2 > RMin1)
					start = c1 + 1;
				else
					break;
			}
			return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
		}
	};
	void Test() {
		vector<int>nums1;
		vector<int>nums2 = {1,2,3};
		Solution s;
		auto result = s.findMedianSortedArrays(nums1,nums2);
		cout << result << endl;
	}
}