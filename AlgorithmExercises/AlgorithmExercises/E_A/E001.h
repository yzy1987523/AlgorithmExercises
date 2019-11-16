/*�ļ�����E001.h 
���ߣ�YZY
˵��������һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� �������������������ǵ������±�()
�ϴ��޸�ʱ�䣺2019/11/16
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
			if (record.find(complement) != record.end()) {//��map����ֵ��ͬʱû��Խ��
				//int res[] = { i, record[complement] };//ǰ��Ϊ�±꣬����ҲΪ�±�
				//return vector<int>(res, res + 2);//����һ������Ϊ2����������������res��Ԫ��Ϊ������ֵ
				v.push_back(record[complement]);//��Ϊ�Ѿ���¼��ֵ������ǰ��
				v.push_back(i);
				break;
			}
			record[nums[i]] = i;//keyΪֵ��valueΪ�±�
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