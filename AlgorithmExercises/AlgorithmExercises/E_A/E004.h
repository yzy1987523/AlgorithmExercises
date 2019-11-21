/*文件名：E004.h
作者：Yzy
说明：给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
上次修改时间：2019/11/21
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

#pragma region 优秀算法
#ifdef 优秀算法



			int n = nums1.size();
			int m = nums2.size();

			if (n > m)  //保证数组1一定最短
			{
				return findMedianSortedArrays(nums2, nums1);
			}
			//Max是左侧的最大值,Min是右侧的最小值
			int  Max1, Min1, Max2, Min2, c1, c2, start = 0, end = n;

			while (start <= end)
			{
				c1 = (start + end) / 2;  //二分
				c2 = (m + n + 1) / 2 - c1;//原理：i+j=(m+n+1)/2；需要满足i左侧的值都小于等于j，

				Max1 = (c1 == 0) ? INT_MIN : nums1[c1 - 1];//不断选取左侧的一半，直到中值为0，判断出数组1整体在右侧
				Min1 = (c1 == n) ? INT_MAX : nums1[c1];//判断数组1整体在左侧
				Max2 = (c2 == 0) ? INT_MIN : nums2[c2 - 1];
				Min2 = (c2 == m) ? INT_MAX : nums2[c2];

				if (Max1 > Min2)
					end = c1 - 1;//取左侧的一半
				else if (Min1 < Max2)
					start = c1 + 1;//取右侧的一半
				else
					break;
			}
			if ((m + n) % 2 == 0) {
				return (max(Max1, Max2) + min(Min1, Min2)) / 2.0;
			}
			else
			{
				return (max(Max1, Max2));
			}
#endif // 优秀算法
#pragma endregion
#pragma region 复写



			int n = nums1.size();
			int m= nums2.size();
			if (n > m)return findMedianSortedArrays(nums2,nums1);
			int l1, r1, l2, r2, c1, c2, start=0, end = n;
			while (start<=end)
			{
				c1 = (start + end) / 2;
				c2 = (m + n + 1) / 2 - c1;

				l1 = (c1 == 0 ? INT_MIN : nums1[c1 - 1]);//未分清
				r1 = (c1 == n ? INT_MAX : nums1[c1]);
				l2 = (c2 == 0 ? INT_MIN : nums2[c2 - 1]);
				r2 = (c2 == m ? INT_MAX : nums2[c2]);
				if (r1 < l2) {
					start = c1 + 1;
				}
				else if(l1>r2)
				{
					end = c1 - 1;
				}
				else
					break;//忘记写

			}
			if ((m + n) % 2 == 0) {
				return (max(l1, l2) + min(r1, r2)) / 2.0;//未完全理解
			}
			else
			{
				return max(l1, l2);
			}
#pragma endregion
			
		}
	};
	void Test() {
		vector<int>nums1 = {2,4};
		vector<int>nums2 = {1,3};
		Solution s;
		auto result = s.findMedianSortedArrays(nums1,nums2);
		cout << result << endl;
	}
}