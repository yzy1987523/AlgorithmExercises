/*文件名：E002.h
作者：Yzy
说明：给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
上次修改时间：2019/11/19
*/
#pragma once
namespace E002 {
//#include <stdlib.h>	
//#include<algorithm>
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			int *p=(int*)malloc(2);
		}
	};
	void Test() {
		vector<double> numbers{ 2.5,  3.5, 6.5, 8.0, 12.0, 1.5, 6.0,10.0 };//声明一个向量容器
		make_heap(numbers.begin(), numbers.end(), less<int>());//构建堆结构(less为最大堆，greater为最小堆，不写则默认为最大堆)
		for (int i = 0; i < numbers.size(); i++)cout << numbers[i] << endl;
		// Result: 12 10 3.5 6.5 8 2.5 1.5 6
		cout << "==============" << endl;

		numbers.push_back(11);
		for (int i = 0; i < numbers.size(); i++)cout << numbers[i] << endl;
		// Result: 12 10 3.5 6.5 8 2.5 1.5 6 11
		cout << "==============" << endl;

		push_heap(begin(numbers), end(numbers));//对向量容器进行堆操作，让其满足堆的结构
		for (int i = 0; i < numbers.size(); i++)cout << numbers[i] << endl;
		// Result: 12 11 3. 5 10 8 2. 5 1. 5 6 6. 5
		cout << "==============" << endl;

		pop_heap(numbers.begin(), numbers.end());//将顶移到最后一位
		for (int i = 0; i < numbers.size(); i++)cout << numbers[i] << endl;
		// Result:11 10 8 3.5 6.5 6 2.5 1.5 12
		cout << "==============" << endl;

		numbers.pop_back();//将最后一位移除
		for (int i = 0; i < numbers.size(); i++)cout << numbers[i] << endl;
		// Result:11 10 8 3.5 6.5 6 2.5 1.5
	}
}