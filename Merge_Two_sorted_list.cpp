/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/



/////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///�����head��tailָ���־�������������м�ָ��temp
#include<iostream>
using namespace std;

typedef int elemtype;
typedef struct node
{
    elemtype Data;
    node* Next=NULL;
}ListNode;




///�����������β�巨����,����head����һ���ڵ�
ListNode* CreateList(ListNode* Head){
    Head= new ListNode;
    if (!Head)
    {
        cout << "�����ڴ�ռ�ʧ�ܣ�";
    }
    Head->Next = NULL;
    ListNode* Tail =Head;

    int  listsize = 5;
    cout << "����5������:" << endl;

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
///��ӡ����
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


///���������Ƚ���λ�����õ����������ǲ���Ԥ���ź����list
///C++
/*class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* Head;
    Head= new ListNode;
    if (!Head)
    {
        cout << "�����ڴ�ռ�ʧ�ܣ�";
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

///����һ��������ȱ����list����������stack�����
///�Ƚ�����list����Сֵ��������Ϊ��һ�����ٴε���,�����Ǳ�������õ�list
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

