Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

#include "stdafx.h"
#include<iostream>
using namespace std;

typedef int elemtype;
typedef struct node
{
	elemtype Data;
	node* Next = NULL;
}ListNode;




///创建链表二：尾插法创建,返回head的下一个节点
ListNode* CreateList(ListNode* Head) {
	Head = new ListNode;
	if (!Head)
	{
		cout << "分配内存空间失败！";
	}
	Head->Next = NULL;
	ListNode* Tail = Head;

	int  listsize = 6;
	cout << "请输6个数字:" << endl;

	for (int i = listsize; i >0; i--)
	{
		ListNode* NewNode = new ListNode;
		cin >> NewNode->Data;
		Tail->Next = NewNode;
		Tail = NewNode;
		NewNode->Next = NULL;
	}
	return Head->Next;
}
///打印链表
void printList(ListNode* list) {
	ListNode* Temp = list;
	while (Temp)
	{
		cout << Temp->Data << "\t";
		Temp = Temp->Next;

	}
	cout << endl;
}



class Solution
{
public:
	bool IsPalindrome(ListNode * head) ///思路：前后一半对比是否相等
	{
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->Next&&fast->Next->Next)
		{
			slow = slow->Next;
			fast = fast->Next->Next;

		}

		slow->Next = Reverse_list(slow->Next);
		slow = slow->Next;
		while (slow)
		{
			if (head->Data != slow->Data)
			{
				return false;
			}
			else
			{
				slow = slow->Next;
				head = head->Next;
			}
		}
		return true;

	}

	ListNode* Reverse_list(ListNode* head)  ///标志逆序法
	{
		ListNode* pre = NULL;
		ListNode* next = NULL;
		while (head)
		{
			next = head->Next;
			head->Next = pre;
			pre = head;
			head = next;
		}
		return pre;

	}
};

int main()
{
	ListNode* List1 = NULL;
	List1 = CreateList(List1);
	printList(List1);

	Solution x;
	cout << x.IsPalindrome(List1) << endl;

}
