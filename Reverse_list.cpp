

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

	int  listsize = 5;
	cout << "请输5个数字:" << endl;

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

///方法一：递归调用
class Solution {
public:
	ListNode * reverseList(ListNode* head) {
		///出口，选head作为单元改变接口
		if (!head || !(head->Next)) return head;//head不存在或则到达尾端返回，因为要把最后一个当新的头
		///达到末端，并保存node作新头
		ListNode* node = reverseList(head->Next); //返回5，并保存为node作为倒置后的新头
		///前后单元进行操作
		head->Next->Next = head;   //当上一句返回head时是5，则这里是4
		                           //迭代总结：迭代上下的自身调用的局部变量相差一个单元
		head->Next = NULL;
		///返回上一层单元
		return node;
	}
};

///方法二：插入法
///xWell, since the head pointer may also be modified,
///we create a new_head that points to it to facilitate the reverse process.

///it will become 0 -> 1 -> 2 -> 3 -> 4 -> 5 (we init new_head->val to be 0).
///Then we set a pointer pre to new_head and another cur to head.
///Then we keep inserting cur->next after pre until cur becomes the last node.The code is follows.
class Solution {
public:
	ListNode * reverseList(ListNode* head) {
		ListNode* new_head = new ListNode(0);
		new_head->next = head;
		ListNode* pre = new_head;
		ListNode* cur = head;   //012345
		while (cur && cur->next) {
			ListNode* temp = pre->next;
			pre->next = cur->next;  //0 -> 2
			cur->next = cur->next->next; //1 -> 3
			pre->next->next = temp;  //2 -> 1
		}
		return new_head->next;
	}
};

///方法三：动态标志移动切分
///1->2->3->4->5     第一步：1->NULL  2->3->4->5->NULL
///第二步： 2->1->NULL  3->4->5->NULL  
///...
class Solution {
public:
	ListNode * reverseList(ListNode* head) {
		ListNode* pre = NULL;
		while (head) {
			ListNode* next = head->next;
			head->next = pre;
			pre = head; //更新pre和head标志，都下移一位
			head = next;
		}
		return pre;
	}
};

int  main()
{

	ListNode* List1 = NULL;
	List1 = CreateList(List1);
	printList(List1);
	

	Solution x;
	ListNode* List3 = x.reverseList(List1);
	printList(List3);
}
