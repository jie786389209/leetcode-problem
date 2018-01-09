/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/



/////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///链表的head和tail指针标志不动，遍历用中间指针temp
#include<iostream>
using namespace std;

typedef int elemtype;
typedef struct node
{
    elemtype Data;
    node* Next=NULL;
}ListNode;




///创建链表二：尾插法创建,返回head的下一个节点
ListNode* CreateList(ListNode* Head){
    Head= new ListNode;
    if (!Head)
    {
        cout << "分配内存空间失败！";
    }
    Head->Next = NULL;
    ListNode* Tail =Head;

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
    return Head;
}
///打印链表
void printList(ListNode* list){
    ListNode* Temp=list;
    while (Temp)
    {
        cout << Temp->Data << "\t";
        Temp = Temp->Next;

    }
    cout << endl;
}

class Solution{
public:
    ListNode* DeLeteNode(int x,ListNode* list)
    {
        ListNode* temp1=list;
        ListNode* temp2;
        while(temp1->Next)
        {
            if(temp1->Next->Data==x)
            {
                temp2=temp1->Next;
                temp1->Next=temp1->Next->Next;
                delete(temp2);
            }

            temp1=temp1->Next;
        }
        return list->Next;
    }
};


///方法二，比较移位，不用迭代，条件是不用预先排好序的list
///C++
/*class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* Head;
    Head= new ListNode;
    if (!Head)
    {
        cout << "分配内存空间失败！";
    }
    Head->Next = NULL;
    ListNode* Tail =Head;

        while (l1 && l2) {
            if (l1->Data < l2->Data) {
                Tail->Next = l1;
                l1 = l1->Next;
            } else {
                Tail->Next = l2;
                l2 = l2->Next;
            }
            Tail = Tail->Next;
        }

        Tail->Next = l1 ? l1 : l2;
        return Head->Next;
    }
};

*/

///方法一：迭代（缺点是list过长会引起stack溢出）
///比较两个list，较小值保留并以为下一个，再次迭代,条件是必须排序好的list
///Java
/*class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->Data < l2->Data) {
            l1->Next = mergeTwoLists(l1->Next, l2);
            return l1;
        } else {
            l2->Next = mergeTwoLists(l2->Next, l1);
            return l2;
        }
    }
};
*/


int  main()
{

    ListNode* List1 = NULL;
    List1 = CreateList(List1);
    printList(List1->Next);

    Solution x;
    List1 = x.DeLeteNode(3,List1);
    printList(List1);
  /*  ListNode* List2 = NULL;
    List2 = CreateList(List2);
    printList(List2);

    Solution x;
    ListNode* List3 = x.mergeTwoLists(List1,List2);
    printList(List3);
    */
}

