
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* before = nullptr;
        ListNode* cur = head;
        
        while (cur != nullptr)
        {
            ListNode* after = cur->next;
            cur->next = before;
            before = cur;
            cur = after;
        }
        return before;
    }
};
