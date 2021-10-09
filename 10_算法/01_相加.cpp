/**
 * https://leetcode-cn.com/problems/add-two-numbers/
 * 
 * 有两个列表:
 * 		1->2->4
 * 		3->8->2
 * 	相加后:4->0->7
 */
#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *head = nullptr;
		ListNode *curr = nullptr;
		int last = 0; //进位
		while (l1 != nullptr or l2 != nullptr)
		{
			ListNode *n = new ListNode(0);
			if (l1 != nullptr)
			{
				n->val = l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				n->val += l2->val;
				l2 = l2->next;
			}
			n->val += last;
			
			last = n->val / 10;
			n->val = n->val % 10;

			if (head == nullptr)
				head = n;

			//新节点加入链表
			if (curr == nullptr)
			{
				curr = n;
			}
			else
			{
				curr->next = n;
				curr = n;
			}
		}

		if (last > 0)
		{
			curr->next = new ListNode(last);
		}
		return head;
	}
};

int main(int arg, char *argv[])
{
	cout << 10 / 10 << endl;
	cout << 18 % 10 << endl;
	cout << "----" << endl;

	ListNode *l1 = new ListNode(9);
	ListNode *l2 = new ListNode(9);
	ListNode *l3 = new ListNode(9);
	ListNode *l4 = new ListNode(9);
	ListNode *l5 = new ListNode(9);
	ListNode *l6 = new ListNode(9);
	ListNode *l7 = new ListNode(9);

	ListNode *la = new ListNode(9);
	ListNode *lb = new ListNode(9);
	ListNode *lc = new ListNode(9);
	ListNode *ld = new ListNode(9);

	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	

	la->next = lb;
	lb->next = lc;
	lc->next = ld;
	

	Solution *p_s = new Solution();

	ListNode *head = p_s->addTwoNumbers(l1, la);
	while (head != nullptr)
	{
		printf("%d\n", head->val);
		head = head->next;
	}
	return 0;
}
