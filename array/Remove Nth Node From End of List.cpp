//移除倒数第n的数字
//思路：fast指针和slow指针时刻保持n间隔，fast到最后时slow到目标位置


ListNode *removeNthFromEnd(ListNode *head, int n) 
{
    if (!head)
        return nullptr;

    ListNode new_head(-1);
    new_head.next = head;

    ListNode *slow = &new_head, *fast = &new_head;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next) 
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *to_de_deleted = slow->next;
    slow->next = slow->next->next;
    
    delete to_be_deleted;

    return new_head.next;
}
