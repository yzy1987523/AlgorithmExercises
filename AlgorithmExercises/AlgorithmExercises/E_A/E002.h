/*文件名：E002.h
作者：Yzy
说明：给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
上次修改时间：2019/11/20
*/
#pragma once
namespace E002 {
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(nullptr) {}
	};

	class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//#define 朴实无华的方案
#ifdef 朴实无华的方案
			int len1 = 1;//记录l1的长度
			int len2 = 1;//记录l2的长度
			ListNode* p = l1;
			ListNode* q = l2;
			while (p->next != NULL)//获取l1的长度
			{
				len1++;
				p = p->next;
			}
			while (q->next != NULL)//获取l2的长度
			{
				len2++;
				q = q->next;
			}
			if (len1 > len2)//l1较长，在l2末尾补零
			{
				for (int i = 1; i <= len1 - len2; i++)
				{
					q->next = new ListNode(0);
					q = q->next;
				}
			}
			else//l2较长，在l1末尾补零
			{
				for (int i = 1; i <= len2 - len1; i++)
				{
					p->next = new ListNode(0);
					p = p->next;
				}
			}
			p = l1;
			q = l2;
			bool count = false;//记录进位
			ListNode* l3 = new ListNode(-1);//存放结果的链表
			ListNode* w = l3;//l3的移动指针
			int i = 0;//记录相加结果
			while (p != NULL && q != NULL)
			{
				i = count + p->val + q->val;
				w->next = new ListNode(i % 10);
				count = i >= 10 ? true : false;
				w = w->next;
				p = p->next;
				q = q->next;
			}
			if (count)//若最后还有进位
			{
				w->next = new ListNode(1);
				w = w->next;
			}
			return l3->next;
#endif // 朴实无华的方案

#ifndef 朴实无华的方案
			ListNode* head = new ListNode(0);
			ListNode*h = head;//游标指针
			int sum = 0;
			int carry = 0;
			while (l1!=nullptr||l2!=nullptr)
			{
				sum = 0;
				if (l1 != nullptr) {
					sum += l1->val;
					l1 = l1->next;
				}
				if (l2 != nullptr) {
					sum += l2->val;
					l2 = l2->next;
				}
				sum += carry;
				h->next = new ListNode(sum % 10);//将值放入下一位，因为如果放在首位，那么会出现多出一位的情况
				h = h->next;
				carry = sum>=10?1:0;
			}
			if (carry > 0) {
				h->next=new ListNode(1);
			}
			return head->next;//最终返回的是排除掉首位的链表
#endif			
		}
	};
	void Test() {
		ListNode*l1_1 = new ListNode(1);
		ListNode*l1_2 = new ListNode(2);
		ListNode*l1_3 = new ListNode(2);

		ListNode*l2_1 = new ListNode(5);
		ListNode*l2_2 = new ListNode(7);
		ListNode*l2_3 = new ListNode(9);
		
		l1_1->next = l1_2;
		l1_2->next = l1_3;
		l2_1->next = l2_2;
		l2_2->next = l2_3;

		Solution s;
		auto list = s.addTwoNumbers(l1_1, l2_1);
		while (list != nullptr) {
			cout << list->val << endl;
			list = list->next;
		}
		


	}
}