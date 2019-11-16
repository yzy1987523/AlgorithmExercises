/*文件名：E001.h 
作者：YZY
说明：给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个整数，并返回他们的数组下标()
上次修改时间：2019/11/16
*/
#pragma once

namespace E001 {
//#include <map>
//#include <vector>
//#include <iostream>
	using namespace std;
	
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> record;
		vector<int> v;
		for (int i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			if (record.find(complement) != record.end()) {//在map中有值的同时没有越界
				//int res[] = { i, record[complement] };//前者为下标，后者也为下标
				//return vector<int>(res, res + 2);//声明一个长度为2的向量，并用数组res的元素为向量赋值
				v.push_back(record[complement]);//因为已经记录的值总是在前面
				v.push_back(i);
				break;
			}
			record[nums[i]] = i;//key为值，value为下标
		}		
		return v;
	}
	void E001Test()
	{
		vector<int>nums;
		int step = 0;
		while (step<10)
		{
			nums.push_back(step);
			step++;
		}
		int target = 8;
		auto result = twoSum(nums, target);
		if(result.size()>=2)		
			cout<< result.at(0)<<","<< result.at(1) <<endl;
		else
			cout<<"null"<<endl;
	
	}
}